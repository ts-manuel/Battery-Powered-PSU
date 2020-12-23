/* 
 * File:    main.c
 * Author:  Manuel
 * Date:    26/06/2020
 * Device:  PIC16LF18346
 * Rev:     1.2 2020
 * 
 * Firmware for the Battery Board
 * 
 * TMR0:
 *      1 millisecond tick
 *      interrupt every 60 seconds
 *      used by the time library
 * 
 * TMR3:
 *      1 second Interrupt
 *      to wake up the microcontroller every second during sleep
 * 
 * WATCHDOG:
 *      enabled with 2 second period
 */

#include <mcc.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include "leds.h"
#include "time.h"
#include "bms.h"
#include "chg.h"
#include "i2cMaster.h"
#include "i2cSlave.h"
#include "types.h"

#pragma warning disable 520     //Function is never called
#pragma warning disable 2053    //Function is never called
#pragma warning disable 1510    //Function appears in multiple call graphs and has been dupplicated

#define _LOG_DATA       true
#define _LOG_RAW        true
#define _LOG_INTERVALL  (5*60)  //Interval between log points in seconds


//Global variables
static volatile bool runUpdateLogic = true;    //Flag set by the interrupt routine every second
static volatile bool extBtnPressed = false;    //Flag set when the external button is pressed
static state_t state = e_STATE_INIT;

//Interrupt service routines
void ISR_Interrupt_1Sec(void);
void ISR_ExtBtn(void);
void ISR_PSU_On(void);
void ISR_ExternalPower(void);

//Static functions
static void LogData(void);


void main(void){
    
    //Initialize device
    SYSTEM_Initialize();
    TIME_Initialize();
    LEDS_Initialize();
    
    //Set interrupt handler functions
    TMR0_SetInterruptHandler(TIME_ISR_Timer);           //60 sec Interrupt
    TMR3_SetInterruptHandler(ISR_Interrupt_1Sec);       //1s interrupt
    INT_SetInterruptHandler(ISR_ExtBtn);                //External button interrupt
    IOCBF6_SetInterruptHandler(BMS_AlertISR);           //Alert PIN interrupt
    IOCAF4_SetInterruptHandler(ISR_PSU_On);             //Power supply switched ON
    IOCAF5_SetInterruptHandler(ISR_ExternalPower);      //External power connected

    //Setup SLEEP mode
    CPUDOZEbits.IDLEN = 1;  //During SLEEP CPU clock is halted but the peripheral clock continues to run
    
    //Enable Global and Peripheral Interrupts
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    PIE0bits.IOCIE = 1; 
    
    printf("Battery Controller 1.1\n");
    printf("Date: %s\n\n", __DATE__);
    
    //Wait for power to stabilize
    IO_3V3_ENABLE_SetLow(); //Enable Power to I2C bus
    TIME_Delay_ms(1000);
    CLRWDT();
    
    //Initialize BMS IC
    LEDS_SetState(e_LED_FULL, true);
    LEDS_SetState(e_LED_BT1_BL, true);
    printf("BMS Initialization\n");
    while(!BMS_Initialize()){
        printf("BMS Initialization failed\n");
        TIME_Delay_ms(500);
        CLRWDT();
    }
    LEDS_SetToDefault();
    
    //Initialize CHG IC
    LEDS_SetState(e_LED_FULL, true);
    LEDS_SetState(e_LED_BT2_BL, true);
    printf("CHG Initialization\n");
    while(!CHG_Initialize()){
        printf("CHG Initialization failed\n");
        BMS_Update(state);
        TIME_Delay_ms(500);
        CLRWDT();
    }
    LEDS_SetToDefault();
    
    
    //Main loop
    while(1){
        bool keepRunning = state != e_STATE_IDLE;

        //Update BMS state and variables
        BMS_Update(state);
 
        //Update CHG state
        CHG_Update(state);
        
        //Show battery level
        if(extBtnPressed){
            extBtnPressed = false;
            LEDS_ShowBatteryLevel();
        }
        
        //Log data during charge and discharge
        if(state != e_STATE_IDLE)
            LogData();
        
        //Update LED state
        keepRunning |= LEDS_Update();
        
        if(runUpdateLogic){
            runUpdateLogic = false;

            //Enter low power mode
            if(!keepRunning){
                LEDS_SetState(e_LED_BT1_CH, false);
                asm("SLEEP");
                LEDS_SetState(e_LED_BT1_CH, true);
            }
        }
        
        
        //Change state
        bool PowerSupplyOn  = !IO_EN_I2C_GetValue();
        bool ChargerPresent = !IO_CHG_OK_GetValue();

        switch(state){
            case e_STATE_INIT:
                IO_3V3_ENABLE_SetHigh();        //Disable Power to I2C bus
                state = e_STATE_IDLE;
                break;

            case e_STATE_IDLE:
                if(ChargerPresent){
                    IO_3V3_ENABLE_SetLow();     //Enable Power to I2C bus
                    LEDS_SetToDefault();        //Turn off LEDs
                    state = e_STATE_CHARGING;
                }
                else if(PowerSupplyOn){
                    IO_3V3_ENABLE_SetLow();     //Enable Power to I2C bus
                    LEDS_SetToDefault();        //Turn off LEDs
                    state = e_STATE_DISCHARGING;
                }
                break;

            case e_STATE_CHARGING:
                if(!ChargerPresent){
                    CHG_EnableCharger(false);   //Disable charger
                    IO_3V3_ENABLE_SetHigh();    //Disable Power to I2C bus
                    LEDS_SetToDefault();        //Turn off LEDs
                    state = e_STATE_IDLE;
                }
                break;

            case e_STATE_DISCHARGING:
                if(!PowerSupplyOn || ChargerPresent){
                    IO_3V3_ENABLE_SetHigh();    //Disable Power to I2C bus
                    LEDS_SetToDefault();        //Turn off LEDs
                    state = e_STATE_IDLE;
                }
                break;
        }
        
        CLRWDT();
    }
}

static void LogData(void){
#if (_LOG_DATA == true)
    static int32_t last = _LOG_INTERVALL / 2;
    uint32_t time = TIME_Seconds();
    
    if(time - last >= _LOG_INTERVALL){
        last = time;
        
        float v1 = (float)BMS_GetCellVoltage(1) / 1000.0f;
        float v2 = (float)BMS_GetCellVoltage(2) / 1000.0f;
        float v3 = (float)BMS_GetCellVoltage(3) / 1000.0f;
        float current = (float)BMS_GetCurrent() / 1000.0f;
        float energy = (float)BMS_GetEnergy() / 1000.0f;
        float capacity = (float)BMS_GetCapacity() / 1000.0f;
        
#if (_LOG_RAW == true)
        printf("%.3f;%.3f;%.3f;%.3f;%d;%.3f;%.3f\n", v1, v2, v3, current, BMS_GetSOC(), energy, capacity);
#else
        printf("v1:%dmV v2:%dmV v3:%dmV  i:%dmA SOC:%d%% T:%d*C En:%ldmWh Ca:%ldmWh\n",
            BMS_GetCellVoltage(1), BMS_GetCellVoltage(2), BMS_GetCellVoltage(3),
            BMS_GetCurrent(), BMS_GetSOC(), BMS_GetTemperature(),
            BMS_GetEnergy(), BMS_GetCapacity());
#endif  
    }
#endif
}

/*
 * ISR called by the overflow of timer3 every 1 sec
 */
void ISR_Interrupt_1Sec(void){
    runUpdateLogic = true;
}

/*
 * ISR called when the button is pressed
 */
void ISR_ExtBtn(void){
    extBtnPressed = true;
}

/*
 * ISR called when the power supply is turned on
 */
void ISR_PSU_On(void){
    runUpdateLogic = true;
}

/*
 * ISR called when external power is connected
 */
void ISR_ExternalPower(void){
    runUpdateLogic = true;
}
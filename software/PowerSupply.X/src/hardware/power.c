/* 
 * File:    power.c
 * Author:  Manuel
 * Date:    19/10/2018
 * 
 * Comments:
 */

#include "power.h"
#include "graphics/GLCD.h"
#include "menu/menu.h"
#include "debug/errors.h"
#include "globalVariables.h"
#include "timer.h"
#include "delays.h"
#include <mcc.h>

#define _FLYBACK_TURN_ON_DELAY  100
#define _INTERPOLATE_VOLTAGE_CH1(x) PWR_Interpolate(x, _GLOBAL_VAR_CH(1).setVoltage.maxValue, _GLOBAL_VAR_CH(1).voltageCalPoints, _GLOBAL_NUM_VOLTAGE_CAL_POINTS)
#define _INTERPOLATE_VOLTAGE_CH2(x) PWR_Interpolate(x, _GLOBAL_VAR_CH(2).setVoltage.maxValue, _GLOBAL_VAR_CH(2).voltageCalPoints, _GLOBAL_NUM_VOLTAGE_CAL_POINTS)
#define _INTERPOLATE_CURRENT_CH1(x) PWR_Interpolate(x, _GLOBAL_VAR_CH(1).setCurrent.maxValue, _GLOBAL_VAR_CH(1).currentCalPoints, _GLOBAL_NUM_CURRENT_CAL_POINTS)
#define _INTERPOLATE_CURRENT_CH2(x) PWR_Interpolate(x, _GLOBAL_VAR_CH(2).setCurrent.maxValue, _GLOBAL_VAR_CH(2).currentCalPoints, _GLOBAL_NUM_CURRENT_CAL_POINTS)

//PSU_ChannelGlobalVariables_t PSU_GlobalVariables[2];
static bool isPowerSupplyON = false;
static bool isChannel1ON    = false;
static bool isChannel2ON    = false;

static void  PWR_DisablePeripherals(void);
static void  PWR_EnablePeripherals(void);
static void  PWR_UpdateCH1(void);
static void  PWR_UpdateCH2(void);

/*
 * Toggles power supply on or off
 */
void PWR_TurnOn(bool turnOn){
    
    if(turnOn){
        //Enable Switching regulator
        PWR_3V3_EN_SetHigh();
        __delay_ms(100);
        
        //Enable Peripherals
        PWR_EnablePeripherals();
 
        //Initialize global variables
        PWR_Initialize();

        //Initialize LCD display
        GLCD_Initialize();
        GLCD_SetBackLight(LCD_Backlight);
        MENU_Initialize();
        
        //Clear all errors
        ERRORS_ClearAll();
        
        //Enable interrupt on power button
        EX_INT1_InterruptFlagClear();
        EX_INT1_InterruptEnable();
    }
    else{
        GLCD_PowerOnOff(false);
 
        //Disable Peripherals
        PWR_DisablePeripherals();
        
        //Turn power off
        FLB_CH1_EN_SetLow();
        FLB_CH2_EN_SetLow();
        FLB_AUX_EN_SetLow();
        PWR_3V3_EN_SetLow();
        
        //Enable interrupt on power button
        EX_INT1_InterruptFlagClear();
        EX_INT1_InterruptEnable();
        
        //Enter sleep
        Sleep();
        
        //Enable Peripherals
        PWR_EnablePeripherals();
    }
    
    isPowerSupplyON = turnOn;
}

/*
 * Enable all peripherals
 */
static void PWR_DisablePeripherals(void){
    PMCON1bits.PMPEN = 0;   //Disable EPMP
    MCCP1_COMPARE_Stop();   //Disable backlight PWM
    CLC1CONLbits.LCEN = 0;  //Disable CLC1 (Flyback1 SYNC)
    CLC2CONLbits.LCEN = 0;  //Disable CLC2 (Flyback0 SYNC)
    TMR1_Stop();            //Stop timer1
    UART1_Disable();        //Disable Serial Port
    IEC1bits.IOCIE = 0;     //Disable IOCI interrupt
}

/*
 * Disable all peripherals 
 */
static void PWR_EnablePeripherals(void){
    PMCON1bits.PMPEN = 1;   //Enable EPMP
    MCCP1_COMPARE_Start();  //Enable backlight PWM
    CLC1CONLbits.LCEN = 1;  //Enable CLC1 (Flyback1 SYNC)
    CLC2CONLbits.LCEN = 1;  //Enable CLC2 (Flyback0 SYNC)
    TMR1_Start();           //Start timer1
    UART1_Enable();         //Enable Serial Port
    IEC1bits.IOCIE = 1;     //Enable IOCI interrupt
}

//Returns true if the power supply is on
bool PWR_IsPowerSupplyOn(void){
    return isPowerSupplyON;
}

//Initializes the global variables
void PWR_Initialize(void){
    _GLOBAL_VAR_CH(1).enabled                   = false;
    _GLOBAL_VAR_CH(1).setVoltage.value          = 1.000f;
    _GLOBAL_VAR_CH(1).setVoltage.maxValue       = 20.00f;
    _GLOBAL_VAR_CH(1).setVoltage.minValue       = 0.000f;
    _GLOBAL_VAR_CH(1).setVoltage.selectedDigit  = 0;
    _GLOBAL_VAR_CH(1).setVoltage.numIntDigits   = 1;
    _GLOBAL_VAR_CH(1).setVoltage.numDecDigits   = 3;
    _GLOBAL_VAR_CH(1).setCurrent.value          = 0.100f;
    _GLOBAL_VAR_CH(1).setCurrent.maxValue       = 1.000f;
    _GLOBAL_VAR_CH(1).setCurrent.minValue       = 0.000f;
    _GLOBAL_VAR_CH(1).setCurrent.selectedDigit  = -1;
    _GLOBAL_VAR_CH(1).setCurrent.numIntDigits   = 0;
    _GLOBAL_VAR_CH(1).setCurrent.numDecDigits   = 3;
    _GLOBAL_VAR_CH(1).senseVoltage              = 0.000f;
    _GLOBAL_VAR_CH(1).senseCurrent              = 0.000f;
    _GLOBAL_VAR_CH(1).sensePower                = 0.000f;
    
    _GLOBAL_VAR_CH(2).enabled                   = false;
    _GLOBAL_VAR_CH(2).setVoltage.value          = 1.000f;
    _GLOBAL_VAR_CH(2).setVoltage.maxValue       = 20.00f;
    _GLOBAL_VAR_CH(2).setVoltage.minValue       = 0.000f;
    _GLOBAL_VAR_CH(2).setVoltage.selectedDigit  = 0;
    _GLOBAL_VAR_CH(2).setVoltage.numIntDigits   = 1;
    _GLOBAL_VAR_CH(2).setVoltage.numDecDigits   = 3;
    _GLOBAL_VAR_CH(2).setCurrent.value          = 0.100f;
    _GLOBAL_VAR_CH(2).setCurrent.maxValue       = 1.000f;
    _GLOBAL_VAR_CH(2).setCurrent.minValue       = 0.000f;
    _GLOBAL_VAR_CH(2).setCurrent.selectedDigit  = -1;
    _GLOBAL_VAR_CH(2).setCurrent.numIntDigits   = 0;
    _GLOBAL_VAR_CH(2).setCurrent.numDecDigits   = 3;
    _GLOBAL_VAR_CH(2).senseVoltage              = 0.000f;
    _GLOBAL_VAR_CH(2).senseCurrent              = 0.000f;
    _GLOBAL_VAR_CH(2).sensePower                = 0.000f;
}

//Updates the DACs values with set voltage and current, reads the ADCs
void PWR_Update(void){
    static int64_t lastMillis = 0;

    //Update every 100mS
    if((TIME_GetMillis() - 100) > lastMillis){
        lastMillis =  TIME_GetMillis();

        //Enable AUX Flyback if one of the channels is enabled
        if(_GLOBAL_VAR_CH(1).enabled || _GLOBAL_VAR_CH(2).enabled){
            if(!FLB_AUX_EN_GetValue()){
                FLB_AUX_EN_SetHigh();
                TIME_Delay_ms(_FLYBACK_TURN_ON_DELAY);
            }
        }
        else{
            FLB_AUX_EN_SetLow();
        }
        
        //Update channels
        PWR_UpdateCH1();
        PWR_UpdateCH2();
        
        //Disable AUX Flyback in no channels are enabled
        if(!_GLOBAL_VAR_CH(1).enabled && !_GLOBAL_VAR_CH(2).enabled){
            FLB_AUX_EN_SetLow();
        }
    }
}

/*
 * Update channel 1 DAC values
 */
static void PWR_UpdateCH1(void){
    static float lastVDac = -1.0f;
    static float lastIDac = -1.0f;
    float vDac = ((_GLOBAL_VAR_CH(1).setVoltage.value - _GLOBAL_VAR_CH(1).voltageOffset) / 5.0f) * _GLOBAL_VAR_CH(1).voltageGain;
    float iDac = ((_GLOBAL_VAR_CH(1).setCurrent.value - _GLOBAL_VAR_CH(1).currentOffset) * 5.0f) * _GLOBAL_VAR_CH(1).currentGain;
    
    //Turn on channel
    if(_GLOBAL_VAR_CH(1).enabled && !isChannel1ON){
        //Initialize DACs and ADCs
        V_DAC_Initialize(_MAX5215_CH1_ADDRESS);
        I_DAC_Initialize(_MCP4716_CH1_ADDRESS);
        INA230_ADC_Initialize(_INA230_CH1_ADDRESS);

        V_DAC_SetVoltage(_MAX5215_CH1_ADDRESS, 0);
        V_DAC_Enable(_MAX5215_CH1_ADDRESS, true);
        I_DAC_SetCurrent(_MCP4716_CH1_ADDRESS, 0);
        I_DAC_Enable(_MCP4716_CH1_ADDRESS, true);

        isChannel1ON = true;
    }
    
    //Update Values
    if(_GLOBAL_VAR_CH(1).enabled){
        //Update CH1 Current DAC Values
        if(lastIDac != iDac){
            lastIDac = iDac;
            
            I_DAC_SetCurrent(_MCP4716_CH1_ADDRESS, iDac);
            I_DAC_Enable(_MCP4716_CH1_ADDRESS, true);
        }
        
        //Update CH1 Voltage DAC Values
        if(lastVDac != vDac){
            lastVDac = vDac;
            
            V_DAC_SetVoltage(_MAX5215_CH1_ADDRESS, vDac);
            V_DAC_Enable(_MAX5215_CH1_ADDRESS, true);
        }
        
        //Enable the output relay and LED
        if(!IO_CH1_OUT_EN_GetValue()){
            IO_CH1_OUT_EN_SetHigh();
            IO_LED_CH1_ON_SetLow();
            //__delay_ms(10);
            FLB_CH1_EN_SetHigh();
        }
        
        //Read CH1 ADC Sense values
        _GLOBAL_VAR_CH(1).senseVoltage = INA230_GetVoltage(_INA230_CH1_ADDRESS);
        _GLOBAL_VAR_CH(1).senseCurrent = INA230_GetCurrent(_INA230_CH1_ADDRESS);
        _GLOBAL_VAR_CH(1).sensePower   = INA230_GetPower(_INA230_CH1_ADDRESS);
    }
   
    //Turn off channel
    if(!_GLOBAL_VAR_CH(1).enabled && isChannel1ON){
        //Disable the output relay and LED
        IO_CH1_OUT_EN_SetLow();
        IO_LED_CH1_ON_SetHigh();

        //__delay_ms(500);
        
        //Disable the DACs
        lastVDac = -1.0f;
        lastIDac = -1.0f;
        
        //Disable flyback converter
        FLB_CH1_EN_SetLow();
        
        _GLOBAL_VAR_CH(1).senseVoltage = 0.0f;
        _GLOBAL_VAR_CH(1).senseCurrent = 0.0f;
        _GLOBAL_VAR_CH(1).sensePower   = 0.0f;
        
        isChannel1ON = false;
    }
}

/*
 * Update channel 2 DAC values
 */
static void PWR_UpdateCH2(void){
    static float lastVDac = -1.0f;
    static float lastIDac = -1.0f;
    float vDac = ((_GLOBAL_VAR_CH(2).setVoltage.value - _GLOBAL_VAR_CH(2).voltageOffset) / 5.0f) * _GLOBAL_VAR_CH(2).voltageGain;
    float iDac = ((_GLOBAL_VAR_CH(2).setCurrent.value - _GLOBAL_VAR_CH(2).currentOffset) * 5.0f) * _GLOBAL_VAR_CH(2).currentGain;
    
    //Turn on channel
    if(_GLOBAL_VAR_CH(2).enabled && !isChannel2ON){
        //Initialize DACs and ADCs
        V_DAC_Initialize(_MAX5215_CH2_ADDRESS);
        I_DAC_Initialize(_MCP4716_CH2_ADDRESS);
        INA230_ADC_Initialize(_INA230_CH2_ADDRESS);

        V_DAC_SetVoltage(_MAX5215_CH2_ADDRESS, 0);
        V_DAC_Enable(_MAX5215_CH2_ADDRESS, true);
        I_DAC_SetCurrent(_MCP4716_CH2_ADDRESS, 0);
        I_DAC_Enable(_MCP4716_CH2_ADDRESS, true);

        isChannel2ON = true;
    }
    
    //Update Values
    if(_GLOBAL_VAR_CH(2).enabled){
        //Update CH2 Current DAC Values
        if(lastIDac != iDac){
            lastIDac = iDac;
            
            I_DAC_SetCurrent(_MCP4716_CH2_ADDRESS, iDac);
            I_DAC_Enable(_MCP4716_CH2_ADDRESS, true);
        }
        
        //Update CH2 Voltage DAC Values
        if(lastVDac != vDac){
            lastVDac = vDac;
            
            V_DAC_SetVoltage(_MAX5215_CH2_ADDRESS, vDac);
            V_DAC_Enable(_MAX5215_CH2_ADDRESS, true);
        }
        
        //Enable the output relay and LED
        if(!IO_CH2_OUT_EN_GetValue()){
            IO_CH2_OUT_EN_SetHigh();
            IO_LED_CH2_ON_SetLow();
            __delay_ms(10);
            FLB_CH2_EN_SetHigh();
        }
        
        //Read CH1 ADC Sense values
        _GLOBAL_VAR_CH(2).senseVoltage = INA230_GetVoltage(_INA230_CH2_ADDRESS);
        _GLOBAL_VAR_CH(2).senseCurrent = INA230_GetCurrent(_INA230_CH2_ADDRESS);
        _GLOBAL_VAR_CH(2).sensePower   = INA230_GetPower(_INA230_CH2_ADDRESS);
    }
   
    //Turn off channel
    if(!_GLOBAL_VAR_CH(2).enabled && isChannel2ON){
        //Disable the output relay and LED
        IO_CH2_OUT_EN_SetLow();
        IO_LED_CH2_ON_SetHigh();

        __delay_ms(500);
        
        //Disable the DACs
        lastVDac = -1.0f;
        lastIDac = -1.0f;
        
        //Disable flyback converter
        FLB_CH2_EN_SetLow();
        
        _GLOBAL_VAR_CH(2).senseVoltage = 0.0f;
        _GLOBAL_VAR_CH(2).senseCurrent = 0.0f;
        _GLOBAL_VAR_CH(2).sensePower   = 0.0f;
        
        isChannel2ON = false;
    }
}
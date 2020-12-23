/* 
 * File:    main.c
 * Author:  Manuel
 * Date:    07/10/2018
 * Device:  PIC24FJ1024GB610
 * Rev:     1.1 2019
 * 
 * Firmware for the Power Supply board
 */

#include <stdint.h>
#include <stdbool.h>
#include "mcc.h"
#include "delays.h"
#include "menu/menu.h"
#include "graphics/GLCD.h"
#include "hardware/timer.h"
#include "hardware/epmp.h"
#include "hardware/power.h"
#include "hardware/battery.h"
#include "hardware/inputs.h"
#include "hardware/eeprom.h"
#include "hardware/I2C_master.h"
#include "debug/log.h"
#include "debug/errors.h"
#include "menu/icons.h"

//Static variables
static volatile int64_t pwrButtonPressTime;
static volatile bool    pwrButtonInterrupt = false;

//Static functions
static void PowerCallback(void);

int main(void){
    //Device initialization
    SYSTEM_Initialize();                            //Initialize the System
    EPMP_Initialize();                              //Initialize the Enhanced Parallel Master Port
    PWR_Initialize();                               //Initialize the Power Supply global variables
    I2C_Initialize();                               //Initialize the I2C hardware
    EXTINT_SetPowerButtonCallback(PowerCallback);   //Set the power button callback function
    TIME_Initialize();                              //Initialize timing functionality
    MENU_Initialize();
    
    //Turn on power supply
    PWR_TurnOn(true);
    __delay_ms(100);
    
    //Read the calibration points from the EEprom
    if(!EEPROM_LoadCallPoints()){   //Log the error
        ERRORS_ThrowError(e_EEPROM, "CAL POINTS CHECKSUM ERROR");
    }
    
    printf("Restart()\n");
    
    //Infinite loop
    while(1){
        if(PWR_IsPowerSupplyOn()){
            uint8_t buttons = INPUTS_GetButtons();
            int8_t  encoder = INPUTS_GetEncoder();
            
            MENU_Update(buttons, encoder);  //Update the screen content
            PWR_Update();                   //Update the values of the DACs and read values from ADCs
            Battery_Update();               //Update battery variables
        }
        
        //Handle the power button
        if(pwrButtonInterrupt){
            if((TIME_GetMillis() - 2000) > pwrButtonPressTime){         //If 2 seconds are elapsed
                pwrButtonInterrupt = false;
                printf("Toggle Power\n");
                PWR_TurnOn(!PWR_IsPowerSupplyOn());                 //Turn power supply On or Off
            }else if(IO_BTN_PWR_GetValue()){
                pwrButtonInterrupt = false;
                printf("Power button released\n");
                if(!PWR_IsPowerSupplyOn())
                    PWR_TurnOn(false);
            }
        }
    }

    return -1;
}

//Callback for the power button
static void PowerCallback(void){
    pwrButtonPressTime = TIME_GetMillis();
    pwrButtonInterrupt = true;
    printf("PowerCallback()\n");
}
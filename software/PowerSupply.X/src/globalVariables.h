/* 
 * File:    icons.h
 * Author:  Manuel
 * Date:    27/10/2018
 * 
 * Comments:
 */


#ifndef _SRC_GLOBAL_VARIABLES_H
#define	_SRC_GLOBAL_VARIABLES_H

#include <stdbool.h>
#include "menu/editableValue.h"

#define _GLOBAL_VAR_CH(x) PSU_GlobalVariables[(x) - 1]  //Returns the gobal variables of a channel
#define _GLOBAL_SCREEN_UPDATE_RATE_MS   200             //Milliseconds between screen updates

//EEPROM Addresses
#define _EEPROM_CALL_ADDRESS    (0)


typedef struct{
    float   value;          //Value
    float   maxValue;       //Maximum value
    float   minValue;       //Minnimum value
    int8_t  selectedDigit;  //Selected digit
    int8_t  numIntDigits;   //Number of digits for the integer part
    int8_t  numDecDigits;   //Number of digits for the decimal part
} MenuFloat_t;

typedef struct{
    bool        enabled;
    MenuFloat_t setVoltage;
    MenuFloat_t setCurrent;
    float       senseVoltage;
    float       senseCurrent;
    float       sensePower;
    float       voltageGain;
    float       voltageOffset;
    float       currentGain;
    float       currentOffset;
    //float       voltageCalPoints[_GLOBAL_NUM_VOLTAGE_CAL_POINTS];
    //float       currentCalPoints[_GLOBAL_NUM_CURRENT_CAL_POINTS];
} PSU_ChannelGlobalVariables_t;
extern PSU_ChannelGlobalVariables_t PSU_GlobalVariables[2];

extern uint8_t LCD_Backlight;
extern uint8_t LCD_TimeoutSeconds;



#endif	/* _SRC_GLOBAL_VARIABLES_H */


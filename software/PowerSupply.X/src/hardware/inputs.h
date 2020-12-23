/* 
 * File:    inputs.h
 * Author:  Manuel
 * Date:    11/10/2018
 * 
 * Comments:
 */

#ifndef SRC_INPUTS_H
#define	SRC_INPUTS_H

#include "mcc.h"

#ifndef _BIT
#define _BIT(x) (1 << x)
#endif

#define _BUTTON_ENC_PB  _BIT(0)
#define _BUTTON_UP_V    _BIT(1)
#define _BUTTON_DW_I    _BIT(2)
#define _BUTTON_MENU    _BIT(3)
#define _BUTTON_LEFT    _BIT(4)
#define _BUTTON_RIGHT   _BIT(5)
#define _BUTTON_ENCH1   _BIT(6)
#define _BUTTON_ENCH2   _BIT(7)

//Returns a bitmap that corresponds to the buttons been pressed
uint8_t INPUTS_GetButtons(void);

//Returns the relative move of the encoder from the previous function call
int8_t INPUTS_GetEncoder(void);

//Sets the callback function called when the power button is pressed
//void INPUTS_SetPowerButtonCallback(void(*callback)(bool));

#endif	/* SRC_INPUTS_H */


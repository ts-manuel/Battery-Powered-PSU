/* 
 * File:    graphics.h
 * Author:  Manuel
 * Date:    12/10/2018
 * 
 * Comments:
 */

#ifndef SRC_GRAPHICS_GRAPHICS_H
#define	SRC_GRAPHICS_GRAPHICS_H

#include <xc.h>
#include "GLCD.h"

//Draws the battery simbol
void GRAPHICS_DrawBatteryIcon(uint8_t x, uint8_t y, uint8_t percentage);

#endif	/* SRC_GRAPHICS_GRAPHICS_H */


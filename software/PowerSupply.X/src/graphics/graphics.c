/* 
 * File:    graphics.c
 * Author:  Manuel
 * Date:    12/10/2018
 * 
 * Comments:
 */

#include "graphics.h"

//Draws the battery symbol
void GRAPHICS_DrawBatteryIcon(uint8_t x, uint8_t y, uint8_t soc){
    //Draw battery outline
    GLCD_VLine(x, y + 1, 3, true);
    GLCD_HLine(x + 1, y,     8, true);
    GLCD_HLine(x + 1, y + 4, 8, true);
    GLCD_VLine(x + 8, y + 1, 3, true);
    GLCD_Pixel(x + 7, y + 3, true);
    
    //Fill battery outline
    uint8_t numSegments = soc / 12;
    for(uint8_t i = 0; i < numSegments; i++){
        uint8_t sx = x + (8 - i);
        GLCD_Pixel(sx,     y + 1, true);
        GLCD_Pixel(sx - 1, y + 2, true);
        if(i < (numSegments - 1))
            GLCD_Pixel(sx - 2, y + 3, true);
    }
}
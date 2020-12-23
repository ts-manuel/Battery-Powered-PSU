/* 
 * File:    menu_settings.c
 * Author:  Manuel
 * Date:    27/10/2018
 * 
 * Comments: Settings menu page
 */

#include "mcc.h"
#include "menu.h"
#include "hardware/inputs.h"
#include "hardware/power.h"
#include "hardware/battery.h"
#include "hardware/timer.h"
#include <stdio.h>

static void Initialize(void*);
static void Redraw(void);
static void ProcessInput(uint8_t buttons, int8_t encoder);
static void Tick(int64_t millis);


static const char* title = "BATTERY";
MenuPage_t menu_battery = {&Initialize, &Redraw, &ProcessInput, &Tick, true, &title, e_NORMAL};


static void Initialize(void* arg){
    
}

static void Redraw(void){
    
    for(uint8_t i = 0; i < 3; i++){
        uint8_t offX = i * 42 + 7;
        uint8_t offY = 11;

        //Draw outline
        GLCD_Rect(offX, offY + 4, offX + 30, offY + 43, true);
        GLCD_FillRect(offX + 12, offY, offX + 17, offY + 3, true);

        //Fill with charge left
        float percentage = (BatteryData.voltages[i] - 2.8f) / 1.35f;
        uint8_t minY = (offY + 42) - (uint8_t)(percentage * 37.0f);
        GLCD_FillRect(offX + 1, minY, offX + 29, offY + 42, true);

        //Print Cell voltage
        GLCD_SetFont(_FONT_4x5);
        GLCD_SetTextModeInverted(true);
        GLCD_printNumF(offX + 5,  offY + 26, BatteryData.voltages[i], 4, 2, '.', ' ');
        GLCD_PrintChar(offX + 22, offY + 26, 'V');
        GLCD_SetTextModeInverted(false);

        //Print battery designator
        GLCD_PrintString(offX + 4, offY + 46, "CELL "); 
        GLCD_PrintNumI(offX + 24, offY + 46, i + 1, 1, ' ');
    }
}

static void ProcessInput(uint8_t buttons, int8_t encoder){
    //Process buttons
    switch(buttons){
        case _BUTTON_ENCH1:
            _GLOBAL_VAR_CH(1).enabled = !_GLOBAL_VAR_CH(1).enabled;
            break;
        case _BUTTON_ENCH2:
            _GLOBAL_VAR_CH(2).enabled = !_GLOBAL_VAR_CH(2).enabled;
            break;
            
        case _BUTTON_LEFT:

            break;
        case _BUTTON_RIGHT:

            break;
            
        case _BUTTON_UP_V:
            
            break;
        case _BUTTON_DW_I:
            
            break;
        case _BUTTON_MENU:
            MENU_Pop();
            break;
        
        case _BUTTON_ENC_PB:

            break;
            
        default:
            break;
    }
    
    //Process encoder
    if(encoder){
        
    }
    
    menu_battery.outOfDate = true;
}

static void Tick(int64_t millis){
    menu_battery.outOfDate = true;
}

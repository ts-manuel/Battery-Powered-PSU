/* 
 * File:    menu_settings.c
 * Author:  Manuel
 * Date:    27/10/2018
 * 
 * Comments: Settings menu page
 */

#include "mcc.h"
#include "menu.h"
#include "editableValue.h"
#include "hardware/inputs.h"
#include "hardware/power.h"
#include <stdio.h>

static void Initialize(void*);
static void Redraw(void);
static void ProcessInput(uint8_t buttons, int8_t encoder);
static void Tick(int64_t millis);

static const char* title = "SETTINGS";
MenuPage_t menu_settings = {&Initialize, &Redraw, &ProcessInput, &Tick, true, &title, e_NORMAL};


#define _NUM_MENU_ARRAY_ENTRIES 3
static EditableValue_t menuArray[_NUM_MENU_ARRAY_ENTRIES] = 
{
    {e_UINT8,    "LCD_BACKLIGHT",   .valueUint8  = {&LCD_Backlight,        0,     255,    10}},
    {e_UINT8,    "LCD_TIMEUOT",     .valueUint8  = {&LCD_TimeoutSeconds,   0,     255,    1}},
    {e_MENU_PAGE,"CLOCK SETUP",     .menuPage    = {(uint8_t*)&menu_clock, "GG/MM/AA"}}
};
static uint8_t selectedItem;


static void Initialize(void* arg){
    
}

static void Redraw(void){
    const uint8_t offsetY = 15;
    
    GLCD_SetFont(_FONT_4x5);
    for(uint8_t i = 0; i < _NUM_MENU_ARRAY_ENTRIES; i++){
        uint8_t y = i * 6 + offsetY;
        
        GLCD_PrintString(10, y, menuArray[i].name);
        EVAL_Print(80, y, &menuArray[i]);
        
        //Draw arrow near selected item
        if(i == selectedItem){
            GLCD_VLine(2, y, 5, true);
            GLCD_VLine(3, y + 1, 3, true);
            GLCD_Pixel(4, y + 2, true);
        }
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
            EVAL_AddToValue(&menuArray[selectedItem], -1.0f);
            break;
        case _BUTTON_RIGHT:
            EVAL_AddToValue(&menuArray[selectedItem], 1.0f);
            break;
            
        case _BUTTON_UP_V:
            if(selectedItem > 0)
                selectedItem --;
            break;
        case _BUTTON_DW_I:
            if(selectedItem < _NUM_MENU_ARRAY_ENTRIES - 1)
                selectedItem ++;
            break;
        case _BUTTON_MENU:
            MENU_Pop();
            break;
        
        case _BUTTON_ENC_PB:
            if(menuArray[selectedItem].type == e_MENU_PAGE){
                MENU_Push((MenuPage_t*)menuArray[selectedItem].menuPage.menuPage, NULL);
            }
            break;
            
        default:
            break;
    }
    
    //Process encoder
    if(encoder){
        EVAL_AddToValue(&menuArray[selectedItem], (float)encoder);
    }
    
    menu_settings.outOfDate = true;
}

static void Tick(int64_t millis){
    
}
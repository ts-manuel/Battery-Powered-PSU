/* 
 * File:    menu_menu.c
 * Author:  Manuel
 * Date:    27/10/2018
 * 
 * Comments: Menu entry point
 */

#include "mcc.h"
#include "menu.h"
#include "icons.h"
#include "hardware/inputs.h"
#include "hardware/power.h"
#include <stdio.h>

static void Initialize(void*);
static void Redraw(void);
static void ProcessInput(uint8_t buttons, int8_t encoder);
static void Tick(int64_t millis);

static const char* title = "MENU";
MenuPage_t menu_menu = {&Initialize, &Redraw, &ProcessInput, &Tick, true, &title, e_NORMAL};

typedef struct{
    MenuPage_t*     menuPage;
    const GLCD_Bitmap_t*  ico;
} MenuEntry_t;

#define _NUM_MENU_ENTRIES 5
static const MenuEntry_t menuEntries[_NUM_MENU_ENTRIES] = {
    {NULL,              &returnICO},
    {&menu_settings,    &settingsICO},
    {&menu_battery,     &batteryICO},
    {&menu_calibration, &calibrationICO},
    {&menu_errors,      &errorsICO}
};
static uint8_t selectedItem = 1;

static void Initialize(void* arg){
    
}

static void Redraw(void){
    
    //Draw center icon
    GLCD_HLine(44, 13, 6, true);
    GLCD_HLine(44, 14, 5, true);
    GLCD_VLine(44, 15, 4, true);
    GLCD_VLine(45, 15, 3, true);
    
    GLCD_HLine(79, 13, 6, true);
    GLCD_HLine(80, 14, 5, true);
    GLCD_VLine(84, 15, 4, true);
    GLCD_VLine(83, 15, 3, true);
    
    GLCD_HLine(44, 53, 6, true);
    GLCD_HLine(44, 52, 5, true);
    GLCD_VLine(44, 48, 4, true);
    GLCD_VLine(45, 49, 3, true);
    
    GLCD_HLine(79, 53, 6, true);
    GLCD_HLine(80, 52, 5, true);
    GLCD_VLine(84, 48, 4, true);
    GLCD_VLine(83, 49, 3, true);
    
    GLCD_Rect(47, 16, 81, 50, true);
    GLCD_DrawBitmap(48, 17, menuEntries[selectedItem].ico);
    uint8_t stringLength = GLCD_GetStringWidth(*menuEntries[selectedItem].menuPage->title_srt);
    uint8_t offsetX = _LCD_HALF_W - stringLength / 2;
    GLCD_PrintString(offsetX, 57, *menuEntries[selectedItem].menuPage->title_srt);
    
    //Draw left Icon
    if(selectedItem > 0){
        GLCD_Rect(2, 16, 2 + 34, 16 + 34, true);
        GLCD_DrawBitmap(3, 17, menuEntries[selectedItem - 1].ico);
        
        //Draw left arrow
        GLCD_VLine(45, 28, 10, true);
        GLCD_VLine(44, 29, 8,  true);
        GLCD_VLine(43, 30, 6,  true);
        GLCD_VLine(42, 31, 4,  true);
        GLCD_VLine(41, 32, 2,  true);
    }
    
    
    //Draw right Icon
    if(selectedItem < _NUM_MENU_ENTRIES - 1){
        GLCD_Rect(91, 16, 91 + 34, 16 + 34, true);
        GLCD_DrawBitmap(92, 17, menuEntries[selectedItem + 1].ico);
    
        //Draw right arrow
        GLCD_VLine(83, 28, 10, true);
        GLCD_VLine(84, 29, 8,  true);
        GLCD_VLine(85, 30, 6,  true);
        GLCD_VLine(86, 31, 4,  true);
        GLCD_VLine(87, 32, 2,  true);
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
            if(selectedItem > 0)
                selectedItem --;
            break;
        case _BUTTON_RIGHT:
            if(selectedItem < _NUM_MENU_ENTRIES - 1)
                selectedItem ++;
            break;
            
        case _BUTTON_UP_V:
            
            break;
        case _BUTTON_DW_I:
            
            break;
        case _BUTTON_MENU:
            MENU_Pop();
            break;
        
        case _BUTTON_ENC_PB:
            if(menuEntries[selectedItem].menuPage != NULL)
                MENU_Push(menuEntries[selectedItem].menuPage, NULL);
            else
                MENU_Pop();
            break;
            
        default:
            break;
    }
    
    //Process encoder
    if(encoder){
        int8_t newSelectedItem = (int8_t)selectedItem + encoder;
        
        if(newSelectedItem < 0)
            selectedItem = 0;
        else if(newSelectedItem >= _NUM_MENU_ENTRIES)
            selectedItem = _NUM_MENU_ENTRIES - 1;
        else
            selectedItem = newSelectedItem;
    }
    
    menu_menu.outOfDate = true;
}

static void Tick(int64_t millis){
    
}
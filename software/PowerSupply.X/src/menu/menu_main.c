/* 
 * File:    menu_main.c
 * Author:  Manuel
 * Date:    10/10/2018
 * 
 * Comments: Main page of the menu
 */

#include "mcc.h"
#include "menu.h"
#include "hardware/inputs.h"
#include "hardware/power.h"
#include "debug/errors.h"
#include <stdio.h>

static void Initialize(void*);
static void Redraw(void);
static void ProcessInput(uint8_t buttons, int8_t encoder);
static void Tick(int64_t millis);
static MenuFloat_t* GetSelectedMenuFloat(void);


static char date[22];
static const char* title = "                     ";
MenuPage_t menu_main = {&Initialize, &Redraw, &ProcessInput, &Tick, true, &title, e_NORMAL};

static uint8_t selectedChannel = 0;
static bool isVoltageSelected = true;

//Initialize menu
static void Initialize(void* arg){
   
}

//Redraw the screen
static void Redraw(void){
    
    GLCD_VLine(_LCD_HALF_W - 1, 7, _LCD_HEIGHT - 8, true);
    GLCD_VLine(_LCD_HALF_W,     7, _LCD_HEIGHT - 8, true);
    GLCD_HLine(0,              42, _LCD_WIDTH,      true);
    
    //Draw channel 1
    GLCD_VLine(15, 8, 7, true);
    GLCD_HLine(0, 15, 16, true);
    GLCD_SetFont(_FONT_4x5);
    GLCD_SetTextModeInverted(selectedChannel == 1);
    GLCD_PrintString(1, 9, "CH1");
    GLCD_SetTextModeInverted(false);
    GLCD_PrintString(43, 47, "SET V");
    GLCD_PrintString(43, 59, "SET A");
    
    GLCD_SetFont(_FONT_8x11);
    GLCD_printNumF(2, 17, _GLOBAL_VAR_CH(1).senseVoltage, 6, 3, '.', ' ');
    GLCD_printNumF(11, 29, _GLOBAL_VAR_CH(1).senseCurrent, 5, 3, '.', ' ');
    GLCD_PrintString(53, 17, "V");
    GLCD_PrintString(53, 29, "A");
    GLCD_SetFont(_FONT_6x9);
    int VoltageCH1CursorPos = (selectedChannel == 1 && isVoltageSelected == true)  ? _GLOBAL_VAR_CH(1).setVoltage.selectedDigit : _NO_CURSOR;
    int CurrentCH1CursorPos = (selectedChannel == 1 && isVoltageSelected == false) ? _GLOBAL_VAR_CH(1).setCurrent.selectedDigit : _NO_CURSOR;
    GLCD_printNumWithCursorF(2, 44, _GLOBAL_VAR_CH(1).setVoltage.value, 6, 3, '.', ' ', VoltageCH1CursorPos);
    GLCD_printNumWithCursorF(9, 55, _GLOBAL_VAR_CH(1).setCurrent.value, 5, 3, '.', ' ', CurrentCH1CursorPos);
    
    
    //Draw channel 2
    GLCD_VLine(80, 8, 7, true);
    GLCD_HLine(65, 15, 16, true);
    GLCD_SetFont(_FONT_4x5);
    GLCD_SetTextModeInverted(selectedChannel == 2);
    GLCD_PrintString(66, 9, "CH2");
    GLCD_SetTextModeInverted(false);
    GLCD_PrintString(109, 47, "SET V");
    GLCD_PrintString(109, 59, "SET A");
    
    GLCD_SetFont(_FONT_8x11);
    GLCD_printNumF(67, 17, _GLOBAL_VAR_CH(2).senseVoltage, 6, 3, '.', ' ');
    GLCD_printNumF(76, 29, _GLOBAL_VAR_CH(2).senseCurrent, 5, 3, '.', ' ');
    GLCD_PrintString(119, 17, "V");
    GLCD_PrintString(119, 29, "A");
    GLCD_SetFont(_FONT_6x9);
    int VoltageCH2CursorPos = (selectedChannel == 2 && isVoltageSelected == true)  ? _GLOBAL_VAR_CH(2).setVoltage.selectedDigit : _NO_CURSOR;
    int CurrentCH2CursorPos = (selectedChannel == 2 && isVoltageSelected == false) ? _GLOBAL_VAR_CH(2).setCurrent.selectedDigit : _NO_CURSOR;
    GLCD_printNumWithCursorF(67, 44, _GLOBAL_VAR_CH(2).setVoltage.value, 6, 3, '.', ' ', VoltageCH2CursorPos);
    GLCD_printNumWithCursorF(74, 55, _GLOBAL_VAR_CH(2).setCurrent.value, 5, 3, '.', ' ', CurrentCH2CursorPos);
    
    //Print date
    GLCD_SetFont(_FONT_4x5);
    GLCD_PrintString(1, 1, date);
}


//Handle inputs
static void ProcessInput(uint8_t buttons, int8_t encoder){
    bcdTime_t time;
    while (RTCC_TimeGet(&time) == false);
    
    //Process buttons
    switch(buttons){
        case _BUTTON_ENCH1:
            _GLOBAL_VAR_CH(1).enabled = !_GLOBAL_VAR_CH(1).enabled;
            break;
            
        case _BUTTON_ENCH2:
            _GLOBAL_VAR_CH(2).enabled = !_GLOBAL_VAR_CH(2).enabled;
            break;
            
        case _BUTTON_LEFT:
            MENU_ChangeSelectedDigitMenuFloat(GetSelectedMenuFloat(), 1);
            break;
            
        case _BUTTON_RIGHT:
            MENU_ChangeSelectedDigitMenuFloat(GetSelectedMenuFloat(), -1);
            break;
            
        case _BUTTON_UP_V:
            if(isVoltageSelected)
                selectedChannel = (selectedChannel + 1) % 3;
            else{
                isVoltageSelected = true;
                if(selectedChannel == 0)
                    selectedChannel = 1;
            }
            break;
            
        case _BUTTON_DW_I:
            if(!isVoltageSelected)
                selectedChannel = (selectedChannel + 1) % 3;
            else{
                isVoltageSelected = false;
                if(selectedChannel == 0)
                    selectedChannel = 1;
            }
            break;
            
        case _BUTTON_MENU:
            MENU_Push(&menu_menu, NULL);
            break;
        
        default:
            break;
    }
    
    //Process encoder
    if(encoder){
        MENU_IncrementMenuFloat(GetSelectedMenuFloat(), encoder);
    }
    
    menu_main.outOfDate = true;
}

static void Tick(int64_t millis){
    //Update date string
    bcdTime_t time;
    if(RTCC_TimeGet(&time) == true){
        sprintf(date, "%02d/%02d/20%02d   %02d:%02d", time.tm_mday, time.tm_mon, time.tm_year, time.tm_hour, time.tm_min);
    }
    
    menu_main.outOfDate = true;
}

//Returns a pointer to the selected menu float or NULL if there is none
static MenuFloat_t* GetSelectedMenuFloat(void){
    
    if(selectedChannel == 1 || selectedChannel == 2){
        if(isVoltageSelected)
            return &_GLOBAL_VAR_CH(selectedChannel).setVoltage;
        else
            return &_GLOBAL_VAR_CH(selectedChannel).setCurrent;
    }

    return NULL;
}
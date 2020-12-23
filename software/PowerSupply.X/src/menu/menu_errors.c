/* 
 * File:    menu_errors.c
 * Author:  Manuel
 * Date:    18/04/2019
 * 
 * Comments: This page of the menu show all the error that had occurrentd
 */

#include "mcc.h"
#include "menu.h"
#include "hardware/inputs.h"
#include "debug/errors.h"
#include <stdio.h>

static void Initialize(void*);
static void Redraw(void);
static void ProcessInput(uint8_t buttons, int8_t encoder);
static void Tick(int64_t millis);

static const char* title = "ERRORS";
MenuPage_t menu_errors = {&Initialize, &Redraw, &ProcessInput, &Tick, true, &title, e_NORMAL};

static int selectedError        = 0;    //Index of the error selected by the arrow
static int indexOfFirstError    = 0;    //Index of first error displyed in the list

static void Initialize(void* arg){
    selectedError = 0;
}

static void Redraw(void){
    int y = 15;
    
    GLCD_SetFont(_FONT_4x5);
    
    //Scroll the list when the selection goes outside the screen
    if(selectedError > (indexOfFirstError + 7))
        indexOfFirstError = selectedError - 7;
    else if(selectedError < indexOfFirstError)
        indexOfFirstError = selectedError;
    
    //Display the list of errors
    for(int i = indexOfFirstError; i < ERRORS_GetErrorCount(); i ++){
        Error_t error = ERRORS_GetError(i);
        GLCD_PrintString(5, y, ErrorTypeNames[error.type]);
        
        //Draw arrow near selected item
        if(i == selectedError){
            GLCD_VLine(2, y, 5, true);
            GLCD_VLine(3, y + 1, 3, true);
            GLCD_Pixel(4, y + 2, true);
        }
        
        y += 6;
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
            if(selectedError > 0)
                selectedError --;
            break;
        case _BUTTON_DW_I:
            if((selectedError + 1) < ERRORS_GetErrorCount())
                selectedError ++;
            break;
        case _BUTTON_MENU:
            MENU_Pop();
            break;
        
        case _BUTTON_ENC_PB:
            MENU_Push(&menu_error_info , (void*)(&selectedError));
            break;
            
        default:
            break;
    }
    
    
    
    menu_errors.outOfDate = true;
}

static void Tick(int64_t millis){
    menu_errors.outOfDate = true;
}
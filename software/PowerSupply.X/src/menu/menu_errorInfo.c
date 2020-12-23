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

static const char* title = "ERROR INFO";
MenuPage_t menu_error_info = {&Initialize, &Redraw, &ProcessInput, &Tick, true, &title, e_NORMAL};

static int selectedError;

static void Initialize(void* arg){
    selectedError = *((int*)arg);
}

static void Redraw(void){
    Error_t error = ERRORS_GetError(selectedError);
    
    GLCD_SetFont(_FONT_4x5);
    GLCD_PrintString(5, 10, "ERROR: ");
    
    char buffer[31];
    int i = 0;
    int charCount = 0;
    int y = 22;
    const int lineWidth = 30;
    do{
        buffer[charCount] = error.description[i];
        charCount++;
        
        if(charCount > lineWidth){
            //Remove last word
            while(error.description[i] != ' '){
                buffer[i] = '\0';
                i--;
            }
            
            //Print line
            GLCD_PrintString(8, y, buffer);
            charCount = 0;
            y += 8;
        }
    } while(error.description[i++] != '\0');
    if(charCount > 0){
        //Print line
        buffer[charCount] = '\0';
        GLCD_PrintString(8, y, buffer);
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
    
    menu_error_info.outOfDate = true;
}

static void Tick(int64_t millis){
    menu_error_info.outOfDate = true;
}
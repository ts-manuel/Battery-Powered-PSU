/* 
 * File:    menu_clock.c
 * Author:  Manuel
 * Date:    19/01/2019
 * 
 * Comments: Settings menu page
 */

#include "mcc.h"
#include "menu.h"
#include "hardware/inputs.h"
#include <stdio.h>

static void Initialize(void*);
static void Redraw(void);
static void ProcessInput(uint8_t buttons, int8_t encoder);
static void Tick(int64_t millis);

static const char* title = "CLOCK SETUP";
MenuPage_t menu_clock = {&Initialize, &Redraw, &ProcessInput, &Tick, true, &title, e_NORMAL};


typedef enum {
    e_DAY,
    e_MONTH,
    e_YEAR,
    e_HOUR,
    e_MINUTE,
    e_SECOND
} ClockDigitType_t;
static ClockDigitType_t selectedDigit = e_DAY;

typedef struct{
    const int offsetX;
    const int offsetY;
    const int maxValue;
    int*      value;
} ClockDigit_t;

#define _NUM_CLOCK_DIGITS 6
static bcdTime_t stime;
static ClockDigit_t clockDigit[_NUM_CLOCK_DIGITS] = {
    {40, 20, 31, &stime.tm_mday},   //Day
    {65, 20, 12, &stime.tm_mon},    //Month
    {90, 20, 99, &stime.tm_year},   //Year
    {40, 40, 23, &stime.tm_hour},   //Hour
    {61, 40, 59, &stime.tm_min},    //Minute
    {82, 40, 59, &stime.tm_sec},    //Minute
};


static void Initialize(void* arg){
    //Read Date and Time from the RTC
    while(!RTCC_TimeGet(&stime));
}

static void Redraw(void){
    
    //Print Text
    GLCD_SetFont(_FONT_4x5);
    GLCD_PrintString(2, 23, "DATE:");
    GLCD_PrintString(2, 43, "TIME:");
    
    
    GLCD_SetFont(_FONT_6x9);
    GLCD_PrintString(clockDigit[e_DAY].offsetX,  clockDigit[e_DAY].offsetY,  "  /   /");
    GLCD_PrintString(clockDigit[e_HOUR].offsetX, clockDigit[e_HOUR].offsetY, "  :  :");
    //Print Digits
    for(uint8_t i = 0; i < _NUM_CLOCK_DIGITS; i++){
        GLCD_PrintNumI(clockDigit[i].offsetX, clockDigit[i].offsetY, *(clockDigit[i].value), 2, ' ');
    }

    //Print upper arrow
    if(*(clockDigit[selectedDigit].value) < clockDigit[selectedDigit].maxValue){
        GLCD_HLine(clockDigit[selectedDigit].offsetX + 6, clockDigit[selectedDigit].offsetY - 5, 1,  true);
        GLCD_HLine(clockDigit[selectedDigit].offsetX + 5, clockDigit[selectedDigit].offsetY - 4, 3,  true);
        GLCD_HLine(clockDigit[selectedDigit].offsetX + 3, clockDigit[selectedDigit].offsetY - 3, 7,  true);
        GLCD_HLine(clockDigit[selectedDigit].offsetX + 1, clockDigit[selectedDigit].offsetY - 2, 11, true);
    }
    
    //Print lower arrow
    if(*(clockDigit[selectedDigit].value) > 0){
        GLCD_HLine(clockDigit[selectedDigit].offsetX + 1, clockDigit[selectedDigit].offsetY + 10, 11, true);
        GLCD_HLine(clockDigit[selectedDigit].offsetX + 3, clockDigit[selectedDigit].offsetY + 11, 7,  true);
        GLCD_HLine(clockDigit[selectedDigit].offsetX + 5, clockDigit[selectedDigit].offsetY + 12, 3,  true);
        GLCD_HLine(clockDigit[selectedDigit].offsetX + 6, clockDigit[selectedDigit].offsetY + 13, 1,  true);
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
            if(selectedDigit > 0)
                selectedDigit --;
            break;
        case _BUTTON_RIGHT:
            if(selectedDigit < _NUM_CLOCK_DIGITS - 1)
                selectedDigit ++;
            break;
            
        case _BUTTON_UP_V:
            if((*(clockDigit[selectedDigit].value)) < clockDigit[selectedDigit].maxValue){
                (*(clockDigit[selectedDigit].value)) ++;
            }
            break;
        case _BUTTON_DW_I:
            if((*(clockDigit[selectedDigit].value)) > 0){
                (*(clockDigit[selectedDigit].value)) --;
            }
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
        int* value = clockDigit[selectedDigit].value;
        int newValue = (*value) + encoder;
        
        if((newValue >= 0) && (newValue <= clockDigit[selectedDigit].maxValue))
            (*(clockDigit[selectedDigit].value)) = newValue;
    }
    
    //Write Date and Time to RTC
    RTCC_TimeSet(&stime);

    menu_clock.outOfDate = true;
}

static void Tick(int64_t millis){
    //Read Date and Time from the RTC
    while(!RTCC_TimeGet(&stime));
    menu_clock.outOfDate = true;
}

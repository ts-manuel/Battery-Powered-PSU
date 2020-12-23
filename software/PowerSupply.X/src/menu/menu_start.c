/* 
 * File:    menu_start.c
 * Author:  Manuel
 * Date:    21/10/2018
 * 
 * Comments: Start page
 */

#include "mcc.h"
#include "menu.h"
#include "icons.h"
#include "hardware/inputs.h"
#include <stdio.h>

static void Initialize(void*);
static void Redraw(void);
static void ProcessInput(uint8_t buttons, int8_t encoder);
static void Tick(int64_t millis);

static const char* title = "21/10/2018 14:38:00";
MenuPage_t menu_start = {&Initialize, &Redraw, &ProcessInput, &Tick, true, &title, e_FULL_SCREEN};


//Initialize menu
static void Initialize(void* arg){
    
}

//Redraw the screen
static void Redraw(void){
    GLCD_DrawBitmap(0, 0, &mainPageBMP);
}

//Handle inputs
static void ProcessInput(uint8_t buttons, int8_t encoder){
    
    
}

static void Tick(int64_t millis){
    if(millis > 2000)
        MENU_Push(&menu_main, NULL);
}
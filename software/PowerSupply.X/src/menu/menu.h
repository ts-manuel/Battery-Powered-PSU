/* 
 * File:    menu.h
 * Author:  Manuel
 * Date:    10/10/2018
 * 
 * Comments: menu interface
 */

#ifndef SRC_MENU_MENU_H
#define	SRC_MENU_MENU_H

#include "mcc.h"
#include "graphics/GLCD.h"
#include "graphics/graphics.h"
#include "hardware/power.h"
#include "hardware/battery.h"
#include "hardware/timer.h"



typedef enum{
    e_FULL_SCREEN,  //The menu occupies the entire screen
    e_NORMAL        //The battery icon and menu title are drawn automatically
} MenuType_t;

typedef struct{
    void(*Initialize)(void*);                               //Pointer to a function that initializes the menu
    void(*Redraw)(void);                                    //Pointer to a function that redraws the screen
    void(*ProcessInput)(uint8_t buttons, int8_t encoder);   //Pointer to a function that handles the inputs
    void(*Tick)(int64_t millis);                            //Function called at the screen update rate
    bool                    outOfDate;  //Set to true if the menu needs to be redraw
    const char**            title_srt;  //Menu title
    MenuType_t              type;       //Type of menu
} MenuPage_t;

typedef struct{
    MenuPage_t* stackArray[10];
    uint8_t     stackPointer;
} MenuStack_t;

//Function that initializes the menu and draws the screen
void MENU_Initialize(void);

//Function that handles the inputs and redraws the screen if needed
void MENU_Update(uint8_t buttons, int8_t encoder);

//Draws the template for the menu
void MENU_DrawTemplate(MenuPage_t* menuPage);

//Pushes a menu page onto the menu stack
void MENU_Push(MenuPage_t* menuPage, void* arg);

//Pops a page from the menu stack
void MENU_Pop(void);


//Increments the selected digit of the menu float by value
void MENU_IncrementMenuFloat(MenuFloat_t* menuFloat, int8_t value);

//Changes the selected digit of the menu float by offset
void MENU_ChangeSelectedDigitMenuFloat(MenuFloat_t* menuFloat, int8_t offset);


extern MenuPage_t menu_start;
extern MenuPage_t menu_main;
extern MenuPage_t menu_menu;
extern MenuPage_t menu_settings;
extern MenuPage_t menu_battery;
extern MenuPage_t menu_calibration;
extern MenuPage_t menu_clock;
extern MenuPage_t menu_errors;
extern MenuPage_t menu_error_info;

#endif	/* SRC_MENU_MENU_H */


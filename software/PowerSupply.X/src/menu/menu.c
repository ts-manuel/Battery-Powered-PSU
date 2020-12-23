/* 
 * File:    menu.c
 * Author:  Manuel
 * Date:    10/10/2018
 * 
 * Comments: menu interface
 */

#include "menu.h"
#include "globalVariables.h"
#include "editableValue.h"
#include "debug/errors.h"
#include "hardware/battery.h"
#include "icons.h"
#include <math.h>

#define currentMenuPage menuStack.stackArray[menuStack.stackPointer - 1]

//Global variables
static MenuStack_t  menuStack;

//Draws the normal menu template
static void MENU_DrawNormalTemplate(MenuPage_t* menuPage);

//Function that initializes the menu and draws the screen
void MENU_Initialize(void){
    menuStack.stackPointer = 0;
    MENU_Push(&menu_start, NULL);
    
    currentMenuPage->Initialize(NULL);
    currentMenuPage->outOfDate = false;
    MENU_DrawTemplate(currentMenuPage);
    currentMenuPage->Redraw();
    GLCD_Update();
    GLCD_SetBackLight(LCD_Backlight);
}

//Function that handles the inputs and redraws the screen if needed
void MENU_Update(uint8_t buttons, int8_t encoder){
    static int64_t millisUpdateScreen       = 0;
    static int64_t millisInactivityCounter  = 0;
    static uint8_t inactivityCounter        = 0;  //Increments every second, reseted every time a button is pressed
    
    //Process inputs
    if((buttons | encoder) && (ERRORS_GetUndisplayedErorrCont() == 0)){
        currentMenuPage->ProcessInput(buttons, encoder);    //Process inputs
        inactivityCounter = 0;                              //Reset the inactivity counter
    }
    
    //Update the screen at the screen update rate
    if((TIME_GetMillis() - millisUpdateScreen) > _GLOBAL_SCREEN_UPDATE_RATE_MS){
        millisUpdateScreen = TIME_GetMillis();
        currentMenuPage->Tick(millisUpdateScreen);
    }
    
    //Redraw the screen if it is out of date
    if(currentMenuPage->outOfDate){
        currentMenuPage->outOfDate = false;
        MENU_DrawTemplate(currentMenuPage);
        currentMenuPage->Redraw();
        
        if(ERRORS_GetUndisplayedErorrCont() == 0)
            GLCD_Update();
    }
    
    //Check for errors
    if(ERRORS_GetUndisplayedErorrCont() > 0){
        ERRORS_ProcessInput(buttons, encoder);
        ERRORS_DrawErrorMessageBox();
        GLCD_Update();
    }
    
    //Increment the inactivity counter every second
    if((TIME_GetMillis() - millisInactivityCounter) > 1000 && inactivityCounter < 255){
        millisInactivityCounter = TIME_GetMillis();
        inactivityCounter ++;
    }
    
    //Set the LCD backlight
    GLCD_SetBackLight(inactivityCounter < LCD_TimeoutSeconds ? LCD_Backlight : 0);
}

//Draws the template for the menu
void MENU_DrawTemplate(MenuPage_t* menuPage){
    switch(menuPage->type){
        case e_FULL_SCREEN:
            GLCD_ClrScr();
            break;
        case e_NORMAL:
            GLCD_ClrScr();
            MENU_DrawNormalTemplate(menuPage);
            break;
    }
}

//Pushes a menu page onto the menu stack
void MENU_Push(MenuPage_t* menuPage, void* arg){
    if(menuPage != NULL){
        menuStack.stackArray[menuStack.stackPointer++] = menuPage;
        currentMenuPage->outOfDate = true;
        currentMenuPage->Initialize(arg);
    }
}

//Pops a page from the menu stack
void MENU_Pop(void){
    if(menuStack.stackPointer > 1)
        menuStack.stackPointer--;
}

//Draws the normal menu template
static void MENU_DrawNormalTemplate(MenuPage_t* menuPage){
    uint8_t soc = BatteryData.SOC;
    
    //Draw horizontal and vertical lines
    GLCD_HLine(0, 7, _LCD_WIDTH, true);
    
    //Draw menu title
    GLCD_SetFont(_FONT_4x5);
    GLCD_PrintString(1, 1, *menuPage->title_srt);
    
    //Draw error icon
    if(ERRORS_GetErrorCount() > 0)
        GLCD_DrawBitmap(_LCD_WIDTH - 45, 0, &errorSmallICO);
    
    //Print SOC
    char str[5];
    int offsety;
    
    if(soc < 10)
        offsety = 25;
    else if(soc < 100)
        offsety = 28;
    else
        offsety = 31;

    sprintf(str, "%3d%%", soc);
    GLCD_PrintString(_LCD_WIDTH - offsety, 1, str);
    
    //Draw battery icon
    GRAPHICS_DrawBatteryIcon(_LCD_WIDTH - 10, 1, soc);
}


//Increments the selected digit of the menu float by value
void MENU_IncrementMenuFloat(MenuFloat_t* menuFloat, int8_t value){
    if(menuFloat != NULL){
        float newValue;
        float valueToAdd;
        
        valueToAdd = (float)pow(10.0f, (float)menuFloat->selectedDigit) * value;
        
        newValue = menuFloat->value + valueToAdd;

        if(newValue > menuFloat->maxValue)
            menuFloat->value = menuFloat->maxValue;
        else if(newValue < menuFloat->minValue)
            menuFloat->value = menuFloat->minValue;
        else
            menuFloat->value = newValue;
    }
}

//Changes the selected digit of the menu float by offset
void MENU_ChangeSelectedDigitMenuFloat(MenuFloat_t* menuFloat, int8_t offset){
    if(menuFloat != NULL){
        int8_t newSelectedDigit = menuFloat->selectedDigit + offset;
        
        if(newSelectedDigit > menuFloat->numIntDigits - 1)
            menuFloat->selectedDigit = menuFloat->numIntDigits - 1;
        else if(newSelectedDigit < -menuFloat->numDecDigits)
            menuFloat->selectedDigit = -menuFloat->numDecDigits;
        else
            menuFloat->selectedDigit = newSelectedDigit;
    }
}
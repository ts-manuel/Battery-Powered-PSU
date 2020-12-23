/* 
 * File:    errors.c
 * Author:  Manuel
 * Date:    18/04/2019
 * 
 * 
 */

#include "errors.h"
#include "hardware/inputs.h"
#include "graphics/GLCD.h"

#define _ERROR_ARRAY_SIZE   20

const char* ErrorTypeNames[4] = {
    "EEPROM",
    "INA230",
    "MAX5215",
    "MCP4716"};

static int errorCount = 0;
static int undisplayedErrorCount = 0;
static Error_t errorArray[_ERROR_ARRAY_SIZE];

//Add error is has different type from the errors already stored
void ERRORS_ThrowError(ErrorType_t type, char* description){
    Error_t error;
    bool newError = true;
    
    //Check if the error is new
    for(int i = 0; i < errorCount; i++){
        if(errorArray[i].type == type)
            newError = false;
    }
    
    if(newError && errorCount < _ERROR_ARRAY_SIZE){
        error.type = type;
        error.description = description;
        errorArray[errorCount++] = error;
        undisplayedErrorCount ++;
    }
}

//Clears all the errors
void ERRORS_ClearAll(void){
    errorCount = 0;
    undisplayedErrorCount = 0;
}

//Returns the specified error
Error_t ERRORS_GetError(int i){
    return errorArray[i];
}

//Returns the last error
Error_t ERRORS_GetLastError(void){
    return errorArray[errorCount - 1];
}

//Returns the number of errors
int ERRORS_GetErrorCount(void){
    return errorCount;
}

int ERRORS_GetUndisplayedErorrCont(void){
    return undisplayedErrorCount;
}

//Draws a message box with the last error
void ERRORS_DrawErrorMessageBox(void){
    Error_t error = errorArray[errorCount - undisplayedErrorCount];
    char buffer[26];
    
    GLCD_SetFont(_FONT_4x5);
    
    //Draw rectangle
    GLCD_FillRect(9, 9, _LCD_WIDTH - 8, _LCD_HEIGHT - 8, false);
    GLCD_HLine(11, 10, _LCD_WIDTH - 21, true);
    GLCD_HLine(11, _LCD_HEIGHT - 10, _LCD_WIDTH - 21, true);
    GLCD_HLine(12, _LCD_HEIGHT - 9, _LCD_WIDTH - 21, true);
    GLCD_VLine(10, 11, _LCD_HEIGHT - 21, true);
    GLCD_VLine(_LCD_WIDTH - 10, 11, _LCD_HEIGHT - 21, true);
    GLCD_VLine(_LCD_WIDTH - 9, 12, _LCD_HEIGHT - 21, true);
    
    //Print error type
    sprintf(buffer, "ERROR: %s", ErrorTypeNames[(int)error.type]);
    int len = strlen(buffer);
    int x = 10 + _LCD_HALF_W - (_FONT_4x5->maxX * len) / 2;
    GLCD_PrintString(x, 12, buffer);
    
    //Print Separator
    GLCD_HLine(20, 18, _LCD_WIDTH - 40, true);
    
    //Print error message
    int i = 0;
    int charCount = 0;
    int y = 22;
    const int lineWidth = 25;
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
            GLCD_PrintString(12, y, buffer);
            charCount = 0;
            y += 8;
        }
    } while(error.description[i++] != '\0');
    if(charCount > 0){
        //Print line
        buffer[charCount] = '\0';
        GLCD_PrintString(12, y, buffer);
    }
}

void ERRORS_ProcessInput(uint8_t buttons, int8_t encoder){
    //Process buttons
    switch(buttons){
        case _BUTTON_ENCH1:
            break;
        case _BUTTON_ENCH2:
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
            if(undisplayedErrorCount > 0)
                undisplayedErrorCount --;
            break;
        
        default:
            break;
    }
}
/* 
 * File:    menu_calibration.c
 * Author:  Manuel
 * Date:    15/12/2018
 * 
 * Comments: Calibration menu page
 */

#include "mcc.h"
#include "menu.h"
#include "hardware/inputs.h"
#include "hardware/power.h"
#include "hardware/battery.h"
#include "hardware/eeprom.h"
#include <stdio.h>

static void Initialize(void*);
static void Redraw(void);
static void ProcessInput(uint8_t buttons, int8_t encoder);
static void Tick(int64_t millis);
static void SaveCalibration(void);
static void RestoreCalibration(void);

static const char* title = "CALIBRATION";
MenuPage_t menu_calibration = {&Initialize, &Redraw, &ProcessInput, &Tick, true, &title, e_NORMAL};


#define _CH1_VOLTAGE_GAIN       0
#define _CH1_VOLTAGE_OFFSET     1
#define _CH1_CURRENT_GAIN       2
#define _CH1_CURRENT_OFFSET     3
#define _CH2_VOLTAGE_GAIN       4
#define _CH2_VOLTAGE_OFFSET     5
#define _CH2_CURRENT_GAIN       6
#define _CH2_CURRENT_OFFSET     7
#define _NUM_CALL_COEFFICENTS   8

float calValues[_NUM_CALL_COEFFICENTS];

static EditableValue_t calCoefficents[_NUM_CALL_COEFFICENTS] = 
{
    {e_FLOAT4,   "CH1  V-GAIN",    .valueFloat4 = {&_GLOBAL_VAR_CH(1).voltageGain,    0.7f, 1.1f, 0.0001f}},
    {e_FLOAT4,   "CH1  V-OFFS",    .valueFloat4 = {&_GLOBAL_VAR_CH(1).voltageOffset,  0.f,  1.f,  0.001f}},
    {e_FLOAT4,   "CH1  I -GAIN",    .valueFloat4 = {&_GLOBAL_VAR_CH(1).currentGain,   0.f,  1.f,  0.0001f}},
    {e_FLOAT4,   "CH1  I -OFFS",    .valueFloat4 = {&_GLOBAL_VAR_CH(1).currentOffset, 0.f,  1.f,  0.001f}},
    
    {e_FLOAT4,   "CH2 V-GAIN",    .valueFloat4 = {&_GLOBAL_VAR_CH(2).voltageGain,     0.7f, 1.1f, 0.0001f}},
    {e_FLOAT4,   "CH2 V-OFFS",    .valueFloat4 = {&_GLOBAL_VAR_CH(2).voltageOffset,   0.f,  1.f,  0.001f}},
    {e_FLOAT4,   "CH2 I -GAIN",    .valueFloat4 = {&_GLOBAL_VAR_CH(2).currentGain,    0.f,  1.f,  0.001f}},
    {e_FLOAT4,   "CH2 I -OFFS",    .valueFloat4 = {&_GLOBAL_VAR_CH(2).currentOffset,  0.f,  1.f,  0.001f}}
};
static uint8_t selectedItem;

static bool showSaveMessageBox = false;
static bool saveCalibration = false;

static void Initialize(void* arg){
    showSaveMessageBox  = false;
    saveCalibration     = false;
    
    //Read calibration data from eeprom 
    EEPROM_LoadCallPoints();
    
    //Load calibration data inside temp variables
    calValues[_CH1_VOLTAGE_GAIN]    = _GLOBAL_VAR_CH(1).voltageGain;
    calValues[_CH1_VOLTAGE_OFFSET]  = _GLOBAL_VAR_CH(1).voltageOffset;
    calValues[_CH1_CURRENT_GAIN]    = _GLOBAL_VAR_CH(1).currentGain;
    calValues[_CH1_CURRENT_OFFSET]  = _GLOBAL_VAR_CH(1).currentOffset;
    calValues[_CH2_VOLTAGE_GAIN]    = _GLOBAL_VAR_CH(2).voltageGain;
    calValues[_CH2_VOLTAGE_OFFSET]  = _GLOBAL_VAR_CH(2).voltageOffset;
    calValues[_CH2_CURRENT_GAIN]    = _GLOBAL_VAR_CH(2).currentGain;
    calValues[_CH2_CURRENT_OFFSET]  = _GLOBAL_VAR_CH(2).currentOffset;
    
    menu_battery.outOfDate = true;
}

static void Redraw(void){
    const uint8_t offsetY = 10;
    
    GLCD_SetFont(_FONT_4x5);

    for(uint8_t i = 0; i < _NUM_CALL_COEFFICENTS; i++){
        uint8_t y = i * 6 + offsetY;

        GLCD_PrintString(10, y, calCoefficents[i].name);
        EVAL_Print(80, y, &calCoefficents[i]);

        //Draw arrow near selected item
        if(i == selectedItem){
            GLCD_VLine(2, y, 5, true);
            GLCD_VLine(3, y + 1, 3, true);
            GLCD_Pixel(4, y + 2, true);
        }
    }

    //Show message box for confirmation before saving data
    if(showSaveMessageBox){
        //Draw rectangle
        GLCD_FillRect(9, 9, _LCD_WIDTH - 9, _LCD_HEIGHT - 9, false);
        GLCD_Rect(10, 10, _LCD_WIDTH - 10, _LCD_HEIGHT - 10, true);
        
        //Draw text
        GLCD_PrintString(25, 22, "WOULD YOU LIKE TO");
        GLCD_PrintString(15, 29, "UPDATE CALIBRATION DATA");
        
        //Draw buttons
        GLCD_HLine(20, 40, 20, true);
        GLCD_HLine(20, 50, 20, true);
        GLCD_VLine(19, 41, 9, true);
        GLCD_VLine(40, 41, 9, true);
        GLCD_FillRect(20, 41, 39, 49, saveCalibration == true);
        GLCD_SetTextModeInverted(saveCalibration == true);
        GLCD_PrintString(25, 43, "YES");
        
        GLCD_HLine(80, 40, 20, true);
        GLCD_HLine(80, 50, 20, true);
        GLCD_VLine(79, 41, 9, true);
        GLCD_VLine(100, 41, 9, true);
        GLCD_FillRect(80, 41, 99, 49, saveCalibration == false);
        GLCD_SetTextModeInverted(saveCalibration == false);
        GLCD_PrintString(85, 43, "NO");
        
        GLCD_SetTextModeInverted(false);
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
            if(showSaveMessageBox == false)
                EVAL_AddToValue(&calCoefficents[selectedItem], -1.0f);
            else
                saveCalibration = true;
            break;
            
        case _BUTTON_RIGHT:
            if(showSaveMessageBox == false)
                EVAL_AddToValue(&calCoefficents[selectedItem], 1.0f);
            else
                saveCalibration = false;
            break;
            
        case _BUTTON_UP_V:
            if(selectedItem > 0)
                selectedItem --;
            break;
            
        case _BUTTON_DW_I:
            if(selectedItem < _NUM_CALL_COEFFICENTS - 1)
                selectedItem ++;
            break;
            
        case _BUTTON_MENU:
            if(showSaveMessageBox == false){
                showSaveMessageBox = true;
            }
            else{
                if(saveCalibration)
                    SaveCalibration();
                MENU_Pop();
            }
            break;
        
        case _BUTTON_ENC_PB:
            if(showSaveMessageBox == true){
                if(saveCalibration)
                    SaveCalibration();
                else
                    RestoreCalibration();
                MENU_Pop();
            }
            break;
            
        default:
            break;
    }
    
    //Process encoder
    if(encoder){
        if(encoder > 2 || encoder < -2)
            EVAL_AddToValue(&calCoefficents[selectedItem], (float)encoder * 100);
        else if(encoder > 1 || encoder < -1)
            EVAL_AddToValue(&calCoefficents[selectedItem], (float)encoder * 10);
        else
            EVAL_AddToValue(&calCoefficents[selectedItem], (float)encoder);
    }
    
    menu_calibration.outOfDate = true;
}

static void Tick(int64_t millis){
    //menu_battery.outOfDate = true;
}

static void SaveCalibration(void){
    //Save calibration data to EEprom
    EEPROM_StoreCallPoints();
}

static void RestoreCalibration(void){
    //Restore calibration
    _GLOBAL_VAR_CH(1).voltageGain   = calValues[_CH1_VOLTAGE_GAIN];
    _GLOBAL_VAR_CH(1).voltageOffset = calValues[_CH1_VOLTAGE_OFFSET];
    _GLOBAL_VAR_CH(1).currentGain   = calValues[_CH1_CURRENT_GAIN];
    _GLOBAL_VAR_CH(1).currentOffset = calValues[_CH1_CURRENT_OFFSET];
    
    _GLOBAL_VAR_CH(2).voltageGain   = calValues[_CH2_VOLTAGE_GAIN];
    _GLOBAL_VAR_CH(2).voltageOffset = calValues[_CH2_VOLTAGE_OFFSET];
    _GLOBAL_VAR_CH(2).currentGain   = calValues[_CH2_CURRENT_GAIN];
    _GLOBAL_VAR_CH(2).currentOffset = calValues[_CH2_CURRENT_OFFSET];
}
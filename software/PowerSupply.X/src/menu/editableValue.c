/* 
 * File:    editableValue.c
 * Author:  Manuel
 * Date:    28/10/2018
 * 
 * Comments:
 */
#include "editableValue.h"
#include "graphics/GLCD.h"

static float EVAL_GetValueFloat(EditableValue_t* editableValue);
static float EVAL_GetMaxFloat(EditableValue_t* editableValue);
static float EVAL_GetMinFloat(EditableValue_t* editableValue);
static float EVAL_GetStepFloat(EditableValue_t* editableValue);
static void  EVAL_SetValue(EditableValue_t* editableValue, float f);


//Adds f to the editable value and makes sur it stays within the maximum and minimum values
void EVAL_AddToValue(EditableValue_t* editableValue, float f){
    //Calculate new value
    float max  = EVAL_GetMaxFloat(editableValue);
    float min  = EVAL_GetMinFloat(editableValue);
    float step = EVAL_GetStepFloat(editableValue);
    float newValue = EVAL_GetValueFloat(editableValue) + f * step;
    
    //Check if newValue is within min and max
    if(newValue > max)
        EVAL_SetValue(editableValue, max);
    else if(newValue < min)
        EVAL_SetValue(editableValue, min);
    else
        EVAL_SetValue(editableValue, newValue);
}

//Prints the editable value
void EVAL_Print(int x, int y, EditableValue_t* editableValue){
    switch(editableValue->type){
        case e_FLOAT:       GLCD_printNumF(x, y, *editableValue->valueFloat.value,  5, 2, '.', ' ');  break;
        case e_FLOAT4:      GLCD_printNumF(x, y, *editableValue->valueFloat.value,  5, 4, '.', ' ');  break;
        case e_UINT8:       GLCD_PrintNumI(x, y, *editableValue->valueUint8.value,  3, ' ');          break;
        case e_INT8:        GLCD_PrintNumI(x, y, *editableValue->valueInt8.value,   3, ' ');          break;
        case e_UINT16:      GLCD_PrintNumI(x, y, *editableValue->valueUint16.value, 3, ' ');          break;
        case e_INT16:       GLCD_PrintNumI(x, y, *editableValue->valueInt16.value,  3, ' ');          break;
        case e_MENU_PAGE:   GLCD_PrintString(x, y, editableValue->menuPage.description);              break;
    }
}

static float EVAL_GetValueFloat(EditableValue_t* editableValue){
    switch(editableValue->type){
        case e_FLOAT:   return (float)(*editableValue->valueFloat.value);
        case e_FLOAT4:  return (float)(*editableValue->valueFloat.value);
        case e_UINT8:   return (float)(*editableValue->valueUint8.value);
        case e_INT8:    return (float)(*editableValue->valueInt8.value);
        case e_UINT16:  return (float)(*editableValue->valueUint16.value);
        case e_INT16:   return (float)(*editableValue->valueInt16.value);
        default:        return 0.0f;
    }
}

static float EVAL_GetMaxFloat(EditableValue_t* editableValue){
    switch(editableValue->type){
        case e_FLOAT:   return (float)(editableValue->valueFloat.max);
        case e_FLOAT4:  return (float)(editableValue->valueFloat.max);
        case e_UINT8:   return (float)(editableValue->valueUint8.max);
        case e_INT8:    return (float)(editableValue->valueInt8.max);
        case e_UINT16:  return (float)(editableValue->valueUint16.max);
        case e_INT16:   return (float)(editableValue->valueInt16.max);
        default:        return 0.0f;
    }
}

static float EVAL_GetMinFloat(EditableValue_t* editableValue){
    switch(editableValue->type){
        case e_FLOAT:   return (float)(editableValue->valueFloat.min);
        case e_FLOAT4:  return (float)(editableValue->valueFloat.min);
        case e_UINT8:   return (float)(editableValue->valueUint8.min);
        case e_INT8:    return (float)(editableValue->valueInt8.min);
        case e_UINT16:  return (float)(editableValue->valueUint16.min);
        case e_INT16:   return (float)(editableValue->valueInt16.min);
        default:        return 0.0f;
    }
}

static float EVAL_GetStepFloat(EditableValue_t* editableValue){
    switch(editableValue->type){
        case e_FLOAT:   return (float)(editableValue->valueFloat.step);
        case e_FLOAT4:  return (float)(editableValue->valueFloat.step);
        case e_UINT8:   return (float)(editableValue->valueUint8.step);
        case e_INT8:    return (float)(editableValue->valueInt8.step);
        case e_UINT16:  return (float)(editableValue->valueUint16.step);
        case e_INT16:   return (float)(editableValue->valueInt16.step);
        default:        return 0.0f;
    }
}

static void EVAL_SetValue(EditableValue_t* editableValue, float f){
    switch(editableValue->type){
        case e_FLOAT:   (*editableValue->valueFloat.value)  = (float)   f;   break;
        case e_FLOAT4:  (*editableValue->valueFloat.value)  = (float)   f;   break;
        case e_UINT8:   (*editableValue->valueUint8.value)  = (uint8_t) f;   break;
        case e_INT8:    (*editableValue->valueInt8.value)   = (int8_t)  f;   break;
        case e_UINT16:  (*editableValue->valueUint8.value)  = (uint16_t)f;   break;
        case e_INT16:   (*editableValue->valueInt16.value)  = (int16_t) f;   break;
        default:
            break;
    }
}
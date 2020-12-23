/* 
 * File:    editableValue.h
 * Author:  Manuel
 * Date:    28/10/2018
 * 
 * Comments:
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _SRC_MENU_EDITABLEVALUE_H
#define	_SRC_MENU_EDITABLEVALUE_H

#include <xc.h>
#include "stdbool.h"
#include "stdint.h"

typedef enum {e_FLOAT, e_FLOAT4, e_UINT8, e_INT8, e_UINT16, e_INT16, e_MENU_PAGE} ValueType_t;

typedef struct{
    float*  value;
    float   min;
    float   max;
    float   step;
} EditableValueFloat_t;

typedef struct{
    float*  value;
    float   min;
    float   max;
    float   step;
} EditableValueFloat4_t;

typedef struct{
    uint8_t*  value;
    uint8_t   min;
    uint8_t   max;
    uint8_t   step;
} EditableValueUint8_t;

typedef struct{
    int8_t*  value;
    int8_t   min;
    int8_t   max;
    int8_t   step;
} EditableValueInt8_t;

typedef struct{
    uint16_t*  value;
    uint16_t   min;
    uint16_t   max;
    uint16_t   step;
} EditableValueUint16_t;

typedef struct{
    int16_t*  value;
    int16_t   min;
    int16_t   max;
    int16_t   step;
} EditableValueInt16_t;

typedef struct{
    uint8_t*    menuPage;
    const char* description;
} EditableValueMenuPage_t;

typedef struct{
    ValueType_t type;
    const char* name;
    union{
        EditableValueFloat_t    valueFloat;
        EditableValueFloat4_t   valueFloat4;
        EditableValueUint8_t    valueUint8;
        EditableValueInt8_t     valueInt8;
        EditableValueUint16_t   valueUint16;
        EditableValueInt16_t    valueInt16;
        EditableValueMenuPage_t menuPage;
    };
} EditableValue_t;

//Adds f to the editable value and makes sure it stays within the maximum and minimum values
void EVAL_AddToValue(EditableValue_t* editableValue, float f);

//Prints the editable value
void EVAL_Print(int x, int y, EditableValue_t* editableValue);

#endif	/* _SRC_MENU_EDITABLEVALUE_H */


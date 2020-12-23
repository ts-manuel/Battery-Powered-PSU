/* 
 * File:    errors.h
 * Author:  Manuel
 * Date:    18/04/2019
 * 
 * 
 */


#ifndef _SRC_DEBUG_ERRORS_H
#define	_SRC_DEBUG_ERRORS_H

#include <xc.h>
#include <mcc.h>

typedef enum{
    e_EEPROM,
    e_INA230,
    e_MAX5215,
    e_MCP4716
} ErrorType_t;

extern const char* ErrorTypeNames[4];

typedef struct{
    ErrorType_t type;           //Error  type
    char*       description;    //Error description
} Error_t;

void ERRORS_ThrowError(ErrorType_t type, char* description);

void ERRORS_ClearAll(void);

Error_t ERRORS_GetError(int i);

Error_t ERRORS_GetLastError(void);

int ERRORS_GetErrorCount(void);

int ERRORS_GetUndisplayedErorrCont(void);

void ERRORS_DrawErrorMessageBox(void);

void ERRORS_ProcessInput(uint8_t buttons, int8_t encoder);

#endif	/* _SRC_DEBUG_ERRORS_H */


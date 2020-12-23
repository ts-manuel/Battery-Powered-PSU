/* 
 * File:    log.h
 * Author:  Manuel
 * Date:    15/01/2019
 * 
 * Comments: 
 */

#ifndef _SRC_DEBUG_LOG_H
#define	_SRC_DEBUG_LOG_H

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

//If defined as true the corresponding messages are printed
#define _LOG_PRINT_INFO     true
#define _LOG_PRINT_ERROR    true
#define _LOG_PRINT_FATAL    true


//Macro definition
#if _LOG_PRINT_INFO == true
    #define LOG_PRINT_INFO(s, ...) { if (LOG_IsInfoEnabled()) { printf("INFO: "); printf(s, __VA_ARGS__);} }
#else
    #define LOG_PRINT_INFO
#endif

#if _LOG_PRINT_ERROR == true
    #define LOG_PRINT_ERROR(s, ...) { if(LOG_IsErrorEnabled()) { printf("ERROR: "); printf(s, __VA_ARGS__);} }
#else
    #define LOG_PRINT_ERROR
#endif

#if _LOG_PRINT_FATAL == true
    #define LOG_PRINT_FATAL(s, ...) { if(LOG_IsFatalEnabled()) { printf("FATAL: "); printf(s, __VA_ARGS__);} }
#else
    #define LOG_PRINT_FATAL
#endif

bool LOG_IsInfoEnabled(void);
bool LOG_IsErrorEnabled(void);
bool LOG_IsFatalEnabled(void);

void LOG_SetPrintInfo(bool b);
void LOG_SetPrintError(bool b);
void LOG_SetPrintFatal(bool b);


#endif	/* _SRC_DEBUG_LOG_H */


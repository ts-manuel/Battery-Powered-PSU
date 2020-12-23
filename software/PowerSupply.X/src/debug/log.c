/* 
 * File:    log.h
 * Author:  Manuel
 * Date:    15/01/2019
 * 
 * Comments: 
 */

#include "log.h"
#include <stdio.h>

static bool logPrintInfo  = true;
static bool logPrintError = true;
static bool logPrintFatal = true;


bool LOG_IsInfoEnabled(void){
#if _LOG_PRINT_INFO == true
    return logPrintInfo;
#else
    return false;
#endif
}

bool LOG_IsErrorEnabled(void){
#if _LOG_PRINT_ERROR == true
    return logPrintError;
#else
    return false;
#endif
}

bool LOG_IsFatalEnabled(void){
#if _LOG_PRINT_FATAL == true
    return logPrintFatal;
#else
    return false;
#endif
}

void LOG_SetPrintInfo(bool b){
    logPrintInfo = b;
}

void LOG_SetPrintError(bool b){
    logPrintError = b;
}

void LOG_SetPrintFatal(bool b){
    logPrintFatal = b;
}
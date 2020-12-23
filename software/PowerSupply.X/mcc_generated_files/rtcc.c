
/**
  RTCC Generated Driver API Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    rtcc.c

  @Summary:
    This is the generated header file for the RTCC driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description:
    This header file provides APIs for driver for RTCC.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.95-b-SNAPSHOT
        Device            :  PIC24FJ1024GB610
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36
        MPLAB 	          :  MPLAB X v5.10
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/


/**
 Section: Included Files
*/

#include <xc.h>
#include "rtcc.h"

/**
// Section: Static function
*/

static void RTCC_Lock(void);
static bool rtccTimeInitialized;
static bool RTCCTimeInitialized(void);
static uint8_t ConvertHexToBCD(uint8_t hexvalue);
static uint8_t ConvertBCDToHex(uint8_t bcdvalue);

/**
// Section: Driver Interface Function Definitions
*/

void RTCC_Initialize(void)
{

   RTCCON1Lbits.RTCEN = 0;
   
   __builtin_write_RTCC_WRLOCK();
   
   
   if(!RTCCTimeInitialized())
   {
       // set 2019-03-14 14-06-29
       DATEH = 0x1903;    // Year/Month
       DATEL = 0x1404;    // Date/Wday
       TIMEH = 0x1406;    // hours/minutes
       TIMEL = 0x2900;    // seconds
   }
   // set 2019-03-14 14-06-29
   ALMDATEH = 0x1903;    // Year/Month
   ALMDATEL = 0x1404;    // Date/Wday
   ALMTIMEH = 0x1406;    // hours/minutes
   ALMTIMEL = 0x2900;    // seconds
   // AMASK Every Second; ALMRPT 0; CHIME disabled; ALRMEN enabled; 
   RTCCON1H = 0x8100;

   // PWCPS 1:1; PS 1:1; CLKSEL SOSC; FDIV 8; 
   RTCCON2L = 0x4000;
   // DIV 16383; 
   RTCCON2H = 0x3FFF;
   // PWCSTAB 0; PWCSAMP 0; 
   RTCCON3L = 0x00;

   // RTCEN enabled; OUTSEL Alarm Event; PWCPOE disabled; PWCEN disabled; WRLOCK disabled; PWCPOL disabled; TSAEN disabled; RTCOE disabled; 
   RTCCON1L = 0x8000; 
   
   // Enable RTCC, clear RTCWREN 
   RTCCON1Lbits.RTCEN = 1; 
   RTCC_Lock();

}

static void RTCC_Lock(void)
{
    __asm__ volatile("DISI #6");
    __asm__ volatile("MOV #NVMKEY, W1");
    __asm__ volatile("MOV #0x55, W2");
    __asm__ volatile("MOV W2, [W1]");
    __asm__ volatile("MOV #0xAA, W3");
    __asm__ volatile("MOV W3, [W1]");
    __asm__ volatile("BSET RTCCON1L, #11");
}

bool RTCC_TimeGet(struct tm *currentTime)
{
    uint16_t register_value;
    if(RTCSTATLbits.SYNC){
        return false;
    }
 
    register_value = DATEH;
    currentTime->tm_year = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    currentTime->tm_mon = ConvertBCDToHex(register_value & 0x00FF);
    
    register_value = DATEL;
    currentTime->tm_mday = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    currentTime->tm_wday = ConvertBCDToHex(register_value & 0x00FF);
    
    register_value = TIMEH;
    currentTime->tm_hour = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    currentTime->tm_min = ConvertBCDToHex(register_value & 0x00FF);
    
    register_value = TIMEL;
    currentTime->tm_sec = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    
    return true;
}

void RTCC_TimeSet(struct tm *initialTime)
{

  __builtin_write_RTCC_WRLOCK();

   RTCCON1Lbits.RTCEN = 0;
   

   // set RTCC initial time
   DATEH = (ConvertHexToBCD(initialTime->tm_year) << 8) | ConvertHexToBCD(initialTime->tm_mon) ;  // YEAR/MONTH-1
   DATEL = (ConvertHexToBCD(initialTime->tm_mday) << 8) | ConvertHexToBCD(initialTime->tm_wday) ;  // /DAY-1/WEEKDAY
   TIMEH = (ConvertHexToBCD(initialTime->tm_hour) << 8)  | ConvertHexToBCD(initialTime->tm_min); // /HOURS/MINUTES
   TIMEL = (ConvertHexToBCD(initialTime->tm_sec) << 8) ;   // SECOND
           
   // Enable RTCC, clear RTCWREN         
   RTCCON1Lbits.RTCEN = 1;  
   RTCC_Lock();

}

bool RTCC_BCDTimeGet(bcdTime_t *currentTime)
{
    uint16_t register_value;
    if(RTCSTATLbits.SYNC){
        return false;
    }

    register_value = DATEH;
    currentTime->tm_year = (register_value & 0xFF00) >> 8;
    currentTime->tm_mon = register_value & 0x00FF;
    
    register_value = DATEL;
    currentTime->tm_mday = (register_value & 0xFF00) >> 8;
    currentTime->tm_wday = register_value & 0x00FF;
    
    register_value = TIMEH;
    currentTime->tm_hour = (register_value & 0xFF00) >> 8;
    currentTime->tm_min = register_value & 0x00FF;
   
    register_value = TIMEL;
    currentTime->tm_sec = (register_value & 0xFF00) >> 8;

    return true;
}

void RTCC_BCDTimeSet(bcdTime_t *initialTime)
{

   __builtin_write_RTCC_WRLOCK();

   RTCCON1Lbits.RTCEN = 0;
   

   // set RTCC initial time
   DATEH = (initialTime->tm_year << 8) | (initialTime->tm_mon) ;  // YEAR/MONTH-1
   DATEL = (initialTime->tm_mday << 8) | (initialTime->tm_wday) ;  // /DAY-1/WEEKDAY
   TIMEH = (initialTime->tm_hour << 8) | (initialTime->tm_min); // /HOURS/MINUTES
   TIMEL = (initialTime->tm_sec << 8);   // SECONDS   
           
   // Enable RTCC, clear RTCWREN         
   RTCCON1Lbits.RTCEN = 1;  
   RTCC_Lock();

}

/**
 This function implements RTCC_TimeReset.This function is used to
 used by application to reset the RTCC value and reinitialize RTCC value.
*/
void RTCC_TimeReset(bool reset)
{
    rtccTimeInitialized = reset;
}

static bool RTCCTimeInitialized(void)
{
    return(rtccTimeInitialized);
}

void RTCC_TimestampAEventManualSet(void)
{
    RTCSTATLbits.TSAEVT = 1;
}

bool RTCC_TimestampADataGet(struct tm *currentTime)
{
    uint16_t register_value;
    if(!RTCSTATLbits.TSAEVT){
        return false;
    }
  
    register_value = TSADATEH;
    currentTime->tm_year = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    currentTime->tm_mon = ConvertBCDToHex(register_value & 0x00FF);
    
    register_value = TSADATEL;
    currentTime->tm_mday = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    currentTime->tm_wday = ConvertBCDToHex(register_value & 0x00FF);
    
    register_value = TSATIMEH;
    currentTime->tm_hour = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    currentTime->tm_min = ConvertBCDToHex(register_value & 0x00FF);
    
    register_value = TSATIMEL;
    currentTime->tm_sec = ConvertBCDToHex((register_value & 0xFF00) >> 8);
   
    RTCSTATLbits.TSAEVT = 0;

    return true;
}



bool RTCC_TimestampA_BCDDataGet(bcdTime_t *currentTime)
{
    uint16_t register_value;
    if(!RTCSTATLbits.TSAEVT){
        return false;
    }
  
    register_value = TSADATEH;
    currentTime->tm_year = (register_value & 0xFF00) >> 8;
    currentTime->tm_mon = (register_value & 0x00FF);
    
    register_value = TSADATEL;
    currentTime->tm_mday = (register_value & 0xFF00) >> 8;
    currentTime->tm_wday = (register_value & 0x00FF);
    
    register_value = TSATIMEH;
    currentTime->tm_hour = (register_value & 0xFF00) >> 8;
    currentTime->tm_min = (register_value & 0x00FF);
    
    register_value = TSATIMEL;
    currentTime->tm_sec = (register_value & 0xFF00) >> 8;
   
    RTCSTATLbits.TSAEVT = 0;

    return true;
}



static uint8_t ConvertHexToBCD(uint8_t hexvalue)
{
    uint8_t bcdvalue;
    bcdvalue = (hexvalue / 10) << 4;
    bcdvalue = bcdvalue | (hexvalue % 10);
    return (bcdvalue);
}

static uint8_t ConvertBCDToHex(uint8_t bcdvalue)
{
    uint8_t hexvalue;
    hexvalue = (((bcdvalue & 0xF0) >> 4)* 10) + (bcdvalue & 0x0F);
    return hexvalue;
}

void __attribute__ ((weak)) RTCC_CallBack(void)
{
    // Add your custom callback code here
}

/* Function:
    bool RTCC_Task(void)

  Summary:
    Status function which returns the RTCC interrupt flag status

  Description:
    This is the status function for the RTCC peripheral. 
*/
bool RTCC_Task(void)
{
    bool status;
    status = IFS3bits.RTCIF;
    if( IFS3bits.RTCIF)
    {
		// RTCC callback function 
		RTCC_CallBack();
		
		IFS3bits.RTCIF = false;
    }
    return status;
}
/**
 End of File
*/

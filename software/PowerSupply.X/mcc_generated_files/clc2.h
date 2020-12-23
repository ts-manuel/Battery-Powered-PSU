/**
  CLC2 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    clc2.h

  @Summary
    This is the generated header file for the CLC2 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides APIs for driver for CLC2.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.95-b-SNAPSHOT
        Device            :  PIC24FJ1024GB610
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36
        MPLAB             :  MPLAB X v5.10
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

#ifndef _CLC2_H
#define _CLC2_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: CLC2 APIs
*/

/**
  @Summary
    Initializes the CLC2

  @Description
    This routine configures the CLC2 specific control registers

  @Preconditions
    None

  @Returns
    None

  @Param
    None

  @Comment
    

  @Example
    <code>
    CLC2_Initialize();
    </code>
*/
void CLC2_Initialize(void);

/**
  @Summary
    Callback for CLC2.

  @Description
    This routine is callback for CLC2

  @Param
    None.

  @Returns
    None
 
  @Example 
	Refer to CLC2_Initialize(); for an example
*/
void CLC2_CallBack(void);

/**
  @Summary
    Polled implementation

  @Description
    This routine is used to implement the tasks for polled implementations.
  
  @Preconditions
    CLC2_Initialize() function should have been 
    called before calling this function.
 
  @Returns 
    None
 
  @Param
    None
 
  @Example
    Refer to CLC2_Initialize(); for an example
    
*/
void CLC2_Tasks(void);

/**
  @Summary
    Returns output pin status of the CLC module.

  @Description
    This routine returns output pin status of the CLC module.

  @Param
    None.

  @Returns
    Output pin status
 
  @Example 
    <code>
    bool outputStatus;
    outputStatus = CLC2_OutputStatusGet();
    </code>
*/

bool CLC2_OutputStatusGet(void);

/******************************************************************************
*                                                                             
*    Function:			CLC2_Enable
*    Description:       Enables the CLC module                                     
*      
*	 Parameters:		None                                       
*    Return Value:      None
******************************************************************************/
inline static void CLC2_Enable(void)
{
    CLC2CONLbits.LCEN = 1;
}

/******************************************************************************
*                                                                             
*    Function:			CLC2_Disable
*    Description:       Disables the CLC module                                     
*      
*	 Parameters:		None                                       
*    Return Value:      None
******************************************************************************/
inline static void CLC2_Disable(void)
{
    CLC2CONLbits.LCEN = 0;
}

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  // _CLC2_H
/**
 End of File
*/


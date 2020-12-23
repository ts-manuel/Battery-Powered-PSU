/**
  CLC2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    clc2.c

  @Summary
    This is the generated driver implementation file for the CLC2 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides implementations for driver APIs for CLC2.
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

/**
  Section: Included Files
*/

#include "clc2.h"

/**
  Section: CLC2 APIs
*/

void CLC2_Initialize(void)
{
    // Set the CLC2 to the options selected in the User Interface

	CLC2CONL = 0x8084 & ~(0x8000);

    CLC2CONH = 0x00;

    CLC2SELL = 0x16;

    CLC2GLSL = 0x802;

    CLC2GLSH = 0x00;

	
	CLC2_Enable();	
}

void __attribute__ ((weak)) CLC2_CallBack(void)
{
    // Add your custom callback code here
}

void CLC2_Tasks ( void )
{
	if(IFS6bits.CLC2IF)
	{
		// CLC2 callback function 
		CLC2_CallBack();
		
		// clear the CLC2 interrupt flag
		IFS6bits.CLC2IF = 0;
	}
}

bool CLC2_OutputStatusGet(void)
{
    return(CLC2CONLbits.LCOUT);

}
/**
 End of File
*/

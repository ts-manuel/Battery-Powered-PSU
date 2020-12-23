/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.c

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
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
    Section: Includes
*/

#include <xc.h>
#include <stdio.h>
#include "pin_manager.h"

/**
 Section: File specific functions
*/
void (*CN_InterruptHandler)(void) = NULL;

/**
 Section: Driver Interface Function Definitions
*/
void PIN_MANAGER_Initialize (void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x001C;
    LATC = 0x0000;
    LATD = 0x0000;
    LATE = 0x0000;
    LATF = 0x0000;
    LATG = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x06C3;
    TRISB = 0x7EA3;
    TRISC = 0xB01C;
    TRISD = 0xFECF;
    TRISE = 0x02FF;
    TRISF = 0x3193;
    TRISG = 0x73CF;

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    IOCPDA = 0x06C2;
    IOCPDB = 0x1C00;
    IOCPDC = 0x0000;
    IOCPDD = 0xF7CF;
    IOCPDE = 0x0000;
    IOCPDF = 0x3193;
    IOCPDG = 0x700F;
    IOCPUA = 0x0000;
    IOCPUB = 0x6283;
    IOCPUC = 0x0000;
    IOCPUD = 0x0000;
    IOCPUE = 0x0000;
    IOCPUF = 0x0000;
    IOCPUG = 0x0000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0xC000;
    ODCB = 0x0000;
    ODCC = 0x0000;
    ODCD = 0x0000;
    ODCE = 0x0000;
    ODCF = 0x0000;
    ODCG = 0x0000;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSA = 0x0000;
    ANSB = 0x0000;
    ANSC = 0x0000;
    ANSD = 0x0000;
    ANSE = 0x0000;
    ANSG = 0x0000;


    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS

    RPINR0bits.INT1R = 0x0027;    //RC2->EXT_INT:INT1
    RPOR6bits.RP13R = 0x0003;    //RB2->UART1:U1TX
    RPINR19bits.U2RXR = 0x000E;    //RB14->UART2:U2RX
    RPOR15bits.RP30R = 0x001D;    //RF2->CLC1:CLC1OUT
    RPOR8bits.RP17R = 0x001E;    //RF5->CLC2:CLC2OUT
    RPOR8bits.RP16R = 0x001D;    //RF3->CLC1:CLC1OUT
    RPOR1bits.RP2R = 0x0005;    //RD8->UART2:U2TX

    __builtin_write_OSCCONL(OSCCON | 0x40); // lock PPS

    /****************************************************************************
     * Interrupt On Change: negative
     ***************************************************************************/
    IOCNAbits.IOCNA0 = 1;    //Pin : RA0
    IOCNBbits.IOCNB5 = 1;    //Pin : RB5
    IOCNCbits.IOCNC3 = 1;    //Pin : RC3
    IOCNCbits.IOCNC4 = 1;    //Pin : RC4
    IOCNDbits.IOCND11 = 1;    //Pin : RD11
    IOCNEbits.IOCNE9 = 1;    //Pin : RE9
    IOCNGbits.IOCNG6 = 1;    //Pin : RG6
    IOCNGbits.IOCNG7 = 1;    //Pin : RG7
    IOCNGbits.IOCNG8 = 1;    //Pin : RG8
    IOCNGbits.IOCNG9 = 1;    //Pin : RG9
    /****************************************************************************
     * Interrupt On Change: config
     ***************************************************************************/
    PADCONbits.IOCON = 1;    //Config for PORTB

    /****************************************************************************
     * Interrupt On Change: Interrupt Enable
     ***************************************************************************/
    IFS1bits.IOCIF = 0; //Clear IOCI interrupt flag
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void CN_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    CN_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

/* Interrupt service routine for the IOCI interrupt. */
/*void __attribute__ (( interrupt, no_auto_psv )) _IOCInterrupt ( void )
{
    if(IFS1bits.IOCIF == 1)
    {
        // Clear the flag
        IFS1bits.IOCIF = 0;
        if(CN_InterruptHandler) 
        { 
            CN_InterruptHandler(); 
    }
    }
}*/

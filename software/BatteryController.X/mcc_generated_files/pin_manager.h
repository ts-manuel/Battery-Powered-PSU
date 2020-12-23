/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC16LF18346
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set IO_3V3_ENABLE aliases
#define IO_3V3_ENABLE_TRIS                 TRISAbits.TRISA1
#define IO_3V3_ENABLE_LAT                  LATAbits.LATA1
#define IO_3V3_ENABLE_PORT                 PORTAbits.RA1
#define IO_3V3_ENABLE_WPU                  WPUAbits.WPUA1
#define IO_3V3_ENABLE_OD                   ODCONAbits.ODCA1
#define IO_3V3_ENABLE_ANS                  ANSELAbits.ANSA1
#define IO_3V3_ENABLE_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_3V3_ENABLE_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_3V3_ENABLE_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_3V3_ENABLE_GetValue()           PORTAbits.RA1
#define IO_3V3_ENABLE_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_3V3_ENABLE_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_3V3_ENABLE_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define IO_3V3_ENABLE_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define IO_3V3_ENABLE_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define IO_3V3_ENABLE_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define IO_3V3_ENABLE_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define IO_3V3_ENABLE_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set IO_EN_I2C aliases
#define IO_EN_I2C_TRIS                 TRISAbits.TRISA4
#define IO_EN_I2C_LAT                  LATAbits.LATA4
#define IO_EN_I2C_PORT                 PORTAbits.RA4
#define IO_EN_I2C_WPU                  WPUAbits.WPUA4
#define IO_EN_I2C_OD                   ODCONAbits.ODCA4
#define IO_EN_I2C_ANS                  ANSELAbits.ANSA4
#define IO_EN_I2C_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define IO_EN_I2C_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define IO_EN_I2C_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define IO_EN_I2C_GetValue()           PORTAbits.RA4
#define IO_EN_I2C_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define IO_EN_I2C_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define IO_EN_I2C_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define IO_EN_I2C_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define IO_EN_I2C_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define IO_EN_I2C_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define IO_EN_I2C_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define IO_EN_I2C_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set IO_CHG_OK aliases
#define IO_CHG_OK_TRIS                 TRISAbits.TRISA5
#define IO_CHG_OK_LAT                  LATAbits.LATA5
#define IO_CHG_OK_PORT                 PORTAbits.RA5
#define IO_CHG_OK_WPU                  WPUAbits.WPUA5
#define IO_CHG_OK_OD                   ODCONAbits.ODCA5
#define IO_CHG_OK_ANS                  ANSELAbits.ANSA5
#define IO_CHG_OK_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IO_CHG_OK_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IO_CHG_OK_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IO_CHG_OK_GetValue()           PORTAbits.RA5
#define IO_CHG_OK_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IO_CHG_OK_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IO_CHG_OK_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define IO_CHG_OK_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define IO_CHG_OK_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define IO_CHG_OK_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define IO_CHG_OK_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define IO_CHG_OK_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set I2C_SCL aliases
#define I2C_SCL_TRIS                 TRISBbits.TRISB4
#define I2C_SCL_LAT                  LATBbits.LATB4
#define I2C_SCL_PORT                 PORTBbits.RB4
#define I2C_SCL_WPU                  WPUBbits.WPUB4
#define I2C_SCL_OD                   ODCONBbits.ODCB4
#define I2C_SCL_ANS                  ANSELBbits.ANSB4
#define I2C_SCL_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define I2C_SCL_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define I2C_SCL_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define I2C_SCL_GetValue()           PORTBbits.RB4
#define I2C_SCL_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define I2C_SCL_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define I2C_SCL_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define I2C_SCL_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define I2C_SCL_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define I2C_SCL_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define I2C_SCL_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define I2C_SCL_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set I2C_SDA aliases
#define I2C_SDA_TRIS                 TRISBbits.TRISB5
#define I2C_SDA_LAT                  LATBbits.LATB5
#define I2C_SDA_PORT                 PORTBbits.RB5
#define I2C_SDA_WPU                  WPUBbits.WPUB5
#define I2C_SDA_OD                   ODCONBbits.ODCB5
#define I2C_SDA_ANS                  ANSELBbits.ANSB5
#define I2C_SDA_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define I2C_SDA_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define I2C_SDA_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define I2C_SDA_GetValue()           PORTBbits.RB5
#define I2C_SDA_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define I2C_SDA_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define I2C_SDA_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define I2C_SDA_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define I2C_SDA_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define I2C_SDA_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define I2C_SDA_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define I2C_SDA_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_BMS_ALLERT aliases
#define IO_BMS_ALLERT_TRIS                 TRISBbits.TRISB6
#define IO_BMS_ALLERT_LAT                  LATBbits.LATB6
#define IO_BMS_ALLERT_PORT                 PORTBbits.RB6
#define IO_BMS_ALLERT_WPU                  WPUBbits.WPUB6
#define IO_BMS_ALLERT_OD                   ODCONBbits.ODCB6
#define IO_BMS_ALLERT_ANS                  ANSELBbits.ANSB6
#define IO_BMS_ALLERT_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_BMS_ALLERT_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_BMS_ALLERT_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_BMS_ALLERT_GetValue()           PORTBbits.RB6
#define IO_BMS_ALLERT_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_BMS_ALLERT_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_BMS_ALLERT_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_BMS_ALLERT_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_BMS_ALLERT_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define IO_BMS_ALLERT_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define IO_BMS_ALLERT_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define IO_BMS_ALLERT_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_OD                   ODCONBbits.ODCB7
#define IO_RB7_ANS                  ANSELBbits.ANSB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define IO_RB7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define IO_RB7_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set IO_LED0 aliases
#define IO_LED0_TRIS                 TRISCbits.TRISC0
#define IO_LED0_LAT                  LATCbits.LATC0
#define IO_LED0_PORT                 PORTCbits.RC0
#define IO_LED0_WPU                  WPUCbits.WPUC0
#define IO_LED0_OD                   ODCONCbits.ODCC0
#define IO_LED0_ANS                  ANSELCbits.ANSC0
#define IO_LED0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_LED0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_LED0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_LED0_GetValue()           PORTCbits.RC0
#define IO_LED0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_LED0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_LED0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_LED0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_LED0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_LED0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define IO_LED0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define IO_LED0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set IO_LED1 aliases
#define IO_LED1_TRIS                 TRISCbits.TRISC1
#define IO_LED1_LAT                  LATCbits.LATC1
#define IO_LED1_PORT                 PORTCbits.RC1
#define IO_LED1_WPU                  WPUCbits.WPUC1
#define IO_LED1_OD                   ODCONCbits.ODCC1
#define IO_LED1_ANS                  ANSELCbits.ANSC1
#define IO_LED1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_LED1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_LED1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_LED1_GetValue()           PORTCbits.RC1
#define IO_LED1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_LED1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IO_LED1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define IO_LED1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define IO_LED1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define IO_LED1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define IO_LED1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define IO_LED1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set IO_LED2 aliases
#define IO_LED2_TRIS                 TRISCbits.TRISC2
#define IO_LED2_LAT                  LATCbits.LATC2
#define IO_LED2_PORT                 PORTCbits.RC2
#define IO_LED2_WPU                  WPUCbits.WPUC2
#define IO_LED2_OD                   ODCONCbits.ODCC2
#define IO_LED2_ANS                  ANSELCbits.ANSC2
#define IO_LED2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_LED2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_LED2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_LED2_GetValue()           PORTCbits.RC2
#define IO_LED2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_LED2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_LED2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_LED2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_LED2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define IO_LED2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define IO_LED2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define IO_LED2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set IO_LED3 aliases
#define IO_LED3_TRIS                 TRISCbits.TRISC3
#define IO_LED3_LAT                  LATCbits.LATC3
#define IO_LED3_PORT                 PORTCbits.RC3
#define IO_LED3_WPU                  WPUCbits.WPUC3
#define IO_LED3_OD                   ODCONCbits.ODCC3
#define IO_LED3_ANS                  ANSELCbits.ANSC3
#define IO_LED3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_LED3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_LED3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_LED3_GetValue()           PORTCbits.RC3
#define IO_LED3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_LED3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define IO_LED3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define IO_LED3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define IO_LED3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define IO_LED3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define IO_LED3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define IO_LED3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set IO_LED4 aliases
#define IO_LED4_TRIS                 TRISCbits.TRISC4
#define IO_LED4_LAT                  LATCbits.LATC4
#define IO_LED4_PORT                 PORTCbits.RC4
#define IO_LED4_WPU                  WPUCbits.WPUC4
#define IO_LED4_OD                   ODCONCbits.ODCC4
#define IO_LED4_ANS                  ANSELCbits.ANSC4
#define IO_LED4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_LED4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_LED4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_LED4_GetValue()           PORTCbits.RC4
#define IO_LED4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_LED4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_LED4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_LED4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_LED4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define IO_LED4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define IO_LED4_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define IO_LED4_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set IO_LED5 aliases
#define IO_LED5_TRIS                 TRISCbits.TRISC5
#define IO_LED5_LAT                  LATCbits.LATC5
#define IO_LED5_PORT                 PORTCbits.RC5
#define IO_LED5_WPU                  WPUCbits.WPUC5
#define IO_LED5_OD                   ODCONCbits.ODCC5
#define IO_LED5_ANS                  ANSELCbits.ANSC5
#define IO_LED5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_LED5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_LED5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_LED5_GetValue()           PORTCbits.RC5
#define IO_LED5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_LED5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_LED5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_LED5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_LED5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_LED5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_LED5_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define IO_LED5_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set IO_LED6 aliases
#define IO_LED6_TRIS                 TRISCbits.TRISC6
#define IO_LED6_LAT                  LATCbits.LATC6
#define IO_LED6_PORT                 PORTCbits.RC6
#define IO_LED6_WPU                  WPUCbits.WPUC6
#define IO_LED6_OD                   ODCONCbits.ODCC6
#define IO_LED6_ANS                  ANSELCbits.ANSC6
#define IO_LED6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_LED6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_LED6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_LED6_GetValue()           PORTCbits.RC6
#define IO_LED6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_LED6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO_LED6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define IO_LED6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define IO_LED6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define IO_LED6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define IO_LED6_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define IO_LED6_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF4 pin functionality
 * @Example
    IOCAF4_ISR();
 */
void IOCAF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_InterruptHandler);

*/
extern void (*IOCAF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_DefaultInterruptHandler);

*/
void IOCAF4_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF5 pin functionality
 * @Example
    IOCAF5_ISR();
 */
void IOCAF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_InterruptHandler);

*/
extern void (*IOCAF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_DefaultInterruptHandler);

*/
void IOCAF5_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF6 pin functionality
 * @Example
    IOCBF6_ISR();
 */
void IOCBF6_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF6 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF6 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF6_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF6 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF6_SetInterruptHandler() method.
    This handler is called every time the IOCBF6 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(IOCBF6_InterruptHandler);

*/
extern void (*IOCBF6_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF6 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF6_SetInterruptHandler() method.
    This handler is called every time the IOCBF6 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(IOCBF6_DefaultInterruptHandler);

*/
void IOCBF6_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
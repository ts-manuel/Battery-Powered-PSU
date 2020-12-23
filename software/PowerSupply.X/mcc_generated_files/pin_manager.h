/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

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

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>

/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RA0, high using LATA0.

  @Description
    Sets the GPIO pin, RA0, high using LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA0 high (1)
    IO_BTN_CH2_EN_SetHigh();
    </code>

*/
#define IO_BTN_CH2_EN_SetHigh()          _LATA0 = 1
/**
  @Summary
    Sets the GPIO pin, RA0, low using LATA0.

  @Description
    Sets the GPIO pin, RA0, low using LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA0 low (0)
    IO_BTN_CH2_EN_SetLow();
    </code>

*/
#define IO_BTN_CH2_EN_SetLow()           _LATA0 = 0
/**
  @Summary
    Toggles the GPIO pin, RA0, using LATA0.

  @Description
    Toggles the GPIO pin, RA0, using LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA0
    IO_BTN_CH2_EN_Toggle();
    </code>

*/
#define IO_BTN_CH2_EN_Toggle()           _LATA0 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA0.

  @Description
    Reads the value of the GPIO pin, RA0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA0
    postValue = IO_BTN_CH2_EN_GetValue();
    </code>

*/
#define IO_BTN_CH2_EN_GetValue()         _RA0
/**
  @Summary
    Configures the GPIO pin, RA0, as an input.

  @Description
    Configures the GPIO pin, RA0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA0 as an input
    IO_BTN_CH2_EN_SetDigitalInput();
    </code>

*/
#define IO_BTN_CH2_EN_SetDigitalInput()  _TRISA0 = 1
/**
  @Summary
    Configures the GPIO pin, RA0, as an output.

  @Description
    Configures the GPIO pin, RA0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA0 as an output
    IO_BTN_CH2_EN_SetDigitalOutput();
    </code>

*/
#define IO_BTN_CH2_EN_SetDigitalOutput() _TRISA0 = 0
/**
  @Summary
    Sets the GPIO pin, RA1, high using LATA1.

  @Description
    Sets the GPIO pin, RA1, high using LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA1 high (1)
    IO_RA1_SetHigh();
    </code>

*/
#define IO_RA1_SetHigh()          _LATA1 = 1
/**
  @Summary
    Sets the GPIO pin, RA1, low using LATA1.

  @Description
    Sets the GPIO pin, RA1, low using LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA1 low (0)
    IO_RA1_SetLow();
    </code>

*/
#define IO_RA1_SetLow()           _LATA1 = 0
/**
  @Summary
    Toggles the GPIO pin, RA1, using LATA1.

  @Description
    Toggles the GPIO pin, RA1, using LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA1
    IO_RA1_Toggle();
    </code>

*/
#define IO_RA1_Toggle()           _LATA1 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA1.

  @Description
    Reads the value of the GPIO pin, RA1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA1
    postValue = IO_RA1_GetValue();
    </code>

*/
#define IO_RA1_GetValue()         _RA1
/**
  @Summary
    Configures the GPIO pin, RA1, as an input.

  @Description
    Configures the GPIO pin, RA1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA1 as an input
    IO_RA1_SetDigitalInput();
    </code>

*/
#define IO_RA1_SetDigitalInput()  _TRISA1 = 1
/**
  @Summary
    Configures the GPIO pin, RA1, as an output.

  @Description
    Configures the GPIO pin, RA1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA1 as an output
    IO_RA1_SetDigitalOutput();
    </code>

*/
#define IO_RA1_SetDigitalOutput() _TRISA1 = 0
/**
  @Summary
    Sets the GPIO pin, RA10, high using LATA10.

  @Description
    Sets the GPIO pin, RA10, high using LATA10.

  @Preconditions
    The RA10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA10 high (1)
    IO_GPIO_1_SetHigh();
    </code>

*/
#define IO_GPIO_1_SetHigh()          _LATA10 = 1
/**
  @Summary
    Sets the GPIO pin, RA10, low using LATA10.

  @Description
    Sets the GPIO pin, RA10, low using LATA10.

  @Preconditions
    The RA10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA10 low (0)
    IO_GPIO_1_SetLow();
    </code>

*/
#define IO_GPIO_1_SetLow()           _LATA10 = 0
/**
  @Summary
    Toggles the GPIO pin, RA10, using LATA10.

  @Description
    Toggles the GPIO pin, RA10, using LATA10.

  @Preconditions
    The RA10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA10
    IO_GPIO_1_Toggle();
    </code>

*/
#define IO_GPIO_1_Toggle()           _LATA10 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA10.

  @Description
    Reads the value of the GPIO pin, RA10.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA10
    postValue = IO_GPIO_1_GetValue();
    </code>

*/
#define IO_GPIO_1_GetValue()         _RA10
/**
  @Summary
    Configures the GPIO pin, RA10, as an input.

  @Description
    Configures the GPIO pin, RA10, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA10 as an input
    IO_GPIO_1_SetDigitalInput();
    </code>

*/
#define IO_GPIO_1_SetDigitalInput()  _TRISA10 = 1
/**
  @Summary
    Configures the GPIO pin, RA10, as an output.

  @Description
    Configures the GPIO pin, RA10, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA10 as an output
    IO_GPIO_1_SetDigitalOutput();
    </code>

*/
#define IO_GPIO_1_SetDigitalOutput() _TRISA10 = 0
/**
  @Summary
    Sets the GPIO pin, RA14, high using LATA14.

  @Description
    Sets the GPIO pin, RA14, high using LATA14.

  @Preconditions
    The RA14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA14 high (1)
    SCL_SetHigh();
    </code>

*/
#define SCL_SetHigh()          _LATA14 = 1
/**
  @Summary
    Sets the GPIO pin, RA14, low using LATA14.

  @Description
    Sets the GPIO pin, RA14, low using LATA14.

  @Preconditions
    The RA14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA14 low (0)
    SCL_SetLow();
    </code>

*/
#define SCL_SetLow()           _LATA14 = 0
/**
  @Summary
    Toggles the GPIO pin, RA14, using LATA14.

  @Description
    Toggles the GPIO pin, RA14, using LATA14.

  @Preconditions
    The RA14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA14
    SCL_Toggle();
    </code>

*/
#define SCL_Toggle()           _LATA14 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA14.

  @Description
    Reads the value of the GPIO pin, RA14.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA14
    postValue = SCL_GetValue();
    </code>

*/
#define SCL_GetValue()         _RA14
/**
  @Summary
    Configures the GPIO pin, RA14, as an input.

  @Description
    Configures the GPIO pin, RA14, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA14 as an input
    SCL_SetDigitalInput();
    </code>

*/
#define SCL_SetDigitalInput()  _TRISA14 = 1
/**
  @Summary
    Configures the GPIO pin, RA14, as an output.

  @Description
    Configures the GPIO pin, RA14, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA14 as an output
    SCL_SetDigitalOutput();
    </code>

*/
#define SCL_SetDigitalOutput() _TRISA14 = 0
/**
  @Summary
    Sets the GPIO pin, RA15, high using LATA15.

  @Description
    Sets the GPIO pin, RA15, high using LATA15.

  @Preconditions
    The RA15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA15 high (1)
    SDA_SetHigh();
    </code>

*/
#define SDA_SetHigh()          _LATA15 = 1
/**
  @Summary
    Sets the GPIO pin, RA15, low using LATA15.

  @Description
    Sets the GPIO pin, RA15, low using LATA15.

  @Preconditions
    The RA15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA15 low (0)
    SDA_SetLow();
    </code>

*/
#define SDA_SetLow()           _LATA15 = 0
/**
  @Summary
    Toggles the GPIO pin, RA15, using LATA15.

  @Description
    Toggles the GPIO pin, RA15, using LATA15.

  @Preconditions
    The RA15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA15
    SDA_Toggle();
    </code>

*/
#define SDA_Toggle()           _LATA15 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA15.

  @Description
    Reads the value of the GPIO pin, RA15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA15
    postValue = SDA_GetValue();
    </code>

*/
#define SDA_GetValue()         _RA15
/**
  @Summary
    Configures the GPIO pin, RA15, as an input.

  @Description
    Configures the GPIO pin, RA15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA15 as an input
    SDA_SetDigitalInput();
    </code>

*/
#define SDA_SetDigitalInput()  _TRISA15 = 1
/**
  @Summary
    Configures the GPIO pin, RA15, as an output.

  @Description
    Configures the GPIO pin, RA15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA15 as an output
    SDA_SetDigitalOutput();
    </code>

*/
#define SDA_SetDigitalOutput() _TRISA15 = 0
/**
  @Summary
    Sets the GPIO pin, RA2, high using LATA2.

  @Description
    Sets the GPIO pin, RA2, high using LATA2.

  @Preconditions
    The RA2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA2 high (1)
    FLB_AUX_EN_SetHigh();
    </code>

*/
#define FLB_AUX_EN_SetHigh()          _LATA2 = 1
/**
  @Summary
    Sets the GPIO pin, RA2, low using LATA2.

  @Description
    Sets the GPIO pin, RA2, low using LATA2.

  @Preconditions
    The RA2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA2 low (0)
    FLB_AUX_EN_SetLow();
    </code>

*/
#define FLB_AUX_EN_SetLow()           _LATA2 = 0
/**
  @Summary
    Toggles the GPIO pin, RA2, using LATA2.

  @Description
    Toggles the GPIO pin, RA2, using LATA2.

  @Preconditions
    The RA2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA2
    FLB_AUX_EN_Toggle();
    </code>

*/
#define FLB_AUX_EN_Toggle()           _LATA2 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA2.

  @Description
    Reads the value of the GPIO pin, RA2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA2
    postValue = FLB_AUX_EN_GetValue();
    </code>

*/
#define FLB_AUX_EN_GetValue()         _RA2
/**
  @Summary
    Configures the GPIO pin, RA2, as an input.

  @Description
    Configures the GPIO pin, RA2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA2 as an input
    FLB_AUX_EN_SetDigitalInput();
    </code>

*/
#define FLB_AUX_EN_SetDigitalInput()  _TRISA2 = 1
/**
  @Summary
    Configures the GPIO pin, RA2, as an output.

  @Description
    Configures the GPIO pin, RA2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA2 as an output
    FLB_AUX_EN_SetDigitalOutput();
    </code>

*/
#define FLB_AUX_EN_SetDigitalOutput() _TRISA2 = 0
/**
  @Summary
    Sets the GPIO pin, RA3, high using LATA3.

  @Description
    Sets the GPIO pin, RA3, high using LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA3 high (1)
    FLB_CH2_EN_SetHigh();
    </code>

*/
#define FLB_CH2_EN_SetHigh()          _LATA3 = 1
/**
  @Summary
    Sets the GPIO pin, RA3, low using LATA3.

  @Description
    Sets the GPIO pin, RA3, low using LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA3 low (0)
    FLB_CH2_EN_SetLow();
    </code>

*/
#define FLB_CH2_EN_SetLow()           _LATA3 = 0
/**
  @Summary
    Toggles the GPIO pin, RA3, using LATA3.

  @Description
    Toggles the GPIO pin, RA3, using LATA3.

  @Preconditions
    The RA3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA3
    FLB_CH2_EN_Toggle();
    </code>

*/
#define FLB_CH2_EN_Toggle()           _LATA3 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA3.

  @Description
    Reads the value of the GPIO pin, RA3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA3
    postValue = FLB_CH2_EN_GetValue();
    </code>

*/
#define FLB_CH2_EN_GetValue()         _RA3
/**
  @Summary
    Configures the GPIO pin, RA3, as an input.

  @Description
    Configures the GPIO pin, RA3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA3 as an input
    FLB_CH2_EN_SetDigitalInput();
    </code>

*/
#define FLB_CH2_EN_SetDigitalInput()  _TRISA3 = 1
/**
  @Summary
    Configures the GPIO pin, RA3, as an output.

  @Description
    Configures the GPIO pin, RA3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA3 as an output
    FLB_CH2_EN_SetDigitalOutput();
    </code>

*/
#define FLB_CH2_EN_SetDigitalOutput() _TRISA3 = 0
/**
  @Summary
    Sets the GPIO pin, RA4, high using LATA4.

  @Description
    Sets the GPIO pin, RA4, high using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 high (1)
    FLB_CH1_EN_SetHigh();
    </code>

*/
#define FLB_CH1_EN_SetHigh()          _LATA4 = 1
/**
  @Summary
    Sets the GPIO pin, RA4, low using LATA4.

  @Description
    Sets the GPIO pin, RA4, low using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 low (0)
    FLB_CH1_EN_SetLow();
    </code>

*/
#define FLB_CH1_EN_SetLow()           _LATA4 = 0
/**
  @Summary
    Toggles the GPIO pin, RA4, using LATA4.

  @Description
    Toggles the GPIO pin, RA4, using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA4
    FLB_CH1_EN_Toggle();
    </code>

*/
#define FLB_CH1_EN_Toggle()           _LATA4 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA4.

  @Description
    Reads the value of the GPIO pin, RA4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA4
    postValue = FLB_CH1_EN_GetValue();
    </code>

*/
#define FLB_CH1_EN_GetValue()         _RA4
/**
  @Summary
    Configures the GPIO pin, RA4, as an input.

  @Description
    Configures the GPIO pin, RA4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an input
    FLB_CH1_EN_SetDigitalInput();
    </code>

*/
#define FLB_CH1_EN_SetDigitalInput()  _TRISA4 = 1
/**
  @Summary
    Configures the GPIO pin, RA4, as an output.

  @Description
    Configures the GPIO pin, RA4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an output
    FLB_CH1_EN_SetDigitalOutput();
    </code>

*/
#define FLB_CH1_EN_SetDigitalOutput() _TRISA4 = 0
/**
  @Summary
    Sets the GPIO pin, RA5, high using LATA5.

  @Description
    Sets the GPIO pin, RA5, high using LATA5.

  @Preconditions
    The RA5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA5 high (1)
    PWR_3V3_EN_SetHigh();
    </code>

*/
#define PWR_3V3_EN_SetHigh()          _LATA5 = 1
/**
  @Summary
    Sets the GPIO pin, RA5, low using LATA5.

  @Description
    Sets the GPIO pin, RA5, low using LATA5.

  @Preconditions
    The RA5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA5 low (0)
    PWR_3V3_EN_SetLow();
    </code>

*/
#define PWR_3V3_EN_SetLow()           _LATA5 = 0
/**
  @Summary
    Toggles the GPIO pin, RA5, using LATA5.

  @Description
    Toggles the GPIO pin, RA5, using LATA5.

  @Preconditions
    The RA5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA5
    PWR_3V3_EN_Toggle();
    </code>

*/
#define PWR_3V3_EN_Toggle()           _LATA5 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA5.

  @Description
    Reads the value of the GPIO pin, RA5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA5
    postValue = PWR_3V3_EN_GetValue();
    </code>

*/
#define PWR_3V3_EN_GetValue()         _RA5
/**
  @Summary
    Configures the GPIO pin, RA5, as an input.

  @Description
    Configures the GPIO pin, RA5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA5 as an input
    PWR_3V3_EN_SetDigitalInput();
    </code>

*/
#define PWR_3V3_EN_SetDigitalInput()  _TRISA5 = 1
/**
  @Summary
    Configures the GPIO pin, RA5, as an output.

  @Description
    Configures the GPIO pin, RA5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA5 as an output
    PWR_3V3_EN_SetDigitalOutput();
    </code>

*/
#define PWR_3V3_EN_SetDigitalOutput() _TRISA5 = 0
/**
  @Summary
    Sets the GPIO pin, RA6, high using LATA6.

  @Description
    Sets the GPIO pin, RA6, high using LATA6.

  @Preconditions
    The RA6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA6 high (1)
    IO_RA6_SetHigh();
    </code>

*/
#define IO_RA6_SetHigh()          _LATA6 = 1
/**
  @Summary
    Sets the GPIO pin, RA6, low using LATA6.

  @Description
    Sets the GPIO pin, RA6, low using LATA6.

  @Preconditions
    The RA6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA6 low (0)
    IO_RA6_SetLow();
    </code>

*/
#define IO_RA6_SetLow()           _LATA6 = 0
/**
  @Summary
    Toggles the GPIO pin, RA6, using LATA6.

  @Description
    Toggles the GPIO pin, RA6, using LATA6.

  @Preconditions
    The RA6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA6
    IO_RA6_Toggle();
    </code>

*/
#define IO_RA6_Toggle()           _LATA6 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA6.

  @Description
    Reads the value of the GPIO pin, RA6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA6
    postValue = IO_RA6_GetValue();
    </code>

*/
#define IO_RA6_GetValue()         _RA6
/**
  @Summary
    Configures the GPIO pin, RA6, as an input.

  @Description
    Configures the GPIO pin, RA6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA6 as an input
    IO_RA6_SetDigitalInput();
    </code>

*/
#define IO_RA6_SetDigitalInput()  _TRISA6 = 1
/**
  @Summary
    Configures the GPIO pin, RA6, as an output.

  @Description
    Configures the GPIO pin, RA6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA6 as an output
    IO_RA6_SetDigitalOutput();
    </code>

*/
#define IO_RA6_SetDigitalOutput() _TRISA6 = 0
/**
  @Summary
    Sets the GPIO pin, RA7, high using LATA7.

  @Description
    Sets the GPIO pin, RA7, high using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 high (1)
    IO_RA7_SetHigh();
    </code>

*/
#define IO_RA7_SetHigh()          _LATA7 = 1
/**
  @Summary
    Sets the GPIO pin, RA7, low using LATA7.

  @Description
    Sets the GPIO pin, RA7, low using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 low (0)
    IO_RA7_SetLow();
    </code>

*/
#define IO_RA7_SetLow()           _LATA7 = 0
/**
  @Summary
    Toggles the GPIO pin, RA7, using LATA7.

  @Description
    Toggles the GPIO pin, RA7, using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA7
    IO_RA7_Toggle();
    </code>

*/
#define IO_RA7_Toggle()           _LATA7 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA7.

  @Description
    Reads the value of the GPIO pin, RA7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA7
    postValue = IO_RA7_GetValue();
    </code>

*/
#define IO_RA7_GetValue()         _RA7
/**
  @Summary
    Configures the GPIO pin, RA7, as an input.

  @Description
    Configures the GPIO pin, RA7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an input
    IO_RA7_SetDigitalInput();
    </code>

*/
#define IO_RA7_SetDigitalInput()  _TRISA7 = 1
/**
  @Summary
    Configures the GPIO pin, RA7, as an output.

  @Description
    Configures the GPIO pin, RA7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an output
    IO_RA7_SetDigitalOutput();
    </code>

*/
#define IO_RA7_SetDigitalOutput() _TRISA7 = 0
/**
  @Summary
    Sets the GPIO pin, RA9, high using LATA9.

  @Description
    Sets the GPIO pin, RA9, high using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA9 high (1)
    IO_GPIO_0_SetHigh();
    </code>

*/
#define IO_GPIO_0_SetHigh()          _LATA9 = 1
/**
  @Summary
    Sets the GPIO pin, RA9, low using LATA9.

  @Description
    Sets the GPIO pin, RA9, low using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA9 low (0)
    IO_GPIO_0_SetLow();
    </code>

*/
#define IO_GPIO_0_SetLow()           _LATA9 = 0
/**
  @Summary
    Toggles the GPIO pin, RA9, using LATA9.

  @Description
    Toggles the GPIO pin, RA9, using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA9
    IO_GPIO_0_Toggle();
    </code>

*/
#define IO_GPIO_0_Toggle()           _LATA9 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RA9.

  @Description
    Reads the value of the GPIO pin, RA9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA9
    postValue = IO_GPIO_0_GetValue();
    </code>

*/
#define IO_GPIO_0_GetValue()         _RA9
/**
  @Summary
    Configures the GPIO pin, RA9, as an input.

  @Description
    Configures the GPIO pin, RA9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA9 as an input
    IO_GPIO_0_SetDigitalInput();
    </code>

*/
#define IO_GPIO_0_SetDigitalInput()  _TRISA9 = 1
/**
  @Summary
    Configures the GPIO pin, RA9, as an output.

  @Description
    Configures the GPIO pin, RA9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA9 as an output
    IO_GPIO_0_SetDigitalOutput();
    </code>

*/
#define IO_GPIO_0_SetDigitalOutput() _TRISA9 = 0
/**
  @Summary
    Sets the GPIO pin, RB10, high using LATB10.

  @Description
    Sets the GPIO pin, RB10, high using LATB10.

  @Preconditions
    The RB10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB10 high (1)
    IO_RB10_SetHigh();
    </code>

*/
#define IO_RB10_SetHigh()          _LATB10 = 1
/**
  @Summary
    Sets the GPIO pin, RB10, low using LATB10.

  @Description
    Sets the GPIO pin, RB10, low using LATB10.

  @Preconditions
    The RB10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB10 low (0)
    IO_RB10_SetLow();
    </code>

*/
#define IO_RB10_SetLow()           _LATB10 = 0
/**
  @Summary
    Toggles the GPIO pin, RB10, using LATB10.

  @Description
    Toggles the GPIO pin, RB10, using LATB10.

  @Preconditions
    The RB10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB10
    IO_RB10_Toggle();
    </code>

*/
#define IO_RB10_Toggle()           _LATB10 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB10.

  @Description
    Reads the value of the GPIO pin, RB10.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB10
    postValue = IO_RB10_GetValue();
    </code>

*/
#define IO_RB10_GetValue()         _RB10
/**
  @Summary
    Configures the GPIO pin, RB10, as an input.

  @Description
    Configures the GPIO pin, RB10, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB10 as an input
    IO_RB10_SetDigitalInput();
    </code>

*/
#define IO_RB10_SetDigitalInput()  _TRISB10 = 1
/**
  @Summary
    Configures the GPIO pin, RB10, as an output.

  @Description
    Configures the GPIO pin, RB10, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB10 as an output
    IO_RB10_SetDigitalOutput();
    </code>

*/
#define IO_RB10_SetDigitalOutput() _TRISB10 = 0
/**
  @Summary
    Sets the GPIO pin, RB11, high using LATB11.

  @Description
    Sets the GPIO pin, RB11, high using LATB11.

  @Preconditions
    The RB11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB11 high (1)
    IO_RB11_SetHigh();
    </code>

*/
#define IO_RB11_SetHigh()          _LATB11 = 1
/**
  @Summary
    Sets the GPIO pin, RB11, low using LATB11.

  @Description
    Sets the GPIO pin, RB11, low using LATB11.

  @Preconditions
    The RB11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB11 low (0)
    IO_RB11_SetLow();
    </code>

*/
#define IO_RB11_SetLow()           _LATB11 = 0
/**
  @Summary
    Toggles the GPIO pin, RB11, using LATB11.

  @Description
    Toggles the GPIO pin, RB11, using LATB11.

  @Preconditions
    The RB11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB11
    IO_RB11_Toggle();
    </code>

*/
#define IO_RB11_Toggle()           _LATB11 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB11.

  @Description
    Reads the value of the GPIO pin, RB11.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB11
    postValue = IO_RB11_GetValue();
    </code>

*/
#define IO_RB11_GetValue()         _RB11
/**
  @Summary
    Configures the GPIO pin, RB11, as an input.

  @Description
    Configures the GPIO pin, RB11, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB11 as an input
    IO_RB11_SetDigitalInput();
    </code>

*/
#define IO_RB11_SetDigitalInput()  _TRISB11 = 1
/**
  @Summary
    Configures the GPIO pin, RB11, as an output.

  @Description
    Configures the GPIO pin, RB11, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB11 as an output
    IO_RB11_SetDigitalOutput();
    </code>

*/
#define IO_RB11_SetDigitalOutput() _TRISB11 = 0
/**
  @Summary
    Sets the GPIO pin, RB12, high using LATB12.

  @Description
    Sets the GPIO pin, RB12, high using LATB12.

  @Preconditions
    The RB12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB12 high (1)
    IO_RB12_SetHigh();
    </code>

*/
#define IO_RB12_SetHigh()          _LATB12 = 1
/**
  @Summary
    Sets the GPIO pin, RB12, low using LATB12.

  @Description
    Sets the GPIO pin, RB12, low using LATB12.

  @Preconditions
    The RB12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB12 low (0)
    IO_RB12_SetLow();
    </code>

*/
#define IO_RB12_SetLow()           _LATB12 = 0
/**
  @Summary
    Toggles the GPIO pin, RB12, using LATB12.

  @Description
    Toggles the GPIO pin, RB12, using LATB12.

  @Preconditions
    The RB12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB12
    IO_RB12_Toggle();
    </code>

*/
#define IO_RB12_Toggle()           _LATB12 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB12.

  @Description
    Reads the value of the GPIO pin, RB12.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB12
    postValue = IO_RB12_GetValue();
    </code>

*/
#define IO_RB12_GetValue()         _RB12
/**
  @Summary
    Configures the GPIO pin, RB12, as an input.

  @Description
    Configures the GPIO pin, RB12, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB12 as an input
    IO_RB12_SetDigitalInput();
    </code>

*/
#define IO_RB12_SetDigitalInput()  _TRISB12 = 1
/**
  @Summary
    Configures the GPIO pin, RB12, as an output.

  @Description
    Configures the GPIO pin, RB12, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB12 as an output
    IO_RB12_SetDigitalOutput();
    </code>

*/
#define IO_RB12_SetDigitalOutput() _TRISB12 = 0
/**
  @Summary
    Sets the GPIO pin, RB13, high using LATB13.

  @Description
    Sets the GPIO pin, RB13, high using LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB13 high (1)
    IO_RB13_SetHigh();
    </code>

*/
#define IO_RB13_SetHigh()          _LATB13 = 1
/**
  @Summary
    Sets the GPIO pin, RB13, low using LATB13.

  @Description
    Sets the GPIO pin, RB13, low using LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB13 low (0)
    IO_RB13_SetLow();
    </code>

*/
#define IO_RB13_SetLow()           _LATB13 = 0
/**
  @Summary
    Toggles the GPIO pin, RB13, using LATB13.

  @Description
    Toggles the GPIO pin, RB13, using LATB13.

  @Preconditions
    The RB13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB13
    IO_RB13_Toggle();
    </code>

*/
#define IO_RB13_Toggle()           _LATB13 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB13.

  @Description
    Reads the value of the GPIO pin, RB13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB13
    postValue = IO_RB13_GetValue();
    </code>

*/
#define IO_RB13_GetValue()         _RB13
/**
  @Summary
    Configures the GPIO pin, RB13, as an input.

  @Description
    Configures the GPIO pin, RB13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB13 as an input
    IO_RB13_SetDigitalInput();
    </code>

*/
#define IO_RB13_SetDigitalInput()  _TRISB13 = 1
/**
  @Summary
    Configures the GPIO pin, RB13, as an output.

  @Description
    Configures the GPIO pin, RB13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB13 as an output
    IO_RB13_SetDigitalOutput();
    </code>

*/
#define IO_RB13_SetDigitalOutput() _TRISB13 = 0
/**
  @Summary
    Sets the GPIO pin, RB15, high using LATB15.

  @Description
    Sets the GPIO pin, RB15, high using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB15 high (1)
    IO_LCD_A0_SetHigh();
    </code>

*/
#define IO_LCD_A0_SetHigh()          _LATB15 = 1
/**
  @Summary
    Sets the GPIO pin, RB15, low using LATB15.

  @Description
    Sets the GPIO pin, RB15, low using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB15 low (0)
    IO_LCD_A0_SetLow();
    </code>

*/
#define IO_LCD_A0_SetLow()           _LATB15 = 0
/**
  @Summary
    Toggles the GPIO pin, RB15, using LATB15.

  @Description
    Toggles the GPIO pin, RB15, using LATB15.

  @Preconditions
    The RB15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB15
    IO_LCD_A0_Toggle();
    </code>

*/
#define IO_LCD_A0_Toggle()           _LATB15 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB15.

  @Description
    Reads the value of the GPIO pin, RB15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB15
    postValue = IO_LCD_A0_GetValue();
    </code>

*/
#define IO_LCD_A0_GetValue()         _RB15
/**
  @Summary
    Configures the GPIO pin, RB15, as an input.

  @Description
    Configures the GPIO pin, RB15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB15 as an input
    IO_LCD_A0_SetDigitalInput();
    </code>

*/
#define IO_LCD_A0_SetDigitalInput()  _TRISB15 = 1
/**
  @Summary
    Configures the GPIO pin, RB15, as an output.

  @Description
    Configures the GPIO pin, RB15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB15 as an output
    IO_LCD_A0_SetDigitalOutput();
    </code>

*/
#define IO_LCD_A0_SetDigitalOutput() _TRISB15 = 0
/**
  @Summary
    Sets the GPIO pin, RB3, high using LATB3.

  @Description
    Sets the GPIO pin, RB3, high using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB3 high (1)
    IO_LED_CH1_ON_SetHigh();
    </code>

*/
#define IO_LED_CH1_ON_SetHigh()          _LATB3 = 1
/**
  @Summary
    Sets the GPIO pin, RB3, low using LATB3.

  @Description
    Sets the GPIO pin, RB3, low using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB3 low (0)
    IO_LED_CH1_ON_SetLow();
    </code>

*/
#define IO_LED_CH1_ON_SetLow()           _LATB3 = 0
/**
  @Summary
    Toggles the GPIO pin, RB3, using LATB3.

  @Description
    Toggles the GPIO pin, RB3, using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB3
    IO_LED_CH1_ON_Toggle();
    </code>

*/
#define IO_LED_CH1_ON_Toggle()           _LATB3 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB3.

  @Description
    Reads the value of the GPIO pin, RB3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB3
    postValue = IO_LED_CH1_ON_GetValue();
    </code>

*/
#define IO_LED_CH1_ON_GetValue()         _RB3
/**
  @Summary
    Configures the GPIO pin, RB3, as an input.

  @Description
    Configures the GPIO pin, RB3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB3 as an input
    IO_LED_CH1_ON_SetDigitalInput();
    </code>

*/
#define IO_LED_CH1_ON_SetDigitalInput()  _TRISB3 = 1
/**
  @Summary
    Configures the GPIO pin, RB3, as an output.

  @Description
    Configures the GPIO pin, RB3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB3 as an output
    IO_LED_CH1_ON_SetDigitalOutput();
    </code>

*/
#define IO_LED_CH1_ON_SetDigitalOutput() _TRISB3 = 0
/**
  @Summary
    Sets the GPIO pin, RB4, high using LATB4.

  @Description
    Sets the GPIO pin, RB4, high using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 high (1)
    IO_LED_CH2_ON_SetHigh();
    </code>

*/
#define IO_LED_CH2_ON_SetHigh()          _LATB4 = 1
/**
  @Summary
    Sets the GPIO pin, RB4, low using LATB4.

  @Description
    Sets the GPIO pin, RB4, low using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 low (0)
    IO_LED_CH2_ON_SetLow();
    </code>

*/
#define IO_LED_CH2_ON_SetLow()           _LATB4 = 0
/**
  @Summary
    Toggles the GPIO pin, RB4, using LATB4.

  @Description
    Toggles the GPIO pin, RB4, using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB4
    IO_LED_CH2_ON_Toggle();
    </code>

*/
#define IO_LED_CH2_ON_Toggle()           _LATB4 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB4.

  @Description
    Reads the value of the GPIO pin, RB4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB4
    postValue = IO_LED_CH2_ON_GetValue();
    </code>

*/
#define IO_LED_CH2_ON_GetValue()         _RB4
/**
  @Summary
    Configures the GPIO pin, RB4, as an input.

  @Description
    Configures the GPIO pin, RB4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an input
    IO_LED_CH2_ON_SetDigitalInput();
    </code>

*/
#define IO_LED_CH2_ON_SetDigitalInput()  _TRISB4 = 1
/**
  @Summary
    Configures the GPIO pin, RB4, as an output.

  @Description
    Configures the GPIO pin, RB4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an output
    IO_LED_CH2_ON_SetDigitalOutput();
    </code>

*/
#define IO_LED_CH2_ON_SetDigitalOutput() _TRISB4 = 0
/**
  @Summary
    Sets the GPIO pin, RB5, high using LATB5.

  @Description
    Sets the GPIO pin, RB5, high using LATB5.

  @Preconditions
    The RB5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB5 high (1)
    IO_BTN_MENU_SetHigh();
    </code>

*/
#define IO_BTN_MENU_SetHigh()          _LATB5 = 1
/**
  @Summary
    Sets the GPIO pin, RB5, low using LATB5.

  @Description
    Sets the GPIO pin, RB5, low using LATB5.

  @Preconditions
    The RB5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB5 low (0)
    IO_BTN_MENU_SetLow();
    </code>

*/
#define IO_BTN_MENU_SetLow()           _LATB5 = 0
/**
  @Summary
    Toggles the GPIO pin, RB5, using LATB5.

  @Description
    Toggles the GPIO pin, RB5, using LATB5.

  @Preconditions
    The RB5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB5
    IO_BTN_MENU_Toggle();
    </code>

*/
#define IO_BTN_MENU_Toggle()           _LATB5 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB5.

  @Description
    Reads the value of the GPIO pin, RB5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB5
    postValue = IO_BTN_MENU_GetValue();
    </code>

*/
#define IO_BTN_MENU_GetValue()         _RB5
/**
  @Summary
    Configures the GPIO pin, RB5, as an input.

  @Description
    Configures the GPIO pin, RB5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB5 as an input
    IO_BTN_MENU_SetDigitalInput();
    </code>

*/
#define IO_BTN_MENU_SetDigitalInput()  _TRISB5 = 1
/**
  @Summary
    Configures the GPIO pin, RB5, as an output.

  @Description
    Configures the GPIO pin, RB5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB5 as an output
    IO_BTN_MENU_SetDigitalOutput();
    </code>

*/
#define IO_BTN_MENU_SetDigitalOutput() _TRISB5 = 0
/**
  @Summary
    Sets the GPIO pin, RB6, high using LATB6.

  @Description
    Sets the GPIO pin, RB6, high using LATB6.

  @Preconditions
    The RB6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB6 high (1)
    IO_CH1_OUT_EN_SetHigh();
    </code>

*/
#define IO_CH1_OUT_EN_SetHigh()          _LATB6 = 1
/**
  @Summary
    Sets the GPIO pin, RB6, low using LATB6.

  @Description
    Sets the GPIO pin, RB6, low using LATB6.

  @Preconditions
    The RB6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB6 low (0)
    IO_CH1_OUT_EN_SetLow();
    </code>

*/
#define IO_CH1_OUT_EN_SetLow()           _LATB6 = 0
/**
  @Summary
    Toggles the GPIO pin, RB6, using LATB6.

  @Description
    Toggles the GPIO pin, RB6, using LATB6.

  @Preconditions
    The RB6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB6
    IO_CH1_OUT_EN_Toggle();
    </code>

*/
#define IO_CH1_OUT_EN_Toggle()           _LATB6 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB6.

  @Description
    Reads the value of the GPIO pin, RB6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB6
    postValue = IO_CH1_OUT_EN_GetValue();
    </code>

*/
#define IO_CH1_OUT_EN_GetValue()         _RB6
/**
  @Summary
    Configures the GPIO pin, RB6, as an input.

  @Description
    Configures the GPIO pin, RB6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB6 as an input
    IO_CH1_OUT_EN_SetDigitalInput();
    </code>

*/
#define IO_CH1_OUT_EN_SetDigitalInput()  _TRISB6 = 1
/**
  @Summary
    Configures the GPIO pin, RB6, as an output.

  @Description
    Configures the GPIO pin, RB6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB6 as an output
    IO_CH1_OUT_EN_SetDigitalOutput();
    </code>

*/
#define IO_CH1_OUT_EN_SetDigitalOutput() _TRISB6 = 0
/**
  @Summary
    Sets the GPIO pin, RB7, high using LATB7.

  @Description
    Sets the GPIO pin, RB7, high using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB7 high (1)
    IO_CH1_FAULT_OC_SetHigh();
    </code>

*/
#define IO_CH1_FAULT_OC_SetHigh()          _LATB7 = 1
/**
  @Summary
    Sets the GPIO pin, RB7, low using LATB7.

  @Description
    Sets the GPIO pin, RB7, low using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB7 low (0)
    IO_CH1_FAULT_OC_SetLow();
    </code>

*/
#define IO_CH1_FAULT_OC_SetLow()           _LATB7 = 0
/**
  @Summary
    Toggles the GPIO pin, RB7, using LATB7.

  @Description
    Toggles the GPIO pin, RB7, using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB7
    IO_CH1_FAULT_OC_Toggle();
    </code>

*/
#define IO_CH1_FAULT_OC_Toggle()           _LATB7 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB7.

  @Description
    Reads the value of the GPIO pin, RB7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB7
    postValue = IO_CH1_FAULT_OC_GetValue();
    </code>

*/
#define IO_CH1_FAULT_OC_GetValue()         _RB7
/**
  @Summary
    Configures the GPIO pin, RB7, as an input.

  @Description
    Configures the GPIO pin, RB7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB7 as an input
    IO_CH1_FAULT_OC_SetDigitalInput();
    </code>

*/
#define IO_CH1_FAULT_OC_SetDigitalInput()  _TRISB7 = 1
/**
  @Summary
    Configures the GPIO pin, RB7, as an output.

  @Description
    Configures the GPIO pin, RB7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB7 as an output
    IO_CH1_FAULT_OC_SetDigitalOutput();
    </code>

*/
#define IO_CH1_FAULT_OC_SetDigitalOutput() _TRISB7 = 0
/**
  @Summary
    Sets the GPIO pin, RB8, high using LATB8.

  @Description
    Sets the GPIO pin, RB8, high using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB8 high (1)
    IO_CH2_OUT_EN_SetHigh();
    </code>

*/
#define IO_CH2_OUT_EN_SetHigh()          _LATB8 = 1
/**
  @Summary
    Sets the GPIO pin, RB8, low using LATB8.

  @Description
    Sets the GPIO pin, RB8, low using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB8 low (0)
    IO_CH2_OUT_EN_SetLow();
    </code>

*/
#define IO_CH2_OUT_EN_SetLow()           _LATB8 = 0
/**
  @Summary
    Toggles the GPIO pin, RB8, using LATB8.

  @Description
    Toggles the GPIO pin, RB8, using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB8
    IO_CH2_OUT_EN_Toggle();
    </code>

*/
#define IO_CH2_OUT_EN_Toggle()           _LATB8 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB8.

  @Description
    Reads the value of the GPIO pin, RB8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB8
    postValue = IO_CH2_OUT_EN_GetValue();
    </code>

*/
#define IO_CH2_OUT_EN_GetValue()         _RB8
/**
  @Summary
    Configures the GPIO pin, RB8, as an input.

  @Description
    Configures the GPIO pin, RB8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB8 as an input
    IO_CH2_OUT_EN_SetDigitalInput();
    </code>

*/
#define IO_CH2_OUT_EN_SetDigitalInput()  _TRISB8 = 1
/**
  @Summary
    Configures the GPIO pin, RB8, as an output.

  @Description
    Configures the GPIO pin, RB8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB8 as an output
    IO_CH2_OUT_EN_SetDigitalOutput();
    </code>

*/
#define IO_CH2_OUT_EN_SetDigitalOutput() _TRISB8 = 0
/**
  @Summary
    Sets the GPIO pin, RB9, high using LATB9.

  @Description
    Sets the GPIO pin, RB9, high using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB9 high (1)
    IO_CH2_FAULT_OC_SetHigh();
    </code>

*/
#define IO_CH2_FAULT_OC_SetHigh()          _LATB9 = 1
/**
  @Summary
    Sets the GPIO pin, RB9, low using LATB9.

  @Description
    Sets the GPIO pin, RB9, low using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB9 low (0)
    IO_CH2_FAULT_OC_SetLow();
    </code>

*/
#define IO_CH2_FAULT_OC_SetLow()           _LATB9 = 0
/**
  @Summary
    Toggles the GPIO pin, RB9, using LATB9.

  @Description
    Toggles the GPIO pin, RB9, using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB9
    IO_CH2_FAULT_OC_Toggle();
    </code>

*/
#define IO_CH2_FAULT_OC_Toggle()           _LATB9 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RB9.

  @Description
    Reads the value of the GPIO pin, RB9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB9
    postValue = IO_CH2_FAULT_OC_GetValue();
    </code>

*/
#define IO_CH2_FAULT_OC_GetValue()         _RB9
/**
  @Summary
    Configures the GPIO pin, RB9, as an input.

  @Description
    Configures the GPIO pin, RB9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB9 as an input
    IO_CH2_FAULT_OC_SetDigitalInput();
    </code>

*/
#define IO_CH2_FAULT_OC_SetDigitalInput()  _TRISB9 = 1
/**
  @Summary
    Configures the GPIO pin, RB9, as an output.

  @Description
    Configures the GPIO pin, RB9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB9 as an output
    IO_CH2_FAULT_OC_SetDigitalOutput();
    </code>

*/
#define IO_CH2_FAULT_OC_SetDigitalOutput() _TRISB9 = 0
/**
  @Summary
    Sets the GPIO pin, RC2, high using LATC2.

  @Description
    Sets the GPIO pin, RC2, high using LATC2.

  @Preconditions
    The RC2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC2 high (1)
    IO_BTN_PWR_SetHigh();
    </code>

*/
#define IO_BTN_PWR_SetHigh()          _LATC2 = 1
/**
  @Summary
    Sets the GPIO pin, RC2, low using LATC2.

  @Description
    Sets the GPIO pin, RC2, low using LATC2.

  @Preconditions
    The RC2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC2 low (0)
    IO_BTN_PWR_SetLow();
    </code>

*/
#define IO_BTN_PWR_SetLow()           _LATC2 = 0
/**
  @Summary
    Toggles the GPIO pin, RC2, using LATC2.

  @Description
    Toggles the GPIO pin, RC2, using LATC2.

  @Preconditions
    The RC2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC2
    IO_BTN_PWR_Toggle();
    </code>

*/
#define IO_BTN_PWR_Toggle()           _LATC2 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RC2.

  @Description
    Reads the value of the GPIO pin, RC2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC2
    postValue = IO_BTN_PWR_GetValue();
    </code>

*/
#define IO_BTN_PWR_GetValue()         _RC2
/**
  @Summary
    Configures the GPIO pin, RC2, as an input.

  @Description
    Configures the GPIO pin, RC2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC2 as an input
    IO_BTN_PWR_SetDigitalInput();
    </code>

*/
#define IO_BTN_PWR_SetDigitalInput()  _TRISC2 = 1
/**
  @Summary
    Configures the GPIO pin, RC2, as an output.

  @Description
    Configures the GPIO pin, RC2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC2 as an output
    IO_BTN_PWR_SetDigitalOutput();
    </code>

*/
#define IO_BTN_PWR_SetDigitalOutput() _TRISC2 = 0
/**
  @Summary
    Sets the GPIO pin, RC3, high using LATC3.

  @Description
    Sets the GPIO pin, RC3, high using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC3 high (1)
    IO_ENC_A_SetHigh();
    </code>

*/
#define IO_ENC_A_SetHigh()          _LATC3 = 1
/**
  @Summary
    Sets the GPIO pin, RC3, low using LATC3.

  @Description
    Sets the GPIO pin, RC3, low using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC3 low (0)
    IO_ENC_A_SetLow();
    </code>

*/
#define IO_ENC_A_SetLow()           _LATC3 = 0
/**
  @Summary
    Toggles the GPIO pin, RC3, using LATC3.

  @Description
    Toggles the GPIO pin, RC3, using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC3
    IO_ENC_A_Toggle();
    </code>

*/
#define IO_ENC_A_Toggle()           _LATC3 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RC3.

  @Description
    Reads the value of the GPIO pin, RC3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC3
    postValue = IO_ENC_A_GetValue();
    </code>

*/
#define IO_ENC_A_GetValue()         _RC3
/**
  @Summary
    Configures the GPIO pin, RC3, as an input.

  @Description
    Configures the GPIO pin, RC3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC3 as an input
    IO_ENC_A_SetDigitalInput();
    </code>

*/
#define IO_ENC_A_SetDigitalInput()  _TRISC3 = 1
/**
  @Summary
    Configures the GPIO pin, RC3, as an output.

  @Description
    Configures the GPIO pin, RC3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC3 as an output
    IO_ENC_A_SetDigitalOutput();
    </code>

*/
#define IO_ENC_A_SetDigitalOutput() _TRISC3 = 0
/**
  @Summary
    Sets the GPIO pin, RC4, high using LATC4.

  @Description
    Sets the GPIO pin, RC4, high using LATC4.

  @Preconditions
    The RC4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC4 high (1)
    IO_ENC_B_SetHigh();
    </code>

*/
#define IO_ENC_B_SetHigh()          _LATC4 = 1
/**
  @Summary
    Sets the GPIO pin, RC4, low using LATC4.

  @Description
    Sets the GPIO pin, RC4, low using LATC4.

  @Preconditions
    The RC4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC4 low (0)
    IO_ENC_B_SetLow();
    </code>

*/
#define IO_ENC_B_SetLow()           _LATC4 = 0
/**
  @Summary
    Toggles the GPIO pin, RC4, using LATC4.

  @Description
    Toggles the GPIO pin, RC4, using LATC4.

  @Preconditions
    The RC4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC4
    IO_ENC_B_Toggle();
    </code>

*/
#define IO_ENC_B_Toggle()           _LATC4 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RC4.

  @Description
    Reads the value of the GPIO pin, RC4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC4
    postValue = IO_ENC_B_GetValue();
    </code>

*/
#define IO_ENC_B_GetValue()         _RC4
/**
  @Summary
    Configures the GPIO pin, RC4, as an input.

  @Description
    Configures the GPIO pin, RC4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC4 as an input
    IO_ENC_B_SetDigitalInput();
    </code>

*/
#define IO_ENC_B_SetDigitalInput()  _TRISC4 = 1
/**
  @Summary
    Configures the GPIO pin, RC4, as an output.

  @Description
    Configures the GPIO pin, RC4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC4 as an output
    IO_ENC_B_SetDigitalOutput();
    </code>

*/
#define IO_ENC_B_SetDigitalOutput() _TRISC4 = 0
/**
  @Summary
    Sets the GPIO pin, RD0, high using LATD0.

  @Description
    Sets the GPIO pin, RD0, high using LATD0.

  @Preconditions
    The RD0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD0 high (1)
    IO_RD0_SetHigh();
    </code>

*/
#define IO_RD0_SetHigh()          _LATD0 = 1
/**
  @Summary
    Sets the GPIO pin, RD0, low using LATD0.

  @Description
    Sets the GPIO pin, RD0, low using LATD0.

  @Preconditions
    The RD0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD0 low (0)
    IO_RD0_SetLow();
    </code>

*/
#define IO_RD0_SetLow()           _LATD0 = 0
/**
  @Summary
    Toggles the GPIO pin, RD0, using LATD0.

  @Description
    Toggles the GPIO pin, RD0, using LATD0.

  @Preconditions
    The RD0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD0
    IO_RD0_Toggle();
    </code>

*/
#define IO_RD0_Toggle()           _LATD0 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD0.

  @Description
    Reads the value of the GPIO pin, RD0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD0
    postValue = IO_RD0_GetValue();
    </code>

*/
#define IO_RD0_GetValue()         _RD0
/**
  @Summary
    Configures the GPIO pin, RD0, as an input.

  @Description
    Configures the GPIO pin, RD0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD0 as an input
    IO_RD0_SetDigitalInput();
    </code>

*/
#define IO_RD0_SetDigitalInput()  _TRISD0 = 1
/**
  @Summary
    Configures the GPIO pin, RD0, as an output.

  @Description
    Configures the GPIO pin, RD0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD0 as an output
    IO_RD0_SetDigitalOutput();
    </code>

*/
#define IO_RD0_SetDigitalOutput() _TRISD0 = 0
/**
  @Summary
    Sets the GPIO pin, RD1, high using LATD1.

  @Description
    Sets the GPIO pin, RD1, high using LATD1.

  @Preconditions
    The RD1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD1 high (1)
    IO_RD1_SetHigh();
    </code>

*/
#define IO_RD1_SetHigh()          _LATD1 = 1
/**
  @Summary
    Sets the GPIO pin, RD1, low using LATD1.

  @Description
    Sets the GPIO pin, RD1, low using LATD1.

  @Preconditions
    The RD1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD1 low (0)
    IO_RD1_SetLow();
    </code>

*/
#define IO_RD1_SetLow()           _LATD1 = 0
/**
  @Summary
    Toggles the GPIO pin, RD1, using LATD1.

  @Description
    Toggles the GPIO pin, RD1, using LATD1.

  @Preconditions
    The RD1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD1
    IO_RD1_Toggle();
    </code>

*/
#define IO_RD1_Toggle()           _LATD1 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD1.

  @Description
    Reads the value of the GPIO pin, RD1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD1
    postValue = IO_RD1_GetValue();
    </code>

*/
#define IO_RD1_GetValue()         _RD1
/**
  @Summary
    Configures the GPIO pin, RD1, as an input.

  @Description
    Configures the GPIO pin, RD1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD1 as an input
    IO_RD1_SetDigitalInput();
    </code>

*/
#define IO_RD1_SetDigitalInput()  _TRISD1 = 1
/**
  @Summary
    Configures the GPIO pin, RD1, as an output.

  @Description
    Configures the GPIO pin, RD1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD1 as an output
    IO_RD1_SetDigitalOutput();
    </code>

*/
#define IO_RD1_SetDigitalOutput() _TRISD1 = 0
/**
  @Summary
    Sets the GPIO pin, RD10, high using LATD10.

  @Description
    Sets the GPIO pin, RD10, high using LATD10.

  @Preconditions
    The RD10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD10 high (1)
    IO_RD10_SetHigh();
    </code>

*/
#define IO_RD10_SetHigh()          _LATD10 = 1
/**
  @Summary
    Sets the GPIO pin, RD10, low using LATD10.

  @Description
    Sets the GPIO pin, RD10, low using LATD10.

  @Preconditions
    The RD10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD10 low (0)
    IO_RD10_SetLow();
    </code>

*/
#define IO_RD10_SetLow()           _LATD10 = 0
/**
  @Summary
    Toggles the GPIO pin, RD10, using LATD10.

  @Description
    Toggles the GPIO pin, RD10, using LATD10.

  @Preconditions
    The RD10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD10
    IO_RD10_Toggle();
    </code>

*/
#define IO_RD10_Toggle()           _LATD10 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD10.

  @Description
    Reads the value of the GPIO pin, RD10.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD10
    postValue = IO_RD10_GetValue();
    </code>

*/
#define IO_RD10_GetValue()         _RD10
/**
  @Summary
    Configures the GPIO pin, RD10, as an input.

  @Description
    Configures the GPIO pin, RD10, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD10 as an input
    IO_RD10_SetDigitalInput();
    </code>

*/
#define IO_RD10_SetDigitalInput()  _TRISD10 = 1
/**
  @Summary
    Configures the GPIO pin, RD10, as an output.

  @Description
    Configures the GPIO pin, RD10, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD10 as an output
    IO_RD10_SetDigitalOutput();
    </code>

*/
#define IO_RD10_SetDigitalOutput() _TRISD10 = 0
/**
  @Summary
    Sets the GPIO pin, RD11, high using LATD11.

  @Description
    Sets the GPIO pin, RD11, high using LATD11.

  @Preconditions
    The RD11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD11 high (1)
    IO_BTN_UP_VOLT_SetHigh();
    </code>

*/
#define IO_BTN_UP_VOLT_SetHigh()          _LATD11 = 1
/**
  @Summary
    Sets the GPIO pin, RD11, low using LATD11.

  @Description
    Sets the GPIO pin, RD11, low using LATD11.

  @Preconditions
    The RD11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD11 low (0)
    IO_BTN_UP_VOLT_SetLow();
    </code>

*/
#define IO_BTN_UP_VOLT_SetLow()           _LATD11 = 0
/**
  @Summary
    Toggles the GPIO pin, RD11, using LATD11.

  @Description
    Toggles the GPIO pin, RD11, using LATD11.

  @Preconditions
    The RD11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD11
    IO_BTN_UP_VOLT_Toggle();
    </code>

*/
#define IO_BTN_UP_VOLT_Toggle()           _LATD11 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD11.

  @Description
    Reads the value of the GPIO pin, RD11.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD11
    postValue = IO_BTN_UP_VOLT_GetValue();
    </code>

*/
#define IO_BTN_UP_VOLT_GetValue()         _RD11
/**
  @Summary
    Configures the GPIO pin, RD11, as an input.

  @Description
    Configures the GPIO pin, RD11, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD11 as an input
    IO_BTN_UP_VOLT_SetDigitalInput();
    </code>

*/
#define IO_BTN_UP_VOLT_SetDigitalInput()  _TRISD11 = 1
/**
  @Summary
    Configures the GPIO pin, RD11, as an output.

  @Description
    Configures the GPIO pin, RD11, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD11 as an output
    IO_BTN_UP_VOLT_SetDigitalOutput();
    </code>

*/
#define IO_BTN_UP_VOLT_SetDigitalOutput() _TRISD11 = 0
/**
  @Summary
    Sets the GPIO pin, RD14, high using LATD14.

  @Description
    Sets the GPIO pin, RD14, high using LATD14.

  @Preconditions
    The RD14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD14 high (1)
    IO_RD14_SetHigh();
    </code>

*/
#define IO_RD14_SetHigh()          _LATD14 = 1
/**
  @Summary
    Sets the GPIO pin, RD14, low using LATD14.

  @Description
    Sets the GPIO pin, RD14, low using LATD14.

  @Preconditions
    The RD14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD14 low (0)
    IO_RD14_SetLow();
    </code>

*/
#define IO_RD14_SetLow()           _LATD14 = 0
/**
  @Summary
    Toggles the GPIO pin, RD14, using LATD14.

  @Description
    Toggles the GPIO pin, RD14, using LATD14.

  @Preconditions
    The RD14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD14
    IO_RD14_Toggle();
    </code>

*/
#define IO_RD14_Toggle()           _LATD14 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD14.

  @Description
    Reads the value of the GPIO pin, RD14.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD14
    postValue = IO_RD14_GetValue();
    </code>

*/
#define IO_RD14_GetValue()         _RD14
/**
  @Summary
    Configures the GPIO pin, RD14, as an input.

  @Description
    Configures the GPIO pin, RD14, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD14 as an input
    IO_RD14_SetDigitalInput();
    </code>

*/
#define IO_RD14_SetDigitalInput()  _TRISD14 = 1
/**
  @Summary
    Configures the GPIO pin, RD14, as an output.

  @Description
    Configures the GPIO pin, RD14, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD14 as an output
    IO_RD14_SetDigitalOutput();
    </code>

*/
#define IO_RD14_SetDigitalOutput() _TRISD14 = 0
/**
  @Summary
    Sets the GPIO pin, RD15, high using LATD15.

  @Description
    Sets the GPIO pin, RD15, high using LATD15.

  @Preconditions
    The RD15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD15 high (1)
    IO_RD15_SetHigh();
    </code>

*/
#define IO_RD15_SetHigh()          _LATD15 = 1
/**
  @Summary
    Sets the GPIO pin, RD15, low using LATD15.

  @Description
    Sets the GPIO pin, RD15, low using LATD15.

  @Preconditions
    The RD15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD15 low (0)
    IO_RD15_SetLow();
    </code>

*/
#define IO_RD15_SetLow()           _LATD15 = 0
/**
  @Summary
    Toggles the GPIO pin, RD15, using LATD15.

  @Description
    Toggles the GPIO pin, RD15, using LATD15.

  @Preconditions
    The RD15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD15
    IO_RD15_Toggle();
    </code>

*/
#define IO_RD15_Toggle()           _LATD15 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD15.

  @Description
    Reads the value of the GPIO pin, RD15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD15
    postValue = IO_RD15_GetValue();
    </code>

*/
#define IO_RD15_GetValue()         _RD15
/**
  @Summary
    Configures the GPIO pin, RD15, as an input.

  @Description
    Configures the GPIO pin, RD15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD15 as an input
    IO_RD15_SetDigitalInput();
    </code>

*/
#define IO_RD15_SetDigitalInput()  _TRISD15 = 1
/**
  @Summary
    Configures the GPIO pin, RD15, as an output.

  @Description
    Configures the GPIO pin, RD15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD15 as an output
    IO_RD15_SetDigitalOutput();
    </code>

*/
#define IO_RD15_SetDigitalOutput() _TRISD15 = 0
/**
  @Summary
    Sets the GPIO pin, RD2, high using LATD2.

  @Description
    Sets the GPIO pin, RD2, high using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD2 high (1)
    IO_RD2_SetHigh();
    </code>

*/
#define IO_RD2_SetHigh()          _LATD2 = 1
/**
  @Summary
    Sets the GPIO pin, RD2, low using LATD2.

  @Description
    Sets the GPIO pin, RD2, low using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD2 low (0)
    IO_RD2_SetLow();
    </code>

*/
#define IO_RD2_SetLow()           _LATD2 = 0
/**
  @Summary
    Toggles the GPIO pin, RD2, using LATD2.

  @Description
    Toggles the GPIO pin, RD2, using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD2
    IO_RD2_Toggle();
    </code>

*/
#define IO_RD2_Toggle()           _LATD2 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD2.

  @Description
    Reads the value of the GPIO pin, RD2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD2
    postValue = IO_RD2_GetValue();
    </code>

*/
#define IO_RD2_GetValue()         _RD2
/**
  @Summary
    Configures the GPIO pin, RD2, as an input.

  @Description
    Configures the GPIO pin, RD2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD2 as an input
    IO_RD2_SetDigitalInput();
    </code>

*/
#define IO_RD2_SetDigitalInput()  _TRISD2 = 1
/**
  @Summary
    Configures the GPIO pin, RD2, as an output.

  @Description
    Configures the GPIO pin, RD2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD2 as an output
    IO_RD2_SetDigitalOutput();
    </code>

*/
#define IO_RD2_SetDigitalOutput() _TRISD2 = 0
/**
  @Summary
    Sets the GPIO pin, RD3, high using LATD3.

  @Description
    Sets the GPIO pin, RD3, high using LATD3.

  @Preconditions
    The RD3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD3 high (1)
    IO_RD3_SetHigh();
    </code>

*/
#define IO_RD3_SetHigh()          _LATD3 = 1
/**
  @Summary
    Sets the GPIO pin, RD3, low using LATD3.

  @Description
    Sets the GPIO pin, RD3, low using LATD3.

  @Preconditions
    The RD3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD3 low (0)
    IO_RD3_SetLow();
    </code>

*/
#define IO_RD3_SetLow()           _LATD3 = 0
/**
  @Summary
    Toggles the GPIO pin, RD3, using LATD3.

  @Description
    Toggles the GPIO pin, RD3, using LATD3.

  @Preconditions
    The RD3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD3
    IO_RD3_Toggle();
    </code>

*/
#define IO_RD3_Toggle()           _LATD3 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD3.

  @Description
    Reads the value of the GPIO pin, RD3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD3
    postValue = IO_RD3_GetValue();
    </code>

*/
#define IO_RD3_GetValue()         _RD3
/**
  @Summary
    Configures the GPIO pin, RD3, as an input.

  @Description
    Configures the GPIO pin, RD3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD3 as an input
    IO_RD3_SetDigitalInput();
    </code>

*/
#define IO_RD3_SetDigitalInput()  _TRISD3 = 1
/**
  @Summary
    Configures the GPIO pin, RD3, as an output.

  @Description
    Configures the GPIO pin, RD3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD3 as an output
    IO_RD3_SetDigitalOutput();
    </code>

*/
#define IO_RD3_SetDigitalOutput() _TRISD3 = 0
/**
  @Summary
    Sets the GPIO pin, RD4, high using LATD4.

  @Description
    Sets the GPIO pin, RD4, high using LATD4.

  @Preconditions
    The RD4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD4 high (1)
    IO_LCD_E_SetHigh();
    </code>

*/
#define IO_LCD_E_SetHigh()          _LATD4 = 1
/**
  @Summary
    Sets the GPIO pin, RD4, low using LATD4.

  @Description
    Sets the GPIO pin, RD4, low using LATD4.

  @Preconditions
    The RD4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD4 low (0)
    IO_LCD_E_SetLow();
    </code>

*/
#define IO_LCD_E_SetLow()           _LATD4 = 0
/**
  @Summary
    Toggles the GPIO pin, RD4, using LATD4.

  @Description
    Toggles the GPIO pin, RD4, using LATD4.

  @Preconditions
    The RD4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD4
    IO_LCD_E_Toggle();
    </code>

*/
#define IO_LCD_E_Toggle()           _LATD4 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD4.

  @Description
    Reads the value of the GPIO pin, RD4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD4
    postValue = IO_LCD_E_GetValue();
    </code>

*/
#define IO_LCD_E_GetValue()         _RD4
/**
  @Summary
    Configures the GPIO pin, RD4, as an input.

  @Description
    Configures the GPIO pin, RD4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD4 as an input
    IO_LCD_E_SetDigitalInput();
    </code>

*/
#define IO_LCD_E_SetDigitalInput()  _TRISD4 = 1
/**
  @Summary
    Configures the GPIO pin, RD4, as an output.

  @Description
    Configures the GPIO pin, RD4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD4 as an output
    IO_LCD_E_SetDigitalOutput();
    </code>

*/
#define IO_LCD_E_SetDigitalOutput() _TRISD4 = 0
/**
  @Summary
    Sets the GPIO pin, RD5, high using LATD5.

  @Description
    Sets the GPIO pin, RD5, high using LATD5.

  @Preconditions
    The RD5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD5 high (1)
    IO_LCD_RW_SetHigh();
    </code>

*/
#define IO_LCD_RW_SetHigh()          _LATD5 = 1
/**
  @Summary
    Sets the GPIO pin, RD5, low using LATD5.

  @Description
    Sets the GPIO pin, RD5, low using LATD5.

  @Preconditions
    The RD5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD5 low (0)
    IO_LCD_RW_SetLow();
    </code>

*/
#define IO_LCD_RW_SetLow()           _LATD5 = 0
/**
  @Summary
    Toggles the GPIO pin, RD5, using LATD5.

  @Description
    Toggles the GPIO pin, RD5, using LATD5.

  @Preconditions
    The RD5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD5
    IO_LCD_RW_Toggle();
    </code>

*/
#define IO_LCD_RW_Toggle()           _LATD5 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD5.

  @Description
    Reads the value of the GPIO pin, RD5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD5
    postValue = IO_LCD_RW_GetValue();
    </code>

*/
#define IO_LCD_RW_GetValue()         _RD5
/**
  @Summary
    Configures the GPIO pin, RD5, as an input.

  @Description
    Configures the GPIO pin, RD5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD5 as an input
    IO_LCD_RW_SetDigitalInput();
    </code>

*/
#define IO_LCD_RW_SetDigitalInput()  _TRISD5 = 1
/**
  @Summary
    Configures the GPIO pin, RD5, as an output.

  @Description
    Configures the GPIO pin, RD5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD5 as an output
    IO_LCD_RW_SetDigitalOutput();
    </code>

*/
#define IO_LCD_RW_SetDigitalOutput() _TRISD5 = 0
/**
  @Summary
    Sets the GPIO pin, RD6, high using LATD6.

  @Description
    Sets the GPIO pin, RD6, high using LATD6.

  @Preconditions
    The RD6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD6 high (1)
    IO_RD6_SetHigh();
    </code>

*/
#define IO_RD6_SetHigh()          _LATD6 = 1
/**
  @Summary
    Sets the GPIO pin, RD6, low using LATD6.

  @Description
    Sets the GPIO pin, RD6, low using LATD6.

  @Preconditions
    The RD6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD6 low (0)
    IO_RD6_SetLow();
    </code>

*/
#define IO_RD6_SetLow()           _LATD6 = 0
/**
  @Summary
    Toggles the GPIO pin, RD6, using LATD6.

  @Description
    Toggles the GPIO pin, RD6, using LATD6.

  @Preconditions
    The RD6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD6
    IO_RD6_Toggle();
    </code>

*/
#define IO_RD6_Toggle()           _LATD6 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD6.

  @Description
    Reads the value of the GPIO pin, RD6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD6
    postValue = IO_RD6_GetValue();
    </code>

*/
#define IO_RD6_GetValue()         _RD6
/**
  @Summary
    Configures the GPIO pin, RD6, as an input.

  @Description
    Configures the GPIO pin, RD6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD6 as an input
    IO_RD6_SetDigitalInput();
    </code>

*/
#define IO_RD6_SetDigitalInput()  _TRISD6 = 1
/**
  @Summary
    Configures the GPIO pin, RD6, as an output.

  @Description
    Configures the GPIO pin, RD6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD6 as an output
    IO_RD6_SetDigitalOutput();
    </code>

*/
#define IO_RD6_SetDigitalOutput() _TRISD6 = 0
/**
  @Summary
    Sets the GPIO pin, RD7, high using LATD7.

  @Description
    Sets the GPIO pin, RD7, high using LATD7.

  @Preconditions
    The RD7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD7 high (1)
    IO_RD7_SetHigh();
    </code>

*/
#define IO_RD7_SetHigh()          _LATD7 = 1
/**
  @Summary
    Sets the GPIO pin, RD7, low using LATD7.

  @Description
    Sets the GPIO pin, RD7, low using LATD7.

  @Preconditions
    The RD7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD7 low (0)
    IO_RD7_SetLow();
    </code>

*/
#define IO_RD7_SetLow()           _LATD7 = 0
/**
  @Summary
    Toggles the GPIO pin, RD7, using LATD7.

  @Description
    Toggles the GPIO pin, RD7, using LATD7.

  @Preconditions
    The RD7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD7
    IO_RD7_Toggle();
    </code>

*/
#define IO_RD7_Toggle()           _LATD7 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD7.

  @Description
    Reads the value of the GPIO pin, RD7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD7
    postValue = IO_RD7_GetValue();
    </code>

*/
#define IO_RD7_GetValue()         _RD7
/**
  @Summary
    Configures the GPIO pin, RD7, as an input.

  @Description
    Configures the GPIO pin, RD7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD7 as an input
    IO_RD7_SetDigitalInput();
    </code>

*/
#define IO_RD7_SetDigitalInput()  _TRISD7 = 1
/**
  @Summary
    Configures the GPIO pin, RD7, as an output.

  @Description
    Configures the GPIO pin, RD7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD7 as an output
    IO_RD7_SetDigitalOutput();
    </code>

*/
#define IO_RD7_SetDigitalOutput() _TRISD7 = 0
/**
  @Summary
    Sets the GPIO pin, RD8, high using LATD8.

  @Description
    Sets the GPIO pin, RD8, high using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD8 high (1)
    IO_RD8_SetHigh();
    </code>

*/
#define IO_RD8_SetHigh()          _LATD8 = 1
/**
  @Summary
    Sets the GPIO pin, RD8, low using LATD8.

  @Description
    Sets the GPIO pin, RD8, low using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD8 low (0)
    IO_RD8_SetLow();
    </code>

*/
#define IO_RD8_SetLow()           _LATD8 = 0
/**
  @Summary
    Toggles the GPIO pin, RD8, using LATD8.

  @Description
    Toggles the GPIO pin, RD8, using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD8
    IO_RD8_Toggle();
    </code>

*/
#define IO_RD8_Toggle()           _LATD8 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD8.

  @Description
    Reads the value of the GPIO pin, RD8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD8
    postValue = IO_RD8_GetValue();
    </code>

*/
#define IO_RD8_GetValue()         _RD8
/**
  @Summary
    Configures the GPIO pin, RD8, as an input.

  @Description
    Configures the GPIO pin, RD8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD8 as an input
    IO_RD8_SetDigitalInput();
    </code>

*/
#define IO_RD8_SetDigitalInput()  _TRISD8 = 1
/**
  @Summary
    Configures the GPIO pin, RD8, as an output.

  @Description
    Configures the GPIO pin, RD8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD8 as an output
    IO_RD8_SetDigitalOutput();
    </code>

*/
#define IO_RD8_SetDigitalOutput() _TRISD8 = 0
/**
  @Summary
    Sets the GPIO pin, RD9, high using LATD9.

  @Description
    Sets the GPIO pin, RD9, high using LATD9.

  @Preconditions
    The RD9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD9 high (1)
    IO_RD9_SetHigh();
    </code>

*/
#define IO_RD9_SetHigh()          _LATD9 = 1
/**
  @Summary
    Sets the GPIO pin, RD9, low using LATD9.

  @Description
    Sets the GPIO pin, RD9, low using LATD9.

  @Preconditions
    The RD9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD9 low (0)
    IO_RD9_SetLow();
    </code>

*/
#define IO_RD9_SetLow()           _LATD9 = 0
/**
  @Summary
    Toggles the GPIO pin, RD9, using LATD9.

  @Description
    Toggles the GPIO pin, RD9, using LATD9.

  @Preconditions
    The RD9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD9
    IO_RD9_Toggle();
    </code>

*/
#define IO_RD9_Toggle()           _LATD9 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD9.

  @Description
    Reads the value of the GPIO pin, RD9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD9
    postValue = IO_RD9_GetValue();
    </code>

*/
#define IO_RD9_GetValue()         _RD9
/**
  @Summary
    Configures the GPIO pin, RD9, as an input.

  @Description
    Configures the GPIO pin, RD9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD9 as an input
    IO_RD9_SetDigitalInput();
    </code>

*/
#define IO_RD9_SetDigitalInput()  _TRISD9 = 1
/**
  @Summary
    Configures the GPIO pin, RD9, as an output.

  @Description
    Configures the GPIO pin, RD9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD9 as an output
    IO_RD9_SetDigitalOutput();
    </code>

*/
#define IO_RD9_SetDigitalOutput() _TRISD9 = 0
/**
  @Summary
    Sets the GPIO pin, RE0, high using LATE0.

  @Description
    Sets the GPIO pin, RE0, high using LATE0.

  @Preconditions
    The RE0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE0 high (1)
    IO_LCD_DB0_SetHigh();
    </code>

*/
#define IO_LCD_DB0_SetHigh()          _LATE0 = 1
/**
  @Summary
    Sets the GPIO pin, RE0, low using LATE0.

  @Description
    Sets the GPIO pin, RE0, low using LATE0.

  @Preconditions
    The RE0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE0 low (0)
    IO_LCD_DB0_SetLow();
    </code>

*/
#define IO_LCD_DB0_SetLow()           _LATE0 = 0
/**
  @Summary
    Toggles the GPIO pin, RE0, using LATE0.

  @Description
    Toggles the GPIO pin, RE0, using LATE0.

  @Preconditions
    The RE0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE0
    IO_LCD_DB0_Toggle();
    </code>

*/
#define IO_LCD_DB0_Toggle()           _LATE0 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE0.

  @Description
    Reads the value of the GPIO pin, RE0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE0
    postValue = IO_LCD_DB0_GetValue();
    </code>

*/
#define IO_LCD_DB0_GetValue()         _RE0
/**
  @Summary
    Configures the GPIO pin, RE0, as an input.

  @Description
    Configures the GPIO pin, RE0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE0 as an input
    IO_LCD_DB0_SetDigitalInput();
    </code>

*/
#define IO_LCD_DB0_SetDigitalInput()  _TRISE0 = 1
/**
  @Summary
    Configures the GPIO pin, RE0, as an output.

  @Description
    Configures the GPIO pin, RE0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE0 as an output
    IO_LCD_DB0_SetDigitalOutput();
    </code>

*/
#define IO_LCD_DB0_SetDigitalOutput() _TRISE0 = 0
/**
  @Summary
    Sets the GPIO pin, RE1, high using LATE1.

  @Description
    Sets the GPIO pin, RE1, high using LATE1.

  @Preconditions
    The RE1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE1 high (1)
    IO_LCD_DB1_SetHigh();
    </code>

*/
#define IO_LCD_DB1_SetHigh()          _LATE1 = 1
/**
  @Summary
    Sets the GPIO pin, RE1, low using LATE1.

  @Description
    Sets the GPIO pin, RE1, low using LATE1.

  @Preconditions
    The RE1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE1 low (0)
    IO_LCD_DB1_SetLow();
    </code>

*/
#define IO_LCD_DB1_SetLow()           _LATE1 = 0
/**
  @Summary
    Toggles the GPIO pin, RE1, using LATE1.

  @Description
    Toggles the GPIO pin, RE1, using LATE1.

  @Preconditions
    The RE1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE1
    IO_LCD_DB1_Toggle();
    </code>

*/
#define IO_LCD_DB1_Toggle()           _LATE1 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE1.

  @Description
    Reads the value of the GPIO pin, RE1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE1
    postValue = IO_LCD_DB1_GetValue();
    </code>

*/
#define IO_LCD_DB1_GetValue()         _RE1
/**
  @Summary
    Configures the GPIO pin, RE1, as an input.

  @Description
    Configures the GPIO pin, RE1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE1 as an input
    IO_LCD_DB1_SetDigitalInput();
    </code>

*/
#define IO_LCD_DB1_SetDigitalInput()  _TRISE1 = 1
/**
  @Summary
    Configures the GPIO pin, RE1, as an output.

  @Description
    Configures the GPIO pin, RE1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE1 as an output
    IO_LCD_DB1_SetDigitalOutput();
    </code>

*/
#define IO_LCD_DB1_SetDigitalOutput() _TRISE1 = 0
/**
  @Summary
    Sets the GPIO pin, RE2, high using LATE2.

  @Description
    Sets the GPIO pin, RE2, high using LATE2.

  @Preconditions
    The RE2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE2 high (1)
    IO_LCD_DB2_SetHigh();
    </code>

*/
#define IO_LCD_DB2_SetHigh()          _LATE2 = 1
/**
  @Summary
    Sets the GPIO pin, RE2, low using LATE2.

  @Description
    Sets the GPIO pin, RE2, low using LATE2.

  @Preconditions
    The RE2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE2 low (0)
    IO_LCD_DB2_SetLow();
    </code>

*/
#define IO_LCD_DB2_SetLow()           _LATE2 = 0
/**
  @Summary
    Toggles the GPIO pin, RE2, using LATE2.

  @Description
    Toggles the GPIO pin, RE2, using LATE2.

  @Preconditions
    The RE2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE2
    IO_LCD_DB2_Toggle();
    </code>

*/
#define IO_LCD_DB2_Toggle()           _LATE2 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE2.

  @Description
    Reads the value of the GPIO pin, RE2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE2
    postValue = IO_LCD_DB2_GetValue();
    </code>

*/
#define IO_LCD_DB2_GetValue()         _RE2
/**
  @Summary
    Configures the GPIO pin, RE2, as an input.

  @Description
    Configures the GPIO pin, RE2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE2 as an input
    IO_LCD_DB2_SetDigitalInput();
    </code>

*/
#define IO_LCD_DB2_SetDigitalInput()  _TRISE2 = 1
/**
  @Summary
    Configures the GPIO pin, RE2, as an output.

  @Description
    Configures the GPIO pin, RE2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE2 as an output
    IO_LCD_DB2_SetDigitalOutput();
    </code>

*/
#define IO_LCD_DB2_SetDigitalOutput() _TRISE2 = 0
/**
  @Summary
    Sets the GPIO pin, RE3, high using LATE3.

  @Description
    Sets the GPIO pin, RE3, high using LATE3.

  @Preconditions
    The RE3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE3 high (1)
    IO_LCD_DB3_SetHigh();
    </code>

*/
#define IO_LCD_DB3_SetHigh()          _LATE3 = 1
/**
  @Summary
    Sets the GPIO pin, RE3, low using LATE3.

  @Description
    Sets the GPIO pin, RE3, low using LATE3.

  @Preconditions
    The RE3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE3 low (0)
    IO_LCD_DB3_SetLow();
    </code>

*/
#define IO_LCD_DB3_SetLow()           _LATE3 = 0
/**
  @Summary
    Toggles the GPIO pin, RE3, using LATE3.

  @Description
    Toggles the GPIO pin, RE3, using LATE3.

  @Preconditions
    The RE3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE3
    IO_LCD_DB3_Toggle();
    </code>

*/
#define IO_LCD_DB3_Toggle()           _LATE3 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE3.

  @Description
    Reads the value of the GPIO pin, RE3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE3
    postValue = IO_LCD_DB3_GetValue();
    </code>

*/
#define IO_LCD_DB3_GetValue()         _RE3
/**
  @Summary
    Configures the GPIO pin, RE3, as an input.

  @Description
    Configures the GPIO pin, RE3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE3 as an input
    IO_LCD_DB3_SetDigitalInput();
    </code>

*/
#define IO_LCD_DB3_SetDigitalInput()  _TRISE3 = 1
/**
  @Summary
    Configures the GPIO pin, RE3, as an output.

  @Description
    Configures the GPIO pin, RE3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE3 as an output
    IO_LCD_DB3_SetDigitalOutput();
    </code>

*/
#define IO_LCD_DB3_SetDigitalOutput() _TRISE3 = 0
/**
  @Summary
    Sets the GPIO pin, RE4, high using LATE4.

  @Description
    Sets the GPIO pin, RE4, high using LATE4.

  @Preconditions
    The RE4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE4 high (1)
    IO_LCD_DB4_SetHigh();
    </code>

*/
#define IO_LCD_DB4_SetHigh()          _LATE4 = 1
/**
  @Summary
    Sets the GPIO pin, RE4, low using LATE4.

  @Description
    Sets the GPIO pin, RE4, low using LATE4.

  @Preconditions
    The RE4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE4 low (0)
    IO_LCD_DB4_SetLow();
    </code>

*/
#define IO_LCD_DB4_SetLow()           _LATE4 = 0
/**
  @Summary
    Toggles the GPIO pin, RE4, using LATE4.

  @Description
    Toggles the GPIO pin, RE4, using LATE4.

  @Preconditions
    The RE4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE4
    IO_LCD_DB4_Toggle();
    </code>

*/
#define IO_LCD_DB4_Toggle()           _LATE4 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE4.

  @Description
    Reads the value of the GPIO pin, RE4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE4
    postValue = IO_LCD_DB4_GetValue();
    </code>

*/
#define IO_LCD_DB4_GetValue()         _RE4
/**
  @Summary
    Configures the GPIO pin, RE4, as an input.

  @Description
    Configures the GPIO pin, RE4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE4 as an input
    IO_LCD_DB4_SetDigitalInput();
    </code>

*/
#define IO_LCD_DB4_SetDigitalInput()  _TRISE4 = 1
/**
  @Summary
    Configures the GPIO pin, RE4, as an output.

  @Description
    Configures the GPIO pin, RE4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE4 as an output
    IO_LCD_DB4_SetDigitalOutput();
    </code>

*/
#define IO_LCD_DB4_SetDigitalOutput() _TRISE4 = 0
/**
  @Summary
    Sets the GPIO pin, RE5, high using LATE5.

  @Description
    Sets the GPIO pin, RE5, high using LATE5.

  @Preconditions
    The RE5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE5 high (1)
    IO_LCD_DB5_SetHigh();
    </code>

*/
#define IO_LCD_DB5_SetHigh()          _LATE5 = 1
/**
  @Summary
    Sets the GPIO pin, RE5, low using LATE5.

  @Description
    Sets the GPIO pin, RE5, low using LATE5.

  @Preconditions
    The RE5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE5 low (0)
    IO_LCD_DB5_SetLow();
    </code>

*/
#define IO_LCD_DB5_SetLow()           _LATE5 = 0
/**
  @Summary
    Toggles the GPIO pin, RE5, using LATE5.

  @Description
    Toggles the GPIO pin, RE5, using LATE5.

  @Preconditions
    The RE5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE5
    IO_LCD_DB5_Toggle();
    </code>

*/
#define IO_LCD_DB5_Toggle()           _LATE5 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE5.

  @Description
    Reads the value of the GPIO pin, RE5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE5
    postValue = IO_LCD_DB5_GetValue();
    </code>

*/
#define IO_LCD_DB5_GetValue()         _RE5
/**
  @Summary
    Configures the GPIO pin, RE5, as an input.

  @Description
    Configures the GPIO pin, RE5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE5 as an input
    IO_LCD_DB5_SetDigitalInput();
    </code>

*/
#define IO_LCD_DB5_SetDigitalInput()  _TRISE5 = 1
/**
  @Summary
    Configures the GPIO pin, RE5, as an output.

  @Description
    Configures the GPIO pin, RE5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE5 as an output
    IO_LCD_DB5_SetDigitalOutput();
    </code>

*/
#define IO_LCD_DB5_SetDigitalOutput() _TRISE5 = 0
/**
  @Summary
    Sets the GPIO pin, RE6, high using LATE6.

  @Description
    Sets the GPIO pin, RE6, high using LATE6.

  @Preconditions
    The RE6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE6 high (1)
    IO_LCD_DB6_SetHigh();
    </code>

*/
#define IO_LCD_DB6_SetHigh()          _LATE6 = 1
/**
  @Summary
    Sets the GPIO pin, RE6, low using LATE6.

  @Description
    Sets the GPIO pin, RE6, low using LATE6.

  @Preconditions
    The RE6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE6 low (0)
    IO_LCD_DB6_SetLow();
    </code>

*/
#define IO_LCD_DB6_SetLow()           _LATE6 = 0
/**
  @Summary
    Toggles the GPIO pin, RE6, using LATE6.

  @Description
    Toggles the GPIO pin, RE6, using LATE6.

  @Preconditions
    The RE6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE6
    IO_LCD_DB6_Toggle();
    </code>

*/
#define IO_LCD_DB6_Toggle()           _LATE6 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE6.

  @Description
    Reads the value of the GPIO pin, RE6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE6
    postValue = IO_LCD_DB6_GetValue();
    </code>

*/
#define IO_LCD_DB6_GetValue()         _RE6
/**
  @Summary
    Configures the GPIO pin, RE6, as an input.

  @Description
    Configures the GPIO pin, RE6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE6 as an input
    IO_LCD_DB6_SetDigitalInput();
    </code>

*/
#define IO_LCD_DB6_SetDigitalInput()  _TRISE6 = 1
/**
  @Summary
    Configures the GPIO pin, RE6, as an output.

  @Description
    Configures the GPIO pin, RE6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE6 as an output
    IO_LCD_DB6_SetDigitalOutput();
    </code>

*/
#define IO_LCD_DB6_SetDigitalOutput() _TRISE6 = 0
/**
  @Summary
    Sets the GPIO pin, RE7, high using LATE7.

  @Description
    Sets the GPIO pin, RE7, high using LATE7.

  @Preconditions
    The RE7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE7 high (1)
    IO_LCD_DB7_SetHigh();
    </code>

*/
#define IO_LCD_DB7_SetHigh()          _LATE7 = 1
/**
  @Summary
    Sets the GPIO pin, RE7, low using LATE7.

  @Description
    Sets the GPIO pin, RE7, low using LATE7.

  @Preconditions
    The RE7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE7 low (0)
    IO_LCD_DB7_SetLow();
    </code>

*/
#define IO_LCD_DB7_SetLow()           _LATE7 = 0
/**
  @Summary
    Toggles the GPIO pin, RE7, using LATE7.

  @Description
    Toggles the GPIO pin, RE7, using LATE7.

  @Preconditions
    The RE7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE7
    IO_LCD_DB7_Toggle();
    </code>

*/
#define IO_LCD_DB7_Toggle()           _LATE7 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE7.

  @Description
    Reads the value of the GPIO pin, RE7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE7
    postValue = IO_LCD_DB7_GetValue();
    </code>

*/
#define IO_LCD_DB7_GetValue()         _RE7
/**
  @Summary
    Configures the GPIO pin, RE7, as an input.

  @Description
    Configures the GPIO pin, RE7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE7 as an input
    IO_LCD_DB7_SetDigitalInput();
    </code>

*/
#define IO_LCD_DB7_SetDigitalInput()  _TRISE7 = 1
/**
  @Summary
    Configures the GPIO pin, RE7, as an output.

  @Description
    Configures the GPIO pin, RE7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE7 as an output
    IO_LCD_DB7_SetDigitalOutput();
    </code>

*/
#define IO_LCD_DB7_SetDigitalOutput() _TRISE7 = 0
/**
  @Summary
    Sets the GPIO pin, RE8, high using LATE8.

  @Description
    Sets the GPIO pin, RE8, high using LATE8.

  @Preconditions
    The RE8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE8 high (1)
    IO_LCD_CS_SetHigh();
    </code>

*/
#define IO_LCD_CS_SetHigh()          _LATE8 = 1
/**
  @Summary
    Sets the GPIO pin, RE8, low using LATE8.

  @Description
    Sets the GPIO pin, RE8, low using LATE8.

  @Preconditions
    The RE8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE8 low (0)
    IO_LCD_CS_SetLow();
    </code>

*/
#define IO_LCD_CS_SetLow()           _LATE8 = 0
/**
  @Summary
    Toggles the GPIO pin, RE8, using LATE8.

  @Description
    Toggles the GPIO pin, RE8, using LATE8.

  @Preconditions
    The RE8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE8
    IO_LCD_CS_Toggle();
    </code>

*/
#define IO_LCD_CS_Toggle()           _LATE8 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE8.

  @Description
    Reads the value of the GPIO pin, RE8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE8
    postValue = IO_LCD_CS_GetValue();
    </code>

*/
#define IO_LCD_CS_GetValue()         _RE8
/**
  @Summary
    Configures the GPIO pin, RE8, as an input.

  @Description
    Configures the GPIO pin, RE8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE8 as an input
    IO_LCD_CS_SetDigitalInput();
    </code>

*/
#define IO_LCD_CS_SetDigitalInput()  _TRISE8 = 1
/**
  @Summary
    Configures the GPIO pin, RE8, as an output.

  @Description
    Configures the GPIO pin, RE8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE8 as an output
    IO_LCD_CS_SetDigitalOutput();
    </code>

*/
#define IO_LCD_CS_SetDigitalOutput() _TRISE8 = 0
/**
  @Summary
    Sets the GPIO pin, RE9, high using LATE9.

  @Description
    Sets the GPIO pin, RE9, high using LATE9.

  @Preconditions
    The RE9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE9 high (1)
    IO_BTN_DN_CURR_SetHigh();
    </code>

*/
#define IO_BTN_DN_CURR_SetHigh()          _LATE9 = 1
/**
  @Summary
    Sets the GPIO pin, RE9, low using LATE9.

  @Description
    Sets the GPIO pin, RE9, low using LATE9.

  @Preconditions
    The RE9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE9 low (0)
    IO_BTN_DN_CURR_SetLow();
    </code>

*/
#define IO_BTN_DN_CURR_SetLow()           _LATE9 = 0
/**
  @Summary
    Toggles the GPIO pin, RE9, using LATE9.

  @Description
    Toggles the GPIO pin, RE9, using LATE9.

  @Preconditions
    The RE9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE9
    IO_BTN_DN_CURR_Toggle();
    </code>

*/
#define IO_BTN_DN_CURR_Toggle()           _LATE9 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RE9.

  @Description
    Reads the value of the GPIO pin, RE9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE9
    postValue = IO_BTN_DN_CURR_GetValue();
    </code>

*/
#define IO_BTN_DN_CURR_GetValue()         _RE9
/**
  @Summary
    Configures the GPIO pin, RE9, as an input.

  @Description
    Configures the GPIO pin, RE9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE9 as an input
    IO_BTN_DN_CURR_SetDigitalInput();
    </code>

*/
#define IO_BTN_DN_CURR_SetDigitalInput()  _TRISE9 = 1
/**
  @Summary
    Configures the GPIO pin, RE9, as an output.

  @Description
    Configures the GPIO pin, RE9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE9 as an output
    IO_BTN_DN_CURR_SetDigitalOutput();
    </code>

*/
#define IO_BTN_DN_CURR_SetDigitalOutput() _TRISE9 = 0
/**
  @Summary
    Sets the GPIO pin, RF0, high using LATF0.

  @Description
    Sets the GPIO pin, RF0, high using LATF0.

  @Preconditions
    The RF0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF0 high (1)
    IO_RF0_SetHigh();
    </code>

*/
#define IO_RF0_SetHigh()          _LATF0 = 1
/**
  @Summary
    Sets the GPIO pin, RF0, low using LATF0.

  @Description
    Sets the GPIO pin, RF0, low using LATF0.

  @Preconditions
    The RF0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF0 low (0)
    IO_RF0_SetLow();
    </code>

*/
#define IO_RF0_SetLow()           _LATF0 = 0
/**
  @Summary
    Toggles the GPIO pin, RF0, using LATF0.

  @Description
    Toggles the GPIO pin, RF0, using LATF0.

  @Preconditions
    The RF0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF0
    IO_RF0_Toggle();
    </code>

*/
#define IO_RF0_Toggle()           _LATF0 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RF0.

  @Description
    Reads the value of the GPIO pin, RF0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF0
    postValue = IO_RF0_GetValue();
    </code>

*/
#define IO_RF0_GetValue()         _RF0
/**
  @Summary
    Configures the GPIO pin, RF0, as an input.

  @Description
    Configures the GPIO pin, RF0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF0 as an input
    IO_RF0_SetDigitalInput();
    </code>

*/
#define IO_RF0_SetDigitalInput()  _TRISF0 = 1
/**
  @Summary
    Configures the GPIO pin, RF0, as an output.

  @Description
    Configures the GPIO pin, RF0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF0 as an output
    IO_RF0_SetDigitalOutput();
    </code>

*/
#define IO_RF0_SetDigitalOutput() _TRISF0 = 0
/**
  @Summary
    Sets the GPIO pin, RF1, high using LATF1.

  @Description
    Sets the GPIO pin, RF1, high using LATF1.

  @Preconditions
    The RF1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF1 high (1)
    IO_RF1_SetHigh();
    </code>

*/
#define IO_RF1_SetHigh()          _LATF1 = 1
/**
  @Summary
    Sets the GPIO pin, RF1, low using LATF1.

  @Description
    Sets the GPIO pin, RF1, low using LATF1.

  @Preconditions
    The RF1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF1 low (0)
    IO_RF1_SetLow();
    </code>

*/
#define IO_RF1_SetLow()           _LATF1 = 0
/**
  @Summary
    Toggles the GPIO pin, RF1, using LATF1.

  @Description
    Toggles the GPIO pin, RF1, using LATF1.

  @Preconditions
    The RF1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF1
    IO_RF1_Toggle();
    </code>

*/
#define IO_RF1_Toggle()           _LATF1 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RF1.

  @Description
    Reads the value of the GPIO pin, RF1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF1
    postValue = IO_RF1_GetValue();
    </code>

*/
#define IO_RF1_GetValue()         _RF1
/**
  @Summary
    Configures the GPIO pin, RF1, as an input.

  @Description
    Configures the GPIO pin, RF1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF1 as an input
    IO_RF1_SetDigitalInput();
    </code>

*/
#define IO_RF1_SetDigitalInput()  _TRISF1 = 1
/**
  @Summary
    Configures the GPIO pin, RF1, as an output.

  @Description
    Configures the GPIO pin, RF1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF1 as an output
    IO_RF1_SetDigitalOutput();
    </code>

*/
#define IO_RF1_SetDigitalOutput() _TRISF1 = 0
/**
  @Summary
    Sets the GPIO pin, RF12, high using LATF12.

  @Description
    Sets the GPIO pin, RF12, high using LATF12.

  @Preconditions
    The RF12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF12 high (1)
    IO_RF12_SetHigh();
    </code>

*/
#define IO_RF12_SetHigh()          _LATF12 = 1
/**
  @Summary
    Sets the GPIO pin, RF12, low using LATF12.

  @Description
    Sets the GPIO pin, RF12, low using LATF12.

  @Preconditions
    The RF12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF12 low (0)
    IO_RF12_SetLow();
    </code>

*/
#define IO_RF12_SetLow()           _LATF12 = 0
/**
  @Summary
    Toggles the GPIO pin, RF12, using LATF12.

  @Description
    Toggles the GPIO pin, RF12, using LATF12.

  @Preconditions
    The RF12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF12
    IO_RF12_Toggle();
    </code>

*/
#define IO_RF12_Toggle()           _LATF12 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RF12.

  @Description
    Reads the value of the GPIO pin, RF12.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF12
    postValue = IO_RF12_GetValue();
    </code>

*/
#define IO_RF12_GetValue()         _RF12
/**
  @Summary
    Configures the GPIO pin, RF12, as an input.

  @Description
    Configures the GPIO pin, RF12, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF12 as an input
    IO_RF12_SetDigitalInput();
    </code>

*/
#define IO_RF12_SetDigitalInput()  _TRISF12 = 1
/**
  @Summary
    Configures the GPIO pin, RF12, as an output.

  @Description
    Configures the GPIO pin, RF12, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF12 as an output
    IO_RF12_SetDigitalOutput();
    </code>

*/
#define IO_RF12_SetDigitalOutput() _TRISF12 = 0
/**
  @Summary
    Sets the GPIO pin, RF13, high using LATF13.

  @Description
    Sets the GPIO pin, RF13, high using LATF13.

  @Preconditions
    The RF13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF13 high (1)
    IO_RF13_SetHigh();
    </code>

*/
#define IO_RF13_SetHigh()          _LATF13 = 1
/**
  @Summary
    Sets the GPIO pin, RF13, low using LATF13.

  @Description
    Sets the GPIO pin, RF13, low using LATF13.

  @Preconditions
    The RF13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF13 low (0)
    IO_RF13_SetLow();
    </code>

*/
#define IO_RF13_SetLow()           _LATF13 = 0
/**
  @Summary
    Toggles the GPIO pin, RF13, using LATF13.

  @Description
    Toggles the GPIO pin, RF13, using LATF13.

  @Preconditions
    The RF13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF13
    IO_RF13_Toggle();
    </code>

*/
#define IO_RF13_Toggle()           _LATF13 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RF13.

  @Description
    Reads the value of the GPIO pin, RF13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF13
    postValue = IO_RF13_GetValue();
    </code>

*/
#define IO_RF13_GetValue()         _RF13
/**
  @Summary
    Configures the GPIO pin, RF13, as an input.

  @Description
    Configures the GPIO pin, RF13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF13 as an input
    IO_RF13_SetDigitalInput();
    </code>

*/
#define IO_RF13_SetDigitalInput()  _TRISF13 = 1
/**
  @Summary
    Configures the GPIO pin, RF13, as an output.

  @Description
    Configures the GPIO pin, RF13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF13 as an output
    IO_RF13_SetDigitalOutput();
    </code>

*/
#define IO_RF13_SetDigitalOutput() _TRISF13 = 0
/**
  @Summary
    Sets the GPIO pin, RF2, high using LATF2.

  @Description
    Sets the GPIO pin, RF2, high using LATF2.

  @Preconditions
    The RF2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF2 high (1)
    FLB_AUX_SYNC_SetHigh();
    </code>

*/
#define FLB_AUX_SYNC_SetHigh()          _LATF2 = 1
/**
  @Summary
    Sets the GPIO pin, RF2, low using LATF2.

  @Description
    Sets the GPIO pin, RF2, low using LATF2.

  @Preconditions
    The RF2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF2 low (0)
    FLB_AUX_SYNC_SetLow();
    </code>

*/
#define FLB_AUX_SYNC_SetLow()           _LATF2 = 0
/**
  @Summary
    Toggles the GPIO pin, RF2, using LATF2.

  @Description
    Toggles the GPIO pin, RF2, using LATF2.

  @Preconditions
    The RF2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF2
    FLB_AUX_SYNC_Toggle();
    </code>

*/
#define FLB_AUX_SYNC_Toggle()           _LATF2 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RF2.

  @Description
    Reads the value of the GPIO pin, RF2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF2
    postValue = FLB_AUX_SYNC_GetValue();
    </code>

*/
#define FLB_AUX_SYNC_GetValue()         _RF2
/**
  @Summary
    Configures the GPIO pin, RF2, as an input.

  @Description
    Configures the GPIO pin, RF2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF2 as an input
    FLB_AUX_SYNC_SetDigitalInput();
    </code>

*/
#define FLB_AUX_SYNC_SetDigitalInput()  _TRISF2 = 1
/**
  @Summary
    Configures the GPIO pin, RF2, as an output.

  @Description
    Configures the GPIO pin, RF2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF2 as an output
    FLB_AUX_SYNC_SetDigitalOutput();
    </code>

*/
#define FLB_AUX_SYNC_SetDigitalOutput() _TRISF2 = 0
/**
  @Summary
    Sets the GPIO pin, RF3, high using LATF3.

  @Description
    Sets the GPIO pin, RF3, high using LATF3.

  @Preconditions
    The RF3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF3 high (1)
    FLB_CH2_SYNC_SetHigh();
    </code>

*/
#define FLB_CH2_SYNC_SetHigh()          _LATF3 = 1
/**
  @Summary
    Sets the GPIO pin, RF3, low using LATF3.

  @Description
    Sets the GPIO pin, RF3, low using LATF3.

  @Preconditions
    The RF3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF3 low (0)
    FLB_CH2_SYNC_SetLow();
    </code>

*/
#define FLB_CH2_SYNC_SetLow()           _LATF3 = 0
/**
  @Summary
    Toggles the GPIO pin, RF3, using LATF3.

  @Description
    Toggles the GPIO pin, RF3, using LATF3.

  @Preconditions
    The RF3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF3
    FLB_CH2_SYNC_Toggle();
    </code>

*/
#define FLB_CH2_SYNC_Toggle()           _LATF3 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RF3.

  @Description
    Reads the value of the GPIO pin, RF3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF3
    postValue = FLB_CH2_SYNC_GetValue();
    </code>

*/
#define FLB_CH2_SYNC_GetValue()         _RF3
/**
  @Summary
    Configures the GPIO pin, RF3, as an input.

  @Description
    Configures the GPIO pin, RF3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF3 as an input
    FLB_CH2_SYNC_SetDigitalInput();
    </code>

*/
#define FLB_CH2_SYNC_SetDigitalInput()  _TRISF3 = 1
/**
  @Summary
    Configures the GPIO pin, RF3, as an output.

  @Description
    Configures the GPIO pin, RF3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF3 as an output
    FLB_CH2_SYNC_SetDigitalOutput();
    </code>

*/
#define FLB_CH2_SYNC_SetDigitalOutput() _TRISF3 = 0
/**
  @Summary
    Sets the GPIO pin, RF4, high using LATF4.

  @Description
    Sets the GPIO pin, RF4, high using LATF4.

  @Preconditions
    The RF4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF4 high (1)
    IO_RF4_SetHigh();
    </code>

*/
#define IO_RF4_SetHigh()          _LATF4 = 1
/**
  @Summary
    Sets the GPIO pin, RF4, low using LATF4.

  @Description
    Sets the GPIO pin, RF4, low using LATF4.

  @Preconditions
    The RF4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF4 low (0)
    IO_RF4_SetLow();
    </code>

*/
#define IO_RF4_SetLow()           _LATF4 = 0
/**
  @Summary
    Toggles the GPIO pin, RF4, using LATF4.

  @Description
    Toggles the GPIO pin, RF4, using LATF4.

  @Preconditions
    The RF4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF4
    IO_RF4_Toggle();
    </code>

*/
#define IO_RF4_Toggle()           _LATF4 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RF4.

  @Description
    Reads the value of the GPIO pin, RF4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF4
    postValue = IO_RF4_GetValue();
    </code>

*/
#define IO_RF4_GetValue()         _RF4
/**
  @Summary
    Configures the GPIO pin, RF4, as an input.

  @Description
    Configures the GPIO pin, RF4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF4 as an input
    IO_RF4_SetDigitalInput();
    </code>

*/
#define IO_RF4_SetDigitalInput()  _TRISF4 = 1
/**
  @Summary
    Configures the GPIO pin, RF4, as an output.

  @Description
    Configures the GPIO pin, RF4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF4 as an output
    IO_RF4_SetDigitalOutput();
    </code>

*/
#define IO_RF4_SetDigitalOutput() _TRISF4 = 0
/**
  @Summary
    Sets the GPIO pin, RF7, high using LATF7.

  @Description
    Sets the GPIO pin, RF7, high using LATF7.

  @Preconditions
    The RF7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF7 high (1)
    IO_RF7_SetHigh();
    </code>

*/
#define IO_RF7_SetHigh()          _LATF7 = 1
/**
  @Summary
    Sets the GPIO pin, RF7, low using LATF7.

  @Description
    Sets the GPIO pin, RF7, low using LATF7.

  @Preconditions
    The RF7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF7 low (0)
    IO_RF7_SetLow();
    </code>

*/
#define IO_RF7_SetLow()           _LATF7 = 0
/**
  @Summary
    Toggles the GPIO pin, RF7, using LATF7.

  @Description
    Toggles the GPIO pin, RF7, using LATF7.

  @Preconditions
    The RF7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF7
    IO_RF7_Toggle();
    </code>

*/
#define IO_RF7_Toggle()           _LATF7 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RF7.

  @Description
    Reads the value of the GPIO pin, RF7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF7
    postValue = IO_RF7_GetValue();
    </code>

*/
#define IO_RF7_GetValue()         _RF7
/**
  @Summary
    Configures the GPIO pin, RF7, as an input.

  @Description
    Configures the GPIO pin, RF7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF7 as an input
    IO_RF7_SetDigitalInput();
    </code>

*/
#define IO_RF7_SetDigitalInput()  _TRISF7 = 1
/**
  @Summary
    Configures the GPIO pin, RF7, as an output.

  @Description
    Configures the GPIO pin, RF7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF7 as an output
    IO_RF7_SetDigitalOutput();
    </code>

*/
#define IO_RF7_SetDigitalOutput() _TRISF7 = 0
/**
  @Summary
    Sets the GPIO pin, RF8, high using LATF8.

  @Description
    Sets the GPIO pin, RF8, high using LATF8.

  @Preconditions
    The RF8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF8 high (1)
    IO_RF8_SetHigh();
    </code>

*/
#define IO_RF8_SetHigh()          _LATF8 = 1
/**
  @Summary
    Sets the GPIO pin, RF8, low using LATF8.

  @Description
    Sets the GPIO pin, RF8, low using LATF8.

  @Preconditions
    The RF8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF8 low (0)
    IO_RF8_SetLow();
    </code>

*/
#define IO_RF8_SetLow()           _LATF8 = 0
/**
  @Summary
    Toggles the GPIO pin, RF8, using LATF8.

  @Description
    Toggles the GPIO pin, RF8, using LATF8.

  @Preconditions
    The RF8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF8
    IO_RF8_Toggle();
    </code>

*/
#define IO_RF8_Toggle()           _LATF8 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RF8.

  @Description
    Reads the value of the GPIO pin, RF8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF8
    postValue = IO_RF8_GetValue();
    </code>

*/
#define IO_RF8_GetValue()         _RF8
/**
  @Summary
    Configures the GPIO pin, RF8, as an input.

  @Description
    Configures the GPIO pin, RF8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF8 as an input
    IO_RF8_SetDigitalInput();
    </code>

*/
#define IO_RF8_SetDigitalInput()  _TRISF8 = 1
/**
  @Summary
    Configures the GPIO pin, RF8, as an output.

  @Description
    Configures the GPIO pin, RF8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF8 as an output
    IO_RF8_SetDigitalOutput();
    </code>

*/
#define IO_RF8_SetDigitalOutput() _TRISF8 = 0
/**
  @Summary
    Sets the GPIO pin, RG0, high using LATG0.

  @Description
    Sets the GPIO pin, RG0, high using LATG0.

  @Preconditions
    The RG0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG0 high (1)
    IO_RG0_SetHigh();
    </code>

*/
#define IO_RG0_SetHigh()          _LATG0 = 1
/**
  @Summary
    Sets the GPIO pin, RG0, low using LATG0.

  @Description
    Sets the GPIO pin, RG0, low using LATG0.

  @Preconditions
    The RG0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG0 low (0)
    IO_RG0_SetLow();
    </code>

*/
#define IO_RG0_SetLow()           _LATG0 = 0
/**
  @Summary
    Toggles the GPIO pin, RG0, using LATG0.

  @Description
    Toggles the GPIO pin, RG0, using LATG0.

  @Preconditions
    The RG0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG0
    IO_RG0_Toggle();
    </code>

*/
#define IO_RG0_Toggle()           _LATG0 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG0.

  @Description
    Reads the value of the GPIO pin, RG0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG0
    postValue = IO_RG0_GetValue();
    </code>

*/
#define IO_RG0_GetValue()         _RG0
/**
  @Summary
    Configures the GPIO pin, RG0, as an input.

  @Description
    Configures the GPIO pin, RG0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG0 as an input
    IO_RG0_SetDigitalInput();
    </code>

*/
#define IO_RG0_SetDigitalInput()  _TRISG0 = 1
/**
  @Summary
    Configures the GPIO pin, RG0, as an output.

  @Description
    Configures the GPIO pin, RG0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG0 as an output
    IO_RG0_SetDigitalOutput();
    </code>

*/
#define IO_RG0_SetDigitalOutput() _TRISG0 = 0
/**
  @Summary
    Sets the GPIO pin, RG1, high using LATG1.

  @Description
    Sets the GPIO pin, RG1, high using LATG1.

  @Preconditions
    The RG1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG1 high (1)
    IO_RG1_SetHigh();
    </code>

*/
#define IO_RG1_SetHigh()          _LATG1 = 1
/**
  @Summary
    Sets the GPIO pin, RG1, low using LATG1.

  @Description
    Sets the GPIO pin, RG1, low using LATG1.

  @Preconditions
    The RG1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG1 low (0)
    IO_RG1_SetLow();
    </code>

*/
#define IO_RG1_SetLow()           _LATG1 = 0
/**
  @Summary
    Toggles the GPIO pin, RG1, using LATG1.

  @Description
    Toggles the GPIO pin, RG1, using LATG1.

  @Preconditions
    The RG1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG1
    IO_RG1_Toggle();
    </code>

*/
#define IO_RG1_Toggle()           _LATG1 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG1.

  @Description
    Reads the value of the GPIO pin, RG1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG1
    postValue = IO_RG1_GetValue();
    </code>

*/
#define IO_RG1_GetValue()         _RG1
/**
  @Summary
    Configures the GPIO pin, RG1, as an input.

  @Description
    Configures the GPIO pin, RG1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG1 as an input
    IO_RG1_SetDigitalInput();
    </code>

*/
#define IO_RG1_SetDigitalInput()  _TRISG1 = 1
/**
  @Summary
    Configures the GPIO pin, RG1, as an output.

  @Description
    Configures the GPIO pin, RG1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG1 as an output
    IO_RG1_SetDigitalOutput();
    </code>

*/
#define IO_RG1_SetDigitalOutput() _TRISG1 = 0
/**
  @Summary
    Sets the GPIO pin, RG12, high using LATG12.

  @Description
    Sets the GPIO pin, RG12, high using LATG12.

  @Preconditions
    The RG12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG12 high (1)
    IO_RG12_SetHigh();
    </code>

*/
#define IO_RG12_SetHigh()          _LATG12 = 1
/**
  @Summary
    Sets the GPIO pin, RG12, low using LATG12.

  @Description
    Sets the GPIO pin, RG12, low using LATG12.

  @Preconditions
    The RG12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG12 low (0)
    IO_RG12_SetLow();
    </code>

*/
#define IO_RG12_SetLow()           _LATG12 = 0
/**
  @Summary
    Toggles the GPIO pin, RG12, using LATG12.

  @Description
    Toggles the GPIO pin, RG12, using LATG12.

  @Preconditions
    The RG12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG12
    IO_RG12_Toggle();
    </code>

*/
#define IO_RG12_Toggle()           _LATG12 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG12.

  @Description
    Reads the value of the GPIO pin, RG12.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG12
    postValue = IO_RG12_GetValue();
    </code>

*/
#define IO_RG12_GetValue()         _RG12
/**
  @Summary
    Configures the GPIO pin, RG12, as an input.

  @Description
    Configures the GPIO pin, RG12, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG12 as an input
    IO_RG12_SetDigitalInput();
    </code>

*/
#define IO_RG12_SetDigitalInput()  _TRISG12 = 1
/**
  @Summary
    Configures the GPIO pin, RG12, as an output.

  @Description
    Configures the GPIO pin, RG12, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG12 as an output
    IO_RG12_SetDigitalOutput();
    </code>

*/
#define IO_RG12_SetDigitalOutput() _TRISG12 = 0
/**
  @Summary
    Sets the GPIO pin, RG13, high using LATG13.

  @Description
    Sets the GPIO pin, RG13, high using LATG13.

  @Preconditions
    The RG13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG13 high (1)
    IO_RG13_SetHigh();
    </code>

*/
#define IO_RG13_SetHigh()          _LATG13 = 1
/**
  @Summary
    Sets the GPIO pin, RG13, low using LATG13.

  @Description
    Sets the GPIO pin, RG13, low using LATG13.

  @Preconditions
    The RG13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG13 low (0)
    IO_RG13_SetLow();
    </code>

*/
#define IO_RG13_SetLow()           _LATG13 = 0
/**
  @Summary
    Toggles the GPIO pin, RG13, using LATG13.

  @Description
    Toggles the GPIO pin, RG13, using LATG13.

  @Preconditions
    The RG13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG13
    IO_RG13_Toggle();
    </code>

*/
#define IO_RG13_Toggle()           _LATG13 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG13.

  @Description
    Reads the value of the GPIO pin, RG13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG13
    postValue = IO_RG13_GetValue();
    </code>

*/
#define IO_RG13_GetValue()         _RG13
/**
  @Summary
    Configures the GPIO pin, RG13, as an input.

  @Description
    Configures the GPIO pin, RG13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG13 as an input
    IO_RG13_SetDigitalInput();
    </code>

*/
#define IO_RG13_SetDigitalInput()  _TRISG13 = 1
/**
  @Summary
    Configures the GPIO pin, RG13, as an output.

  @Description
    Configures the GPIO pin, RG13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG13 as an output
    IO_RG13_SetDigitalOutput();
    </code>

*/
#define IO_RG13_SetDigitalOutput() _TRISG13 = 0
/**
  @Summary
    Sets the GPIO pin, RG14, high using LATG14.

  @Description
    Sets the GPIO pin, RG14, high using LATG14.

  @Preconditions
    The RG14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG14 high (1)
    IO_RG14_SetHigh();
    </code>

*/
#define IO_RG14_SetHigh()          _LATG14 = 1
/**
  @Summary
    Sets the GPIO pin, RG14, low using LATG14.

  @Description
    Sets the GPIO pin, RG14, low using LATG14.

  @Preconditions
    The RG14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG14 low (0)
    IO_RG14_SetLow();
    </code>

*/
#define IO_RG14_SetLow()           _LATG14 = 0
/**
  @Summary
    Toggles the GPIO pin, RG14, using LATG14.

  @Description
    Toggles the GPIO pin, RG14, using LATG14.

  @Preconditions
    The RG14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG14
    IO_RG14_Toggle();
    </code>

*/
#define IO_RG14_Toggle()           _LATG14 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG14.

  @Description
    Reads the value of the GPIO pin, RG14.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG14
    postValue = IO_RG14_GetValue();
    </code>

*/
#define IO_RG14_GetValue()         _RG14
/**
  @Summary
    Configures the GPIO pin, RG14, as an input.

  @Description
    Configures the GPIO pin, RG14, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG14 as an input
    IO_RG14_SetDigitalInput();
    </code>

*/
#define IO_RG14_SetDigitalInput()  _TRISG14 = 1
/**
  @Summary
    Configures the GPIO pin, RG14, as an output.

  @Description
    Configures the GPIO pin, RG14, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG14 as an output
    IO_RG14_SetDigitalOutput();
    </code>

*/
#define IO_RG14_SetDigitalOutput() _TRISG14 = 0
/**
  @Summary
    Sets the GPIO pin, RG15, high using LATG15.

  @Description
    Sets the GPIO pin, RG15, high using LATG15.

  @Preconditions
    The RG15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG15 high (1)
    IO_LCD_RES_SetHigh();
    </code>

*/
#define IO_LCD_RES_SetHigh()          _LATG15 = 1
/**
  @Summary
    Sets the GPIO pin, RG15, low using LATG15.

  @Description
    Sets the GPIO pin, RG15, low using LATG15.

  @Preconditions
    The RG15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG15 low (0)
    IO_LCD_RES_SetLow();
    </code>

*/
#define IO_LCD_RES_SetLow()           _LATG15 = 0
/**
  @Summary
    Toggles the GPIO pin, RG15, using LATG15.

  @Description
    Toggles the GPIO pin, RG15, using LATG15.

  @Preconditions
    The RG15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG15
    IO_LCD_RES_Toggle();
    </code>

*/
#define IO_LCD_RES_Toggle()           _LATG15 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG15.

  @Description
    Reads the value of the GPIO pin, RG15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG15
    postValue = IO_LCD_RES_GetValue();
    </code>

*/
#define IO_LCD_RES_GetValue()         _RG15
/**
  @Summary
    Configures the GPIO pin, RG15, as an input.

  @Description
    Configures the GPIO pin, RG15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG15 as an input
    IO_LCD_RES_SetDigitalInput();
    </code>

*/
#define IO_LCD_RES_SetDigitalInput()  _TRISG15 = 1
/**
  @Summary
    Configures the GPIO pin, RG15, as an output.

  @Description
    Configures the GPIO pin, RG15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG15 as an output
    IO_LCD_RES_SetDigitalOutput();
    </code>

*/
#define IO_LCD_RES_SetDigitalOutput() _TRISG15 = 0
/**
  @Summary
    Sets the GPIO pin, RG2, high using LATG2.

  @Description
    Sets the GPIO pin, RG2, high using LATG2.

  @Preconditions
    The RG2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG2 high (1)
    IO_RG2_SetHigh();
    </code>

*/
#define IO_RG2_SetHigh()          _LATG2 = 1
/**
  @Summary
    Sets the GPIO pin, RG2, low using LATG2.

  @Description
    Sets the GPIO pin, RG2, low using LATG2.

  @Preconditions
    The RG2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG2 low (0)
    IO_RG2_SetLow();
    </code>

*/
#define IO_RG2_SetLow()           _LATG2 = 0
/**
  @Summary
    Toggles the GPIO pin, RG2, using LATG2.

  @Description
    Toggles the GPIO pin, RG2, using LATG2.

  @Preconditions
    The RG2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG2
    IO_RG2_Toggle();
    </code>

*/
#define IO_RG2_Toggle()           _LATG2 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG2.

  @Description
    Reads the value of the GPIO pin, RG2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG2
    postValue = IO_RG2_GetValue();
    </code>

*/
#define IO_RG2_GetValue()         _RG2
/**
  @Summary
    Configures the GPIO pin, RG2, as an input.

  @Description
    Configures the GPIO pin, RG2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG2 as an input
    IO_RG2_SetDigitalInput();
    </code>

*/
#define IO_RG2_SetDigitalInput()  _TRISG2 = 1
/**
  @Summary
    Configures the GPIO pin, RG2, as an output.

  @Description
    Configures the GPIO pin, RG2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG2 as an output
    IO_RG2_SetDigitalOutput();
    </code>

*/
#define IO_RG2_SetDigitalOutput() _TRISG2 = 0
/**
  @Summary
    Sets the GPIO pin, RG3, high using LATG3.

  @Description
    Sets the GPIO pin, RG3, high using LATG3.

  @Preconditions
    The RG3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG3 high (1)
    IO_RG3_SetHigh();
    </code>

*/
#define IO_RG3_SetHigh()          _LATG3 = 1
/**
  @Summary
    Sets the GPIO pin, RG3, low using LATG3.

  @Description
    Sets the GPIO pin, RG3, low using LATG3.

  @Preconditions
    The RG3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG3 low (0)
    IO_RG3_SetLow();
    </code>

*/
#define IO_RG3_SetLow()           _LATG3 = 0
/**
  @Summary
    Toggles the GPIO pin, RG3, using LATG3.

  @Description
    Toggles the GPIO pin, RG3, using LATG3.

  @Preconditions
    The RG3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG3
    IO_RG3_Toggle();
    </code>

*/
#define IO_RG3_Toggle()           _LATG3 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG3.

  @Description
    Reads the value of the GPIO pin, RG3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG3
    postValue = IO_RG3_GetValue();
    </code>

*/
#define IO_RG3_GetValue()         _RG3
/**
  @Summary
    Configures the GPIO pin, RG3, as an input.

  @Description
    Configures the GPIO pin, RG3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG3 as an input
    IO_RG3_SetDigitalInput();
    </code>

*/
#define IO_RG3_SetDigitalInput()  _TRISG3 = 1
/**
  @Summary
    Configures the GPIO pin, RG3, as an output.

  @Description
    Configures the GPIO pin, RG3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG3 as an output
    IO_RG3_SetDigitalOutput();
    </code>

*/
#define IO_RG3_SetDigitalOutput() _TRISG3 = 0
/**
  @Summary
    Sets the GPIO pin, RG6, high using LATG6.

  @Description
    Sets the GPIO pin, RG6, high using LATG6.

  @Preconditions
    The RG6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG6 high (1)
    IO_ENC_PB_SetHigh();
    </code>

*/
#define IO_ENC_PB_SetHigh()          _LATG6 = 1
/**
  @Summary
    Sets the GPIO pin, RG6, low using LATG6.

  @Description
    Sets the GPIO pin, RG6, low using LATG6.

  @Preconditions
    The RG6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG6 low (0)
    IO_ENC_PB_SetLow();
    </code>

*/
#define IO_ENC_PB_SetLow()           _LATG6 = 0
/**
  @Summary
    Toggles the GPIO pin, RG6, using LATG6.

  @Description
    Toggles the GPIO pin, RG6, using LATG6.

  @Preconditions
    The RG6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG6
    IO_ENC_PB_Toggle();
    </code>

*/
#define IO_ENC_PB_Toggle()           _LATG6 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG6.

  @Description
    Reads the value of the GPIO pin, RG6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG6
    postValue = IO_ENC_PB_GetValue();
    </code>

*/
#define IO_ENC_PB_GetValue()         _RG6
/**
  @Summary
    Configures the GPIO pin, RG6, as an input.

  @Description
    Configures the GPIO pin, RG6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG6 as an input
    IO_ENC_PB_SetDigitalInput();
    </code>

*/
#define IO_ENC_PB_SetDigitalInput()  _TRISG6 = 1
/**
  @Summary
    Configures the GPIO pin, RG6, as an output.

  @Description
    Configures the GPIO pin, RG6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG6 as an output
    IO_ENC_PB_SetDigitalOutput();
    </code>

*/
#define IO_ENC_PB_SetDigitalOutput() _TRISG6 = 0
/**
  @Summary
    Sets the GPIO pin, RG7, high using LATG7.

  @Description
    Sets the GPIO pin, RG7, high using LATG7.

  @Preconditions
    The RG7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG7 high (1)
    IO_BTN_ARROW_L_SetHigh();
    </code>

*/
#define IO_BTN_ARROW_L_SetHigh()          _LATG7 = 1
/**
  @Summary
    Sets the GPIO pin, RG7, low using LATG7.

  @Description
    Sets the GPIO pin, RG7, low using LATG7.

  @Preconditions
    The RG7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG7 low (0)
    IO_BTN_ARROW_L_SetLow();
    </code>

*/
#define IO_BTN_ARROW_L_SetLow()           _LATG7 = 0
/**
  @Summary
    Toggles the GPIO pin, RG7, using LATG7.

  @Description
    Toggles the GPIO pin, RG7, using LATG7.

  @Preconditions
    The RG7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG7
    IO_BTN_ARROW_L_Toggle();
    </code>

*/
#define IO_BTN_ARROW_L_Toggle()           _LATG7 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG7.

  @Description
    Reads the value of the GPIO pin, RG7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG7
    postValue = IO_BTN_ARROW_L_GetValue();
    </code>

*/
#define IO_BTN_ARROW_L_GetValue()         _RG7
/**
  @Summary
    Configures the GPIO pin, RG7, as an input.

  @Description
    Configures the GPIO pin, RG7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG7 as an input
    IO_BTN_ARROW_L_SetDigitalInput();
    </code>

*/
#define IO_BTN_ARROW_L_SetDigitalInput()  _TRISG7 = 1
/**
  @Summary
    Configures the GPIO pin, RG7, as an output.

  @Description
    Configures the GPIO pin, RG7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG7 as an output
    IO_BTN_ARROW_L_SetDigitalOutput();
    </code>

*/
#define IO_BTN_ARROW_L_SetDigitalOutput() _TRISG7 = 0
/**
  @Summary
    Sets the GPIO pin, RG8, high using LATG8.

  @Description
    Sets the GPIO pin, RG8, high using LATG8.

  @Preconditions
    The RG8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG8 high (1)
    IO_BTN_ARROW_R_SetHigh();
    </code>

*/
#define IO_BTN_ARROW_R_SetHigh()          _LATG8 = 1
/**
  @Summary
    Sets the GPIO pin, RG8, low using LATG8.

  @Description
    Sets the GPIO pin, RG8, low using LATG8.

  @Preconditions
    The RG8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG8 low (0)
    IO_BTN_ARROW_R_SetLow();
    </code>

*/
#define IO_BTN_ARROW_R_SetLow()           _LATG8 = 0
/**
  @Summary
    Toggles the GPIO pin, RG8, using LATG8.

  @Description
    Toggles the GPIO pin, RG8, using LATG8.

  @Preconditions
    The RG8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG8
    IO_BTN_ARROW_R_Toggle();
    </code>

*/
#define IO_BTN_ARROW_R_Toggle()           _LATG8 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG8.

  @Description
    Reads the value of the GPIO pin, RG8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG8
    postValue = IO_BTN_ARROW_R_GetValue();
    </code>

*/
#define IO_BTN_ARROW_R_GetValue()         _RG8
/**
  @Summary
    Configures the GPIO pin, RG8, as an input.

  @Description
    Configures the GPIO pin, RG8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG8 as an input
    IO_BTN_ARROW_R_SetDigitalInput();
    </code>

*/
#define IO_BTN_ARROW_R_SetDigitalInput()  _TRISG8 = 1
/**
  @Summary
    Configures the GPIO pin, RG8, as an output.

  @Description
    Configures the GPIO pin, RG8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG8 as an output
    IO_BTN_ARROW_R_SetDigitalOutput();
    </code>

*/
#define IO_BTN_ARROW_R_SetDigitalOutput() _TRISG8 = 0
/**
  @Summary
    Sets the GPIO pin, RG9, high using LATG9.

  @Description
    Sets the GPIO pin, RG9, high using LATG9.

  @Preconditions
    The RG9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG9 high (1)
    IO_BTN_CH1_EN_SetHigh();
    </code>

*/
#define IO_BTN_CH1_EN_SetHigh()          _LATG9 = 1
/**
  @Summary
    Sets the GPIO pin, RG9, low using LATG9.

  @Description
    Sets the GPIO pin, RG9, low using LATG9.

  @Preconditions
    The RG9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG9 low (0)
    IO_BTN_CH1_EN_SetLow();
    </code>

*/
#define IO_BTN_CH1_EN_SetLow()           _LATG9 = 0
/**
  @Summary
    Toggles the GPIO pin, RG9, using LATG9.

  @Description
    Toggles the GPIO pin, RG9, using LATG9.

  @Preconditions
    The RG9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG9
    IO_BTN_CH1_EN_Toggle();
    </code>

*/
#define IO_BTN_CH1_EN_Toggle()           _LATG9 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RG9.

  @Description
    Reads the value of the GPIO pin, RG9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG9
    postValue = IO_BTN_CH1_EN_GetValue();
    </code>

*/
#define IO_BTN_CH1_EN_GetValue()         _RG9
/**
  @Summary
    Configures the GPIO pin, RG9, as an input.

  @Description
    Configures the GPIO pin, RG9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG9 as an input
    IO_BTN_CH1_EN_SetDigitalInput();
    </code>

*/
#define IO_BTN_CH1_EN_SetDigitalInput()  _TRISG9 = 1
/**
  @Summary
    Configures the GPIO pin, RG9, as an output.

  @Description
    Configures the GPIO pin, RG9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG9 as an output
    IO_BTN_CH1_EN_SetDigitalOutput();
    </code>

*/
#define IO_BTN_CH1_EN_SetDigitalOutput() _TRISG9 = 0

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the PIC24FJ1024GB610
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize (void);

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        CN_SetInterruptHandler(&CN_CallBack);
    </code>
*/
void CN_SetInterruptHandler(void (* InterruptHandler)(void));

#endif

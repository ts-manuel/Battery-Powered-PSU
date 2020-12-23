/* 
 * File:    inputs.c
 * Author:  Manuel
 * Date:    11/10/2018
 * 
 * Comments:
 */

#include "inputs.h"
#include "hardware/timer.h"
#include <stdio.h>


volatile uint8_t previusButtonValues = 0;
volatile int8_t  encoder = 0;
//volatile int8_t  encoderRate = 0;
volatile int64_t lastEncoderMs = 0;

//Returns a bitmap that corresponds to the buttons been pressed
uint8_t INPUTS_GetButtons(void){
    bool areInterruptsEnabled = INTCON2bits.GIE;
    INTCON2bits.GIE = 0;                        //Disable interrupt
    
    uint8_t value = previusButtonValues;
    previusButtonValues = 0;
    
    INTCON2bits.GIE = areInterruptsEnabled;    //Restore interrupts
    
    return value;
}

//Returns the relative move of the encoder from the previous function call
int8_t INPUTS_GetEncoder(void){
    bool areInterruptsEnabled = INTCON2bits.GIE;
    INTCON2bits.GIE = 0;                        //Disable interrupt
    
    int8_t value = encoder;
    encoder = 0;
    
    INTCON2bits.GIE = areInterruptsEnabled;    //Restore interrupts
    
    return value;
}

/*int8_t INPUTS_GetEncoderRate(void){
    bool areInterruptsEnabled = INTCON2bits.GIE;
    INTCON2bits.GIE = 0;                        //Disable interrupt
    
    int8_t value = encoderRate;
    encoderRate = 0;
    
    INTCON2bits.GIE = areInterruptsEnabled;    //Restore interrupts
    
    return value;
}*/

//Interrupt handler (triggered when an input chenges state)
void __attribute__ ( ( interrupt, no_auto_psv ) ) _IOCInterrupt ( ){
  
    //Check buttons
    previusButtonValues |= IOCFGbits.IOCFG6  ? _BUTTON_ENC_PB   : 0;
    previusButtonValues |= IOCFDbits.IOCFD11 ? _BUTTON_UP_V     : 0;
    previusButtonValues |= IOCFEbits.IOCFE9  ? _BUTTON_DW_I     : 0;
    previusButtonValues |= IOCFBbits.IOCFB5  ? _BUTTON_MENU     : 0;
    previusButtonValues |= IOCFGbits.IOCFG7  ? _BUTTON_LEFT     : 0;
    previusButtonValues |= IOCFGbits.IOCFG8  ? _BUTTON_RIGHT    : 0;
    previusButtonValues |= IOCFGbits.IOCFG9  ? _BUTTON_ENCH1    : 0;
    previusButtonValues |= IOCFAbits.IOCFA0  ? _BUTTON_ENCH2    : 0;
    
    //Check encoder
    //int8_t prevEncoder = encoder;
    if(IOCFCbits.IOCFC3){    //Encoder A
        encoder += IO_ENC_B_GetValue() ? 1 : 0;
    }
    if(IOCFCbits.IOCFC4){    //Encoder B
        encoder += IO_ENC_A_GetValue() ? -1 : 0;
    }
    
    //Calculate encoder velocity
    /*if(encoder != prevEncoder){
        int64_t time = TIME_GetMillis();
    
        encoderRate = (encoder - prevEncoder) / (time - lastEncoderMs);
        
        //printf("encoder rate: %d\n", encoderRate);
        
        float encRate = (float)(encoder - prevEncoder) / (float)(time - lastEncoderMs);
        //printf("encoder rate float: %f\n", encRate);
        
        lastEncoderMs = time;
    }*/
    
    IOCFA = 0;
    IOCFB = 0;
    IOCFC = 0;
    IOCFD = 0;
    IOCFE = 0;
    IOCFG = 0;
    
    IFS1bits.IOCIF = 0;
}
/*
 * lcd_NHD_C128128.c
 *
 *  Created on: 28 gen 2018
 *      Author: Manuel
 */

#include <stdbool.h>
#include "mcc.h"
#include "epmp.h"
#include "hardware/timer.h"
#include "graphics/GLCD.h"

#define _USE_DMA    false           //if true DMA is used to transfer the screen buffer to the LCD
#define _USE_EPMP   true            //if true the Enanched Parralel Master Port is used
#define _FLIP_VERTICALLY    true    //If true flips the screen on the X axis 


//Writes a byte of data to the DDRAM data register
void write_data(unsigned char data){
#if _USE_EPMP == false 
    IO_LCD_A0_SetHigh();
    IO_LCD_RW_SetLow();
    IO_LCD_CS_SetLow();
    IO_LCD_E_SetHigh();
    
    TRISE &= 0xFF00;
    LATE = (LATE & 0xFF00) | data;
    __delay_us(100);
    
    IO_LCD_E_SetLow();
    IO_LCD_CS_SetHigh();
    __delay_us(100);
#else
    IO_LCD_RES_SetHigh();
    EPMP_WriteByte(data, 1);
#endif
}
//Writes a byte to the Instruction register
void write_command(unsigned char data){
#if _USE_EPMP == false 
    IO_LCD_A0_SetLow();
    IO_LCD_RW_SetLow();
    IO_LCD_CS_SetLow();
    IO_LCD_E_SetHigh();
    
    TRISE &= 0xFF00;
    LATE = (LATE & 0xFF00) | data;
    __delay_us(100);
    
    IO_LCD_E_SetLow();
    IO_LCD_CS_SetHigh();
    __delay_us(100);
#else
    IO_LCD_RES_SetHigh();
    EPMP_WriteByte(data, 0);
#endif
}
//Reset the LCD controller
void LCD_Reset(){  
    IO_LCD_RES_SetLow();
    TIME_Delay_ms(1);
    IO_LCD_RES_SetHigh();
    TIME_Delay_ms(1);
}

//Initializes the display
void LCD_NHD_C12865_Initialize(){
	//Reset display controller
	LCD_Reset();

    //Initialize display
	write_command(0xAE);        //Display OFF
    write_command(0xA0);        //RAM Address SEG Correspondence = normal
    write_command(0x41);
#if _FLIP_VERTICALLY == false
    write_command(0xC0);        //COM Scan direction = normal
#else
    write_command(0xC8);        //COM Scan direction = reverse
#endif
	write_command(0xA2);        //Sets the LCD drive voltage bias ratio 1/9 bias
    write_command(0x2F);        //Select internal power supply operating mode (Booster circuit ON, Voltage regulator ON, Voltage follower ON)
	write_command(0x24);        //Select internal resistor ratio(Rb/Ra) mode
    write_command(0x81);        //Enter Electronic Volume Mode Set
    write_command(50);          //Set the V0 output voltage electronic volume register (0 - 63)
    write_command(0xF8);        //Enter Booster Ratio Select Mode Set
    write_command(0x00);        //Set Booster ration 4x
    
    write_command(0xAF);        //Display ON
}

//LCD Display ON / OFF
void LCD_NHD_C12865_PowerOnOff(bool turnOn){
    write_command(turnOn ? 0xAF : 0xAE);
}

//Sets the drive voltage for the LCD, valid values are from 0 to 63
void LCD_NHD_C12865_SetContrast(uint8_t contrast){
    if(contrast > 63)
        contrast = 63;
    
    write_command(0x81);        //Enter Electronic Volume Mode Set
    write_command(contrast);    //Set the V0 output voltage electronic volume register (0 - 63)
}

//Writes a char array to the LCD data DDRAM
void LCD_NHD_C12865_Update(unsigned char *scrBuffer){
#if _USE_DMA == true
	
#else
	unsigned char page;
	unsigned char col;
    
	unsigned int bufferIndex = 0;
	for (page = 0xB0; page < 0xB9; page++){		//write to page 0 then go to next page . 128pixels / 8per page = 16 pages
		write_command(page);					//Set page address
		write_command(0x10);					//Set column address MSB
		write_command(0x00);					//Set column address LSB
		for(col = 0; col < 128; col++){			//each page has 128 pixel columns
			write_data(scrBuffer[bufferIndex++]);   //Write data into LCD Ram
		}
	}
#endif
}

void LCD_NHD_C12865_Test(){
	unsigned char page;
	unsigned char col;
	for (page = 0xB0; page < 0xC0; page++){		//write to page 0 then go to mext page . 128pixels / 8per page = 16 pages
		write_command(page);					//Set page address
		write_command(0x10);					//Set column address MSB
		write_command(0x00);					//Set column address LSB
		for(col = 0; col < 128; col++){			//each page has 128 pixel columns
			if(page == 0xB0){
				write_data(0xFF);			//16 level grayscale; write each byte 4 times
				write_data(0xFF);
				write_data(0xFF);
				write_data(0xFF);
			}
			else if(page == 0xB1){
				write_data(0xFF);			//16 level grayscale; write each byte 4 times
				write_data(0x00);
				write_data(0x00);
				write_data(0x00);
			}
			else{
				write_data((col & 0x10) ? 0xFF : 0x00);			//16 level grayscale; write each byte 4 times
				write_data((col & 0x10) ? 0xFF : 0x00);
				write_data((col & 0x10) ? 0xFF : 0x00);
				write_data((col & 0x10) ? 0xFF : 0x00);
			}
		}
	}
}

//Sets the intensity of the LCD Back-light (0 to 255)
void LCD_NHD_C12865_SetBackLight(uint8_t b){
    MCCP1_COMPARE_SingleCompare16ValueSet(0xFF - b);
}

/*
 * lcd_NHD_C12865.h
 *
 *  Created on: 28 gen 2018
 *      Author: Manuel
 * 
 * Low level functions to communicate with the NHD_C12865AR-FSW-GBW display
 */


#ifndef SRC_HARDWERE_LCD_NHD_C12865_H_
#define SRC_HARDWERE_LCD_NHD_C12865_H_

	void LCD_NHD_C12865_Initialize();
    void LCD_NHD_C12865_PowerOnOff(bool turnOn);
    void LCD_NHD_C12865_SetContrast(uint8_t contrast);
	void LCD_NHD_C12865_SetBackLight(uint8_t b);
	void LCD_NHD_C12865_Update(unsigned char *scrBuffer);
	void LCD_NHD_C12865_Test();

#endif /* SRC_HARDWERE_LCD_NHD_C12865_H_ */

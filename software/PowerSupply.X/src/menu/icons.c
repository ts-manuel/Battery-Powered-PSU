/* 
 * File:    icons.c
 * Author:  Manuel
 * Date:    27/10/2018
 * 
 * Comments:
 */

#include "icons.h"

static const uint8_t mainPageData[] = {
    0x01, 0x45, 0x7D, 0x05, 0x01, 0x71, 0x11, 0x11, 0x7D, 0x01, 0x05, 0x09, 0x11, 0x21, 0x41, 0x01, 
    0x45, 0x7D, 0x05, 0x01, 0x7D, 0x45, 0x45, 0x7D, 0x01, 0x05, 0x09, 0x11, 0x21, 0x41, 0x01, 0x45, 
    0x7D, 0x05, 0x01, 0x7D, 0x55, 0x55, 0x7D, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x45, 0x7D, 0x05, 
    0x01, 0x7D, 0x55, 0x55, 0x5D, 0x01, 0x01, 0x29, 0x01, 0x01, 0x71, 0x11, 0x11, 0x7D, 0x01, 0x75, 
    0x55, 0x55, 0x5D, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x39, 0x45, 0x4D, 0x5D, 0x7D, 0x7D, 0x7D, 0x7D, 0x7D, 0x01, 
    0x01, 0x7D, 0x45, 0x45, 0x01, 0x7D, 0x11, 0x11, 0x7D, 0x01, 0x45, 0x7D, 0x05, 0x01, 0xFF, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 
    0xFF, 0x01, 0x7D, 0x45, 0x45, 0x01, 0x7D, 0x11, 0x11, 0x7D, 0x01, 0x5D, 0x55, 0x75, 0x01, 0xFF, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3D, 0x7F, 0x67, 0x67, 0x67, 0x67, 0x7F, 0x3D, 0x00, 0x3D, 0x7F, 0x67, 0x67, 0x67, 
    0x67, 0x7F, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x3D, 0x7F, 0x67, 0x67, 0x67, 0x67, 0x7F, 0x3D, 0x00, 
    0x3D, 0x7F, 0x67, 0x67, 0x67, 0x67, 0x7F, 0x3D, 0x00, 0x3D, 0x7F, 0x67, 0x67, 0x67, 0x67, 0x7F, 
    0x3D, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0xFF, 
    0xFF, 0x00, 0x00, 0x3D, 0x7F, 0x67, 0x67, 0x67, 0x67, 0x7F, 0x3D, 0x00, 0x3D, 0x7F, 0x67, 0x67, 
    0x67, 0x67, 0x7F, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x3D, 0x7F, 0x67, 0x67, 0x67, 0x67, 0x7F, 0x3D, 
    0x00, 0x3D, 0x7F, 0x67, 0x67, 0x67, 0x67, 0x7F, 0x3D, 0x00, 0x3D, 0x7F, 0x67, 0x67, 0x67, 0x67, 
    0x7F, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xE0, 0xF0, 0x30, 0x30, 0x30, 0x30, 0xF0, 0xE0, 0x00, 0xE3, 0xF7, 0x36, 0x36, 0x36, 
    0x36, 0xF7, 0xE3, 0x00, 0x30, 0x30, 0x00, 0xE3, 0xF7, 0x36, 0x36, 0x36, 0x36, 0xF7, 0xE3, 0x00, 
    0xE3, 0xF7, 0x36, 0x36, 0x36, 0x36, 0xF7, 0xE3, 0x00, 0xE3, 0xF7, 0x36, 0x36, 0x36, 0x36, 0xF7, 
    0xE3, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x70, 0x30, 0x70, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0xFF, 
    0xFF, 0x00, 0x00, 0xE0, 0xF0, 0x30, 0x30, 0x30, 0x30, 0xF0, 0xE0, 0x00, 0xE3, 0xF7, 0x36, 0x36, 
    0x36, 0x36, 0xF7, 0xE3, 0x00, 0x30, 0x30, 0x00, 0xE3, 0xF7, 0x36, 0x36, 0x36, 0x36, 0xF7, 0xE3, 
    0x00, 0xE3, 0xF7, 0x36, 0x36, 0x36, 0x36, 0xF7, 0xE3, 0x00, 0xE3, 0xF7, 0x36, 0x36, 0x36, 0x36, 
    0xF7, 0xE3, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x70, 0x30, 0x70, 0xE0, 0xC0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0F, 0x09, 0x09, 0x00, 0x0F, 0x09, 0x09, 0x00, 0x00, 0xDE, 0xFF, 0x73, 0x73, 0x73, 
    0x73, 0xFF, 0xDE, 0x00, 0x03, 0x03, 0x00, 0xDE, 0xFF, 0x73, 0x73, 0x73, 0x73, 0xFE, 0xDC, 0x00, 
    0xDE, 0xFF, 0x73, 0x73, 0x73, 0x73, 0xFF, 0xDE, 0x00, 0xDE, 0xFF, 0x73, 0x73, 0x73, 0x73, 0xFF, 
    0xDE, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0xFF, 
    0xFF, 0x00, 0x00, 0x0F, 0x09, 0x09, 0x00, 0x0E, 0x01, 0x0E, 0x00, 0x00, 0xDE, 0xFF, 0x73, 0x73, 
    0x73, 0x73, 0xFF, 0xDE, 0x00, 0x03, 0x03, 0x00, 0xDE, 0xFF, 0x73, 0x73, 0x73, 0x73, 0xFE, 0xDC, 
    0x00, 0xDE, 0xFF, 0x73, 0x73, 0x73, 0x73, 0xFF, 0xDE, 0x00, 0xDE, 0xFF, 0x73, 0x73, 0x73, 0x73, 
    0xFF, 0xDE, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xCC, 0xCC, 0xCC, 0xFF, 0x7F, 0x00, 0x00, 0x00, 
    0x40, 0x40, 0x4E, 0x51, 0x51, 0x51, 0x51, 0x4E, 0x40, 0x4E, 0x51, 0x51, 0x51, 0x51, 0x4E, 0x40, 
    0x40, 0x40, 0x40, 0x4E, 0x51, 0x51, 0x51, 0x51, 0x4E, 0x40, 0x4E, 0x51, 0x51, 0x51, 0x51, 0x4E, 
    0x40, 0x4E, 0x51, 0x51, 0x51, 0x51, 0x4E, 0x40, 0x40, 0x40, 0x40, 0x41, 0x41, 0x41, 0x40, 0x41, 
    0x41, 0x41, 0x40, 0x41, 0x41, 0x41, 0x40, 0x40, 0x41, 0x40, 0x40, 0x41, 0x40, 0x40, 0x40, 0xFF, 
    0xFF, 0x40, 0x40, 0x4E, 0x51, 0x51, 0x51, 0x51, 0x4E, 0x40, 0x4E, 0x51, 0x51, 0x51, 0x51, 0x4E, 
    0x40, 0x40, 0x40, 0x40, 0x4E, 0x51, 0x51, 0x51, 0x51, 0x4E, 0x40, 0x4E, 0x51, 0x51, 0x51, 0x51, 
    0x4E, 0x40, 0x4E, 0x51, 0x51, 0x51, 0x51, 0x4E, 0x40, 0x40, 0x40, 0x40, 0x41, 0x41, 0x41, 0x40, 
    0x41, 0x41, 0x41, 0x40, 0x41, 0x41, 0x41, 0x40, 0x40, 0x41, 0x40, 0x40, 0x41, 0x40, 0x40, 0x40, 
    0x00, 0x00, 0xE3, 0x14, 0x14, 0x14, 0x14, 0xE3, 0x00, 0xE3, 0x14, 0x14, 0x14, 0x14, 0xE3, 0x00, 
    0x30, 0x30, 0x00, 0xE3, 0x14, 0x14, 0x14, 0x14, 0xE3, 0x00, 0xE3, 0x14, 0x14, 0x14, 0x14, 0xE3, 
    0x00, 0xE3, 0x14, 0x14, 0x14, 0x14, 0xE3, 0x00, 0x00, 0x00, 0x00, 0xD0, 0x50, 0x70, 0x00, 0xF0, 
    0x50, 0x50, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0xE0, 0x10, 0x10, 0xE0, 0x00, 0x00, 0x00, 0xFF, 
    0xFF, 0x00, 0x00, 0xE3, 0x14, 0x14, 0x14, 0x14, 0xE3, 0x00, 0xE3, 0x14, 0x14, 0x14, 0x14, 0xE3, 
    0x00, 0x30, 0x30, 0x00, 0xE3, 0x14, 0x14, 0x14, 0x14, 0xE3, 0x00, 0xE3, 0x14, 0x14, 0x14, 0x14, 
    0xE3, 0x00, 0xE3, 0x14, 0x14, 0x14, 0x14, 0xE3, 0x00, 0x00, 0x00, 0x00, 0xD0, 0x50, 0x70, 0x00, 
    0xF0, 0x50, 0x50, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0xE0, 0x10, 0x10, 0xE0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xB8, 0x44, 0x44, 0x44, 0x44, 0xB8, 0x00, 0xB8, 0x44, 0x44, 0x44, 0x44, 0xB8, 0x00, 
    0x0C, 0x0C, 0x00, 0xB8, 0x44, 0x44, 0x44, 0x44, 0xB8, 0x00, 0xB8, 0x44, 0x44, 0x44, 0x44, 0xB8, 
    0x00, 0xB8, 0x44, 0x44, 0x44, 0x44, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x74, 0x54, 0x5C, 0x00, 0x7C, 
    0x54, 0x54, 0x00, 0x40, 0x7C, 0x40, 0x00, 0x00, 0x3C, 0x50, 0x50, 0x3C, 0x00, 0x00, 0x00, 0xFF, 
    0xFF, 0x00, 0x00, 0xB8, 0x44, 0x44, 0x44, 0x44, 0xB8, 0x00, 0xB8, 0x44, 0x44, 0x44, 0x44, 0xB8, 
    0x00, 0x0C, 0x0C, 0x00, 0xB8, 0x44, 0x44, 0x44, 0x44, 0xB8, 0x00, 0xB8, 0x44, 0x44, 0x44, 0x44, 
    0xB8, 0x00, 0xB8, 0x44, 0x44, 0x44, 0x44, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x74, 0x54, 0x5C, 0x00, 
    0x7C, 0x54, 0x54, 0x00, 0x40, 0x7C, 0x40, 0x00, 0x00, 0x3C, 0x50, 0x50, 0x3C, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
const GLCD_Bitmap_t mainPageBMP = {128, 65, mainPageData};

static const uint8_t returnBMP[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x1C, 0x3E, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0x80, 0x80, 0x80, 0x80, 
		0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 
	};
const GLCD_Bitmap_t returnICO = {32, 32, returnBMP};

static const uint8_t settingsBMP[] = {
		0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x08, 0x0C, 0x0E, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x0E, 0x0C, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0xE0, 0xF0, 0x78, 0x38, 0x38, 0x38, 0xF8, 0xFC, 0xFE, 0x1F, 0x0F, 0x07, 
		0x03, 0x03, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0D, 0x1B, 0x35, 0x6A, 0xD5, 0xAA, 0xD5, 0xAB, 0xD6, 0xFC, 
		0xE0, 0xF0, 0xF8, 0x7C, 0x3E, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF0, 0xF0, 0xB0, 0x60, 0xC0, 0x80, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF0, 0x70, 0x00, 0x00, 0x00, 0x00, 
	};
const GLCD_Bitmap_t settingsICO = {32, 32, settingsBMP};

static const uint8_t batteryBMP[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0E, 0x0E, 
		0x0E, 0x0E, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3E, 
		0x3C, 0x38, 0x39, 0x3F, 0x3F, 0x3F, 0x3F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8E, 0x0C, 0x08, 
		0x41, 0xC3, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0x70, 0x70, 0xF0, 
		0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	};
const GLCD_Bitmap_t batteryICO = {32, 32, batteryBMP};

static const uint8_t calibrationBMP[] = {
	0x00, 0x00, 0x1F, 0x20, 0x27, 0x24, 0x24, 0x25, 0x24, 0x25, 0x24, 0x25, 0x24, 0x24, 0x27, 0x20,
	0x1F, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xFF, 0x00, 0xFE, 0x82, 0x22, 0x12, 0x0A, 0x06, 0x02, 0x02, 0x02, 0x82, 0xFE, 0x00,
	0xFF, 0x00, 0xFF, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x01, 0x06, 0x06, 0x08, 0x10, 0x20, 0x00,
	0x00, 0x00, 0xFF, 0x00, 0x00, 0x1E, 0x7F, 0x1E, 0x00, 0x00, 0x00, 0x1E, 0x7F, 0x1E, 0x00, 0x00,
	0xFF, 0x00, 0xFF, 0x04, 0x48, 0x10, 0x60, 0x6A, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xFC, 0x02, 0x32, 0x32, 0x02, 0x32, 0x32, 0x02, 0x32, 0x32, 0x02, 0x32, 0x32, 0x02,
	0xFC, 0x00, 0xF8, 0x08, 0x08, 0x08, 0x08, 0xA8, 0x08, 0x08, 0x08, 0xA8, 0x08, 0x08, 0x08, 0x00
};
const GLCD_Bitmap_t calibrationICO = {32, 32, calibrationBMP};

static const uint8_t errorsBMP[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1F, 0x3F,
	0x3F, 0x1F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1F, 0x7F, 0xFF, 0xC3, 0x80, 0x00,
	0x00, 0x80, 0xC3, 0xFF, 0x7F, 0x1F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x00,
	0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x0C, 0x1E, 0x7E, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x86, 0x86,
	0x86, 0x86, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x7E, 0x1E, 0x0C, 0x00
};
const GLCD_Bitmap_t errorsICO = { 32, 32, errorsBMP };

static const uint8_t errorSmallBMP[] = {
	0x00, 0x00, 0x00, 0xF6, 0xF6, 0x00, 0x00, 0x00, 0x00, 
};
const GLCD_Bitmap_t errorSmallICO = { 9, 7, errorSmallBMP };
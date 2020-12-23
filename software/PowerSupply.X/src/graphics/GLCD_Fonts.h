/*
 * GLCD_Fonts.h
 *
 *  Created on: 30 gen 2018
 *      Author: Manuel
 */

#include <stdint.h>

#ifndef SRC_GRAPHICS_GLCD_FONTS_H_
#define SRC_GRAPHICS_GLCD_FONTS_H_

/*#define _FONT_SMALL				SmallFont
#define _FONT_TINY				TinyFont
#define _FONT_MEDIUM_NUMBERS	MediumNumbers
#define _FONT_BIG_NUMBERS		BigNumbers*/


/*typedef struct{
    int x;
    int y;
    const uint8_t* data;
} Char_t;

typedef struct{
    int offset;
    int numChars;
    const Char_t* fontData;
} Font_t;*/

typedef struct{
    const uint8_t x;
    const uint8_t y;
    const uint8_t data[];
} Char_t;

typedef struct{
    const uint8_t offset;
    const uint8_t numChars;
    const uint8_t stride;
    const uint8_t maxX;
    const uint8_t maxY;
    const uint8_t fontData[];
} Font_t;

#define _FONT_4x5   ((Font_t*)&font_4x5)
#define _FONT_6x9   ((Font_t*)&font_6x9)
#define _FONT_8x11  ((Font_t*)&font_8x11)


typedef struct{
    const uint8_t x;
    const uint8_t y;
    const uint8_t data[6];
} Char6_t;

typedef struct{
    const uint8_t x;
    const uint8_t y;
    const uint8_t data[14];
} Char14_t;

typedef struct{
    const uint8_t x;
    const uint8_t y;
    const uint8_t data[18];
} Char18_t;

typedef struct{
    const uint8_t offset;
    const uint8_t numChars;
    const uint8_t stride;
    const uint8_t maxX;
    const uint8_t maxY;
    const Char6_t fontData[];
} Font6_t;

typedef struct{
    const uint8_t offset;
    const uint8_t numChars;
    const uint8_t stride;
    const uint8_t maxX;
    const uint8_t maxY;
    const Char14_t fontData[];
} Font14_t;

typedef struct{
    const uint8_t offset;
    const uint8_t numChars;
    const uint8_t stride;
    const uint8_t maxX;
    const uint8_t maxY;
    const Char18_t fontData[];
} Font18_t;



/*extern const uint8_t SmallFont[];
extern const uint8_t MediumNumbers[];
extern const uint8_t BigNumbers[];
extern const uint8_t TinyFont[];*/

extern const Font6_t    font_4x5;
extern const Font18_t   font_8x11;
extern const Font14_t   font_6x9;

#endif /* SRC_GRAPHICS_GLCD_FONTS_H_ */

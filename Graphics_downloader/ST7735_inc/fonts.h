/* vim: set ai et ts=4 sw=4: */
#include "main.h"

#ifndef __FONTS_H__
#define __FONTS_H__

typedef struct {
    const uint8_t width;
    const uint8_t height;
    const uint16_t *data;
} FontDef;


extern FontDef Font_7x10;
extern FontDef Font_11x18;
extern FontDef Font_16x26;
extern FontDef Font_5x8;



#endif // __FONTS_H__

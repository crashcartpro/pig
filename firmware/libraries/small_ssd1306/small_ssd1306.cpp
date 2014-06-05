#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdlib.h>

#include "small_ssd1306.h"

static uint8_t buffer[SSD1306_LCDHEIGHT * SSD1306_LCDWIDTH / 8] = {//start up screen
0x7F, 0x7F, 0x7F, 0x3F, 0x3F, 0x1F, 0x1E, 0x3E, 0x40, 0x80, 0x01, 0x01, 0x1E, 0xA1, 0x41, 0x27,
0x3F, 0x3F, 0x3F, 0xFF, 0x7F, 0x7F, 0x7F, 0x7E, 0xFC, 0xF1, 0xE6, 0xC8, 0x10, 0x60, 0x80, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x1F, 0xC0, 0xFF, 0xFF, 0xDF, 0x00, 0x00, 0x00, 0xFF, 0x00,
0x00, 0x00, 0x06, 0x08, 0x0F, 0x14, 0x20, 0xC0, 0x00, 0x00, 0x01, 0x01, 0x0B, 0x0E, 0x04, 0x06,
0x06, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x06, 0x04, 0x1C, 0x78, 0x30,
0x10, 0x20, 0x20, 0x20, 0xA0, 0xA0, 0xA0, 0x80, 0x80, 0x20, 0x20, 0x20, 0xD0, 0x30, 0x18, 0x00,
0xC0, 0xE0, 0xF0, 0xF0, 0xF0, 0xE0, 0xC0, 0xC0, 0xC0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0, 0xE0, 0xF0, 0xF0, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00,
0x07, 0x20, 0x90, 0x90, 0x90, 0x90, 0xE2, 0x02, 0x06, 0x18, 0x61, 0x01, 0x01, 0x07, 0x06, 0x00,
0xF8, 0xBC, 0x9E, 0x91, 0x82, 0xC4, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x3E, 0xFE, 0xFD,
0xFC, 0xFA, 0xF2, 0xFA, 0xF9, 0xFC, 0x7E, 0xFF, 0x3F, 0x0F, 0x82, 0x40, 0x30, 0x0C, 0x83, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x18, 0x18, 0x30, 0x70, 0xE0, 0xE0, 0xC0, 0x80, 0x00,
0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xC0, 0xE0, 0x70, 0x30, 0x08, 0x04, 0x00,
0x00, 0x00, 0x01, 0x01, 0x00, 0x60, 0x61, 0xC7, 0xC0, 0xE0, 0x38, 0x07, 0x00, 0x80, 0x80, 0xC0,
0xC0, 0xC1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
0x1F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE1, 0xC0, 0xC0, 0x80, 0x80, 0x00,
0x07, 0x05, 0x09, 0x07, 0x07, 0x07, 0x08, 0x05, 0x18, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
0x01, 0x03, 0x0F, 0x1F, 0x6F, 0x89, 0x67, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03,
0x0F, 0x1F, 0xF3, 0x91, 0x90, 0x01, 0x08, 0x0C, 0x04, 0x02, 0x01, 0x00, 0x00, 0x63, 0x80, 0x00,
0x0C, 0x1E, 0x1E, 0x0E, 0x00, 0x00, 0x00, 0x70, 0x78, 0x78, 0x30, 0x00, 0x01, 0x03, 0x8F, 0xFF,
0x7C, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0x3F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x1F,
0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00,
0xC0, 0xE0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x1F, 0x1F, 0x0F, 0x0F, 0x07,
0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x30, 0xFC, 0x14, 0x02, 0xD2, 0xC2, 0x44, 0xC4, 0x88,
0x08, 0x10, 0x00, 0x20, 0x40, 0x41, 0x02, 0x06, 0x08, 0x08, 0x09, 0x09, 0x18, 0xC2, 0x02, 0x00,
0x04, 0x04, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0C, 0x04, 0x06, 0x03, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x80, 0x40, 0x30, 0x0E, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x18, 0x3C, 0x7F, 0x7F, 0x7F, 0x3F, 0x1F, 0x1F, 0x3F, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x03, 0x1F, 0x3F, 0x1F, 0x1F, 0x3F, 0x7F, 0x7F, 0x7F, 0x3C, 0x18, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char PROGMEM terminus [] = { //13x20 terminus font
  0xFC, 0x07, 0x1C, 0xF0, 0x1F, 0xFE, 0x03, 0xC0, 0xFF, 0x3F, 0xFF, 0xFB,
  0xFF, 0xFC, 0x87, 0xFF, 0x00, 0xFE, 0x0F, 0x1E, 0xF8, 0x3F, 0xFF, 0x07,
  0xE0, 0xFF, 0xBF, 0xFF, 0xFB, 0xFF, 0xFE, 0xCF, 0xFF, 0x01, 0x0F, 0x1E,
  0x1F, 0x3C, 0xF8, 0x07, 0x0F, 0xF0, 0x0F, 0xC0, 0x03, 0x38, 0xE0, 0x0F,
  0xFE, 0xC1, 0x03, 0x07, 0x9C, 0x1F, 0x1C, 0xF0, 0x03, 0x0E, 0xF8, 0x0F,
  0xC0, 0x01, 0x38, 0xE0, 0x07, 0xFC, 0x80, 0x03, 0x07, 0x9C, 0x1F, 0x1C,
  0xF0, 0x03, 0x0E, 0xDC, 0x0F, 0xC0, 0x01, 0x38, 0xE0, 0x07, 0xFC, 0x80,
  0x03, 0x07, 0x1E, 0x1C, 0x1C, 0x70, 0x00, 0x0E, 0xCE, 0x0F, 0xC0, 0x01,
  0x38, 0x70, 0x07, 0xFC, 0x80, 0x03, 0x07, 0x1F, 0x1C, 0x1C, 0x70, 0x00,
  0x0E, 0xC7, 0x0F, 0xC0, 0x01, 0x00, 0x70, 0x07, 0xFC, 0x80, 0x03, 0x87,
  0x1F, 0x1C, 0x00, 0x70, 0x00, 0x8E, 0xC3, 0x0F, 0xC0, 0x01, 0x00, 0x38,
  0x07, 0xFC, 0x80, 0x03, 0xC7, 0x1D, 0x1C, 0x00, 0x38, 0x00, 0xCF, 0xC1,
  0xFF, 0xCF, 0xFF, 0x01, 0x38, 0x0F, 0xFE, 0x80, 0x03, 0xE7, 0x1C, 0x1C,
  0x00, 0x1C, 0xFC, 0xE7, 0xC0, 0xFF, 0xDF, 0xFF, 0x03, 0x1C, 0xFE, 0xEF,
  0x81, 0x03, 0x77, 0x1C, 0x1C, 0x00, 0x0E, 0xFC, 0x77, 0xC0, 0x01, 0xFC,
  0x81, 0x07, 0x1C, 0xFE, 0xCF, 0xFF, 0x03, 0x3F, 0x1C, 0x1C, 0x00, 0x07,
  0x00, 0x7F, 0xC0, 0x01, 0xF8, 0x01, 0x07, 0x0E, 0x0F, 0x9E, 0xFF, 0x03,
  0x1F, 0x1C, 0x1C, 0x80, 0x03, 0x00, 0x7E, 0xC0, 0x01, 0xF8, 0x01, 0x07,
  0x0E, 0x07, 0x1C, 0x80, 0x03, 0x0F, 0x1C, 0x1C, 0xC0, 0x01, 0x00, 0xFE,
  0xFF, 0x01, 0xF8, 0x01, 0x07, 0x07, 0x07, 0x1C, 0x80, 0x03, 0x07, 0x1C,
  0x1C, 0xE0, 0x00, 0x00, 0xFE, 0xFF, 0x01, 0xF8, 0x01, 0x07, 0x07, 0x07,
  0x1C, 0x80, 0x03, 0x07, 0x1C, 0x1C, 0x70, 0x80, 0x03, 0x0E, 0xC0, 0x01,
  0xF8, 0x01, 0x07, 0x07, 0x07, 0x1C, 0x80, 0x03, 0x07, 0x1C, 0x1C, 0x38,
  0x80, 0x03, 0x0E, 0xC0, 0x0F, 0xF8, 0x01, 0x07, 0x07, 0x07, 0x1C, 0x80,
  0x03, 0x0F, 0x1E, 0x1C, 0x1C, 0x80, 0x07, 0x0F, 0xC0, 0x1F, 0xF8, 0x83,
  0x07, 0x07, 0x0F, 0x1E, 0xC0, 0x03, 0xFE, 0x8F, 0xFF, 0xFC, 0x7F, 0xFF,
  0x07, 0xC0, 0xFD, 0x9F, 0xFF, 0x03, 0x07, 0xFE, 0xCF, 0xFF, 0x01, 0xFC,
  0x87, 0xFF, 0xFC, 0x7F, 0xFE, 0x03, 0xC0, 0xF9, 0x0F, 0xFF, 0x01, 0x07,
  0xFC, 0xC7, 0xFF, 0x00
};

static const unsigned char PROGMEM terminus_font [] = { //10x15 terminus font
   0x30, 0x30, 0xc3, 0x0c, 0x0c, 0x00, 0xe0, 0x00, 0x03, 0x18, 0x18, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x30, 0xf0, 0xc3, 0x0f,
   0xc0, 0xff, 0xf3, 0xf7, 0x3f, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x60, 0x00,
   0x18, 0xc0, 0x0f, 0x00, 0xfc, 0xfc, 0xc3, 0xcf, 0x3f, 0xff, 0xff, 0xcf,
   0xcf, 0xc0, 0xfc, 0x80, 0x3f, 0xf0, 0x00, 0x00, 0x0c, 0xcc, 0xcf, 0x3f,
   0x7c, 0xfc, 0xc3, 0xcf, 0xff, 0x03, 0x0f, 0x0c, 0xc0, 0xc0, 0x03, 0xff,
   0x8f, 0x0f, 0x00, 0xf8, 0xc0, 0x00, 0x00, 0x06, 0x00, 0x0c, 0x00, 0x00,
   0xc0, 0x00, 0x80, 0xcf, 0xff, 0x00, 0x30, 0x00, 0x33, 0x00, 0x0f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x03, 0x03, 0x00, 0x1c, 0x0c, 0x1c, 0x00, 0x00, 0x30, 0x30,
   0xc3, 0x0c, 0x0c, 0x8e, 0xb1, 0x01, 0x03, 0x0c, 0x30, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x98, 0x61, 0x38, 0x18, 0x66, 0x18, 0xe0, 0x03,
   0x18, 0x30, 0xb0, 0x61, 0x86, 0x01, 0x00, 0x00, 0x30, 0x00, 0x30, 0x60,
   0x18, 0x3f, 0x86, 0x0d, 0x66, 0xd8, 0x60, 0x03, 0x0c, 0x60, 0xd8, 0xc0,
   0x30, 0x00, 0x36, 0xd8, 0x00, 0x01, 0x0e, 0x6c, 0xd8, 0x60, 0xc6, 0x0c,
   0x66, 0x18, 0x0c, 0x03, 0x0f, 0x3c, 0xf0, 0xc0, 0x03, 0x03, 0x8c, 0x81,
   0x01, 0xc0, 0xe0, 0x01, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x00, 0xc0, 0x00,
   0xc0, 0x60, 0xf0, 0x00, 0x30, 0x00, 0x30, 0x00, 0x0c, 0x00, 0x00, 0x00,
   0xc0, 0x1f, 0x06, 0x03, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x03, 0x03, 0x00, 0x06, 0x0c, 0x30, 0x00, 0x00, 0x30, 0x30, 0xc3, 0x0c,
   0x3f, 0x9b, 0x19, 0x03, 0x03, 0x06, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xd8, 0xc0, 0x3c, 0x0c, 0x3c, 0x30, 0xf0, 0x03, 0x0c, 0x30,
   0xf0, 0xc0, 0x03, 0x03, 0x00, 0x00, 0x18, 0x00, 0x60, 0x30, 0xb0, 0x61,
   0x03, 0x0f, 0x3c, 0xf0, 0xc0, 0x03, 0x0c, 0x30, 0xf0, 0xc0, 0x30, 0x00,
   0x36, 0xcc, 0x00, 0x03, 0x0f, 0x3c, 0xf0, 0xc0, 0x83, 0x0d, 0x3c, 0x30,
   0x0c, 0x03, 0x0f, 0x3c, 0xb0, 0x61, 0x86, 0x01, 0x8c, 0x81, 0x01, 0xc0,
   0x30, 0x03, 0x00, 0x18, 0x00, 0x0c, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x30,
   0xf0, 0x00, 0x30, 0x00, 0x30, 0x00, 0x0c, 0x00, 0x00, 0x00, 0xc0, 0x30,
   0x03, 0x03, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03,
   0x00, 0x03, 0x0c, 0x60, 0x00, 0x00, 0x30, 0x30, 0xc3, 0x8c, 0x6d, 0xdb,
   0x18, 0x03, 0x03, 0x06, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xcc, 0xc0, 0x36, 0x0c, 0x0c, 0x30, 0xd8, 0x03, 0x0c, 0x00, 0xf0, 0xc0,
   0x03, 0xc3, 0x00, 0x03, 0x0c, 0x00, 0xc0, 0x30, 0xf0, 0xc0, 0x03, 0x0f,
   0x3c, 0xf0, 0xc0, 0x03, 0x0c, 0x30, 0xf0, 0xc0, 0x30, 0x00, 0x36, 0xc6,
   0x00, 0x87, 0x0f, 0x3c, 0xf0, 0xc0, 0x83, 0x0d, 0x3c, 0x00, 0x0c, 0x03,
   0x0f, 0x3c, 0xb0, 0x61, 0x86, 0x01, 0x8c, 0x01, 0x03, 0xc0, 0x18, 0x06,
   0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x30, 0xf0, 0x00,
   0x00, 0x80, 0x33, 0x00, 0x0c, 0x00, 0x00, 0x00, 0xc0, 0x60, 0x03, 0x03,
   0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x03,
   0x0c, 0x60, 0x00, 0x00, 0x30, 0x30, 0xf3, 0xbf, 0x0d, 0xce, 0x18, 0x03,
   0x03, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcc, 0xe0,
   0x30, 0x0c, 0x0c, 0x30, 0xcc, 0x03, 0x0c, 0x00, 0xd8, 0xc0, 0x03, 0xc3,
   0x00, 0x03, 0x06, 0x00, 0x80, 0x31, 0xf0, 0xf8, 0x03, 0x0f, 0x3c, 0xc0,
   0xc0, 0x03, 0x0c, 0x30, 0xc0, 0xc0, 0x30, 0x00, 0x36, 0xc3, 0x00, 0xcf,
   0x1f, 0x3c, 0xf0, 0xc0, 0x83, 0x0d, 0x3c, 0x00, 0x0c, 0x03, 0x1b, 0x36,
   0x30, 0x33, 0xcc, 0x00, 0x86, 0x01, 0x03, 0xc0, 0x0c, 0x0c, 0x00, 0x00,
   0xfe, 0xfc, 0xc3, 0x0f, 0xff, 0xfc, 0xf8, 0x37, 0xf0, 0x3f, 0x3c, 0x00,
   0x33, 0x18, 0x0c, 0xff, 0xfc, 0xc3, 0xcf, 0x60, 0x03, 0xcf, 0xef, 0xdf,
   0x3f, 0x03, 0x07, 0x36, 0xf0, 0xc0, 0x03, 0xff, 0x0f, 0x03, 0x0c, 0x60,
   0x00, 0x00, 0x30, 0x00, 0xc0, 0x8c, 0x0d, 0x60, 0xb0, 0x01, 0x00, 0x03,
   0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc6, 0xf0, 0x30, 0x00,
   0x0c, 0x30, 0xc6, 0x03, 0x0c, 0x00, 0xd8, 0xc0, 0x03, 0xc3, 0x00, 0x03,
   0x03, 0xff, 0x03, 0x03, 0xd8, 0xcc, 0x03, 0x0f, 0x36, 0xc0, 0xc0, 0x03,
   0x0c, 0x30, 0xc0, 0xc0, 0x30, 0x00, 0xb6, 0xc1, 0x00, 0x7b, 0x3f, 0x3c,
   0xf0, 0xc0, 0x83, 0x0d, 0x3c, 0x00, 0x0c, 0x03, 0x1b, 0x36, 0x30, 0x33,
   0xcc, 0x00, 0x83, 0x01, 0x06, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0d,
   0x66, 0x98, 0xc1, 0x86, 0xc1, 0x30, 0xf0, 0x60, 0x30, 0x00, 0x33, 0x0c,
   0x0c, 0xb3, 0x0d, 0x66, 0xd8, 0x60, 0x03, 0x6f, 0x30, 0x30, 0x06, 0x03,
   0x07, 0x36, 0xf0, 0xc0, 0x03, 0x03, 0x0c, 0x03, 0x0c, 0x60, 0x00, 0x00,
   0x30, 0x00, 0xc0, 0x8c, 0x0d, 0x60, 0xe0, 0x00, 0x00, 0x03, 0xc0, 0x18,
   0x0c, 0x03, 0x00, 0x00, 0x00, 0x00, 0xc6, 0xd8, 0x30, 0x00, 0x06, 0x18,
   0xc3, 0xff, 0xfc, 0x03, 0x8c, 0x61, 0x03, 0x03, 0x00, 0x80, 0x01, 0x00,
   0x00, 0x06, 0xcc, 0xc6, 0x03, 0xff, 0x33, 0xc0, 0xc0, 0x03, 0x0c, 0x30,
   0xc0, 0xc0, 0x30, 0x00, 0xf6, 0xc0, 0x00, 0x33, 0x6f, 0x3c, 0xf0, 0x60,
   0x83, 0x0d, 0x66, 0x00, 0x0c, 0x03, 0x1b, 0x36, 0x30, 0x1e, 0x78, 0x80,
   0x81, 0x01, 0x06, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x3c, 0xf0,
   0xc0, 0x03, 0xc3, 0x30, 0xf0, 0xc0, 0x30, 0x00, 0x33, 0x06, 0x0c, 0x33,
   0x0f, 0x3c, 0xf0, 0x60, 0x03, 0x3f, 0x30, 0x00, 0x06, 0x03, 0x07, 0x36,
   0xb0, 0x61, 0x03, 0x03, 0x06, 0x03, 0x0c, 0x60, 0x78, 0x0c, 0x30, 0x00,
   0xc0, 0x0c, 0x3f, 0x30, 0xf0, 0x0c, 0x00, 0x03, 0xc0, 0x30, 0x06, 0x03,
   0x00, 0x00, 0x00, 0x00, 0xc3, 0xcc, 0x30, 0x00, 0x83, 0x8f, 0xc1, 0x80,
   0x0d, 0x06, 0x0c, 0x3f, 0x06, 0x03, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x0c,
   0xc6, 0xc6, 0x03, 0x0f, 0x36, 0xc0, 0xc0, 0xff, 0xfc, 0x33, 0xfe, 0xff,
   0x30, 0x00, 0x76, 0xc0, 0x00, 0x03, 0xcf, 0x3c, 0xf0, 0x3f, 0x83, 0xfd,
   0xc3, 0x0f, 0x0c, 0x03, 0x1b, 0x36, 0x30, 0x0c, 0x78, 0xc0, 0x80, 0x01,
   0x0c, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x3c, 0xc0, 0xc0, 0x03,
   0xc3, 0x30, 0xf0, 0xc0, 0x30, 0x00, 0x33, 0x03, 0x0c, 0x33, 0x0f, 0x3c,
   0xf0, 0x60, 0x03, 0x1f, 0x30, 0x00, 0x06, 0x03, 0x0f, 0x33, 0x30, 0x33,
   0x03, 0x03, 0xc3, 0x01, 0x0c, 0xc0, 0xcd, 0x0c, 0x30, 0x00, 0xc0, 0x0c,
   0x6c, 0x30, 0x98, 0x0d, 0x00, 0x03, 0xc0, 0x60, 0x03, 0x03, 0x00, 0xff,
   0x03, 0x00, 0xc3, 0xc6, 0x30, 0x80, 0x01, 0xd8, 0xc0, 0x00, 0x0f, 0x0c,
   0x86, 0x61, 0xfc, 0x03, 0x00, 0x80, 0x01, 0x00, 0x00, 0x06, 0xc3, 0xc6,
   0xff, 0x0f, 0x3c, 0xc0, 0xc0, 0x03, 0x0c, 0x30, 0xf0, 0xc0, 0x30, 0x00,
   0xf6, 0xc0, 0x00, 0x03, 0x8f, 0x3d, 0xf0, 0x00, 0x83, 0x3d, 0x00, 0x18,
   0x0c, 0x03, 0x33, 0x33, 0x33, 0x1e, 0x30, 0x60, 0x80, 0x01, 0x0c, 0xc0,
   0x00, 0x00, 0x00, 0x00, 0xfc, 0x0f, 0x3c, 0xc0, 0xc0, 0x03, 0xc3, 0x30,
   0xf0, 0xc0, 0x30, 0x00, 0xb3, 0x01, 0x0c, 0x33, 0x0f, 0x3c, 0xf0, 0x60,
   0x03, 0x0f, 0x30, 0x00, 0x06, 0x03, 0x0f, 0x33, 0x33, 0x1e, 0x03, 0x83,
   0x01, 0x03, 0x0c, 0x60, 0xcc, 0x0c, 0x30, 0x00, 0xc0, 0x0c, 0x6c, 0x18,
   0x0c, 0x07, 0x00, 0x03, 0xc0, 0xc0, 0x01, 0x03, 0x00, 0x00, 0x00, 0x80,
   0xc1, 0xc3, 0x30, 0xc0, 0x00, 0xf0, 0xc0, 0x00, 0x0f, 0x0c, 0xc6, 0xc0,
   0x00, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x03, 0xc3, 0xc6, 0x03, 0x0f,
   0x3c, 0xc0, 0xc0, 0x03, 0x0c, 0x30, 0xf0, 0xc0, 0x30, 0x00, 0xb6, 0xc1,
   0x00, 0x03, 0x0f, 0x3f, 0xf0, 0x00, 0x83, 0x6d, 0x00, 0x30, 0x0c, 0x03,
   0x33, 0x33, 0x33, 0x33, 0x30, 0x30, 0x80, 0x01, 0x18, 0xc0, 0x00, 0x00,
   0x00, 0x00, 0x06, 0x0f, 0x3c, 0xc0, 0xc0, 0xff, 0xc3, 0x60, 0xf8, 0xc0,
   0x30, 0x00, 0xf3, 0x00, 0x0c, 0x33, 0x0f, 0x3c, 0xf0, 0x30, 0x06, 0x0f,
   0xe0, 0x1f, 0x06, 0x03, 0x9b, 0x31, 0x33, 0x0c, 0x86, 0xc3, 0x00, 0x03,
   0x0c, 0x60, 0x8c, 0x07, 0x00, 0x00, 0xf0, 0x3f, 0x6c, 0x18, 0x0c, 0x06,
   0x00, 0x03, 0xc0, 0xfc, 0xff, 0x3f, 0x18, 0x00, 0x00, 0x80, 0xc1, 0xc1,
   0x30, 0x60, 0x00, 0xf0, 0xc0, 0x00, 0x0f, 0x0c, 0xc3, 0xc0, 0x00, 0xc3,
   0x00, 0x03, 0x06, 0xff, 0x83, 0x01, 0xc0, 0xcc, 0x03, 0x0f, 0x3c, 0xc0,
   0xc0, 0x03, 0x0c, 0x30, 0xf0, 0xc0, 0x30, 0x0c, 0x36, 0xc3, 0x00, 0x03,
   0x0f, 0x3e, 0xf0, 0x00, 0x83, 0xcd, 0x00, 0x30, 0x0c, 0x03, 0x33, 0xb3,
   0x37, 0x33, 0x30, 0x18, 0x80, 0x01, 0x18, 0xc0, 0x00, 0x00, 0x00, 0x00,
   0x03, 0x0f, 0x3c, 0xc0, 0xc0, 0x03, 0xc0, 0xc0, 0xff, 0xc0, 0x30, 0x00,
   0xb3, 0x01, 0x0c, 0x33, 0x0f, 0x3c, 0xf0, 0x1f, 0xfc, 0x0f, 0x00, 0x30,
   0x06, 0x03, 0x9b, 0x31, 0x33, 0x1e, 0xfc, 0x63, 0x00, 0x03, 0x0c, 0x60,
   0x00, 0x00, 0x00, 0x00, 0xc0, 0x8c, 0x6d, 0xcc, 0x0d, 0x06, 0x00, 0x06,
   0x60, 0xc0, 0x01, 0x03, 0x18, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x30, 0x30,
   0x00, 0xf0, 0xff, 0x00, 0x0f, 0x0c, 0xc3, 0xc0, 0x00, 0xc3, 0x00, 0x03,
   0x0c, 0x00, 0xc0, 0x00, 0xc0, 0xf8, 0x03, 0x0f, 0x3c, 0xf0, 0xc0, 0x03,
   0x0c, 0x30, 0xf0, 0xc0, 0x30, 0x0c, 0x36, 0xc6, 0x00, 0x03, 0x0f, 0x3c,
   0xf0, 0x00, 0x83, 0x8d, 0x01, 0x30, 0x0c, 0x03, 0xe3, 0xf1, 0xbc, 0x61,
   0x30, 0x0c, 0x80, 0x01, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f,
   0x3c, 0xc0, 0xc0, 0x03, 0xc0, 0x00, 0xf0, 0xc0, 0x30, 0x00, 0x33, 0x03,
   0x0c, 0x33, 0x0f, 0x3c, 0xf0, 0x00, 0x00, 0x0f, 0x00, 0x30, 0x06, 0x03,
   0xf3, 0x30, 0x33, 0x33, 0x00, 0x33, 0x00, 0x03, 0x0c, 0x60, 0x00, 0x00,
   0x30, 0x00, 0xc0, 0x0c, 0x3f, 0x6c, 0x0f, 0x07, 0x00, 0x06, 0x60, 0x60,
   0x03, 0x03, 0x18, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0x30, 0x18, 0x30, 0x30,
   0xc0, 0x03, 0x0f, 0x0c, 0xc3, 0xc0, 0x00, 0xc3, 0x00, 0x03, 0x18, 0x00,
   0x60, 0x00, 0xc3, 0x00, 0x03, 0x0f, 0x3c, 0xf0, 0xc0, 0x03, 0x0c, 0x30,
   0xf0, 0xc0, 0x30, 0x0c, 0x36, 0xcc, 0x00, 0x03, 0x0f, 0x3c, 0xf0, 0x00,
   0xf6, 0x0c, 0x33, 0x30, 0x0c, 0x03, 0xe3, 0x71, 0xb8, 0x61, 0x30, 0x0c,
   0x80, 0x01, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x3c, 0xf0,
   0xc0, 0x03, 0xc0, 0x00, 0xf0, 0xc0, 0x30, 0x30, 0x33, 0x06, 0x0c, 0x33,
   0x0f, 0x3c, 0xf0, 0x00, 0x00, 0x0f, 0x00, 0x30, 0x06, 0x03, 0xf3, 0x30,
   0xb3, 0x61, 0x00, 0x1b, 0x00, 0x03, 0x0c, 0x60, 0x00, 0x00, 0x30, 0x00,
   0xc0, 0x0c, 0x0c, 0x66, 0x9b, 0x0d, 0x00, 0x0c, 0x30, 0x30, 0x06, 0x03,
   0x18, 0x00, 0xc0, 0x60, 0x80, 0x61, 0x30, 0x0c, 0x60, 0x18, 0xc0, 0x86,
   0x19, 0x06, 0x83, 0x61, 0x80, 0x01, 0x00, 0x03, 0x30, 0x00, 0x30, 0x00,
   0x83, 0x01, 0x03, 0x0f, 0x66, 0xd8, 0x60, 0x03, 0x0c, 0x60, 0xd8, 0xc0,
   0x30, 0x18, 0x33, 0xd8, 0x00, 0x03, 0x0f, 0x6c, 0xd8, 0x00, 0x7c, 0x0c,
   0x66, 0x18, 0x0c, 0x86, 0xc1, 0x30, 0xf0, 0xc0, 0x30, 0x0c, 0x80, 0x01,
   0x60, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0f, 0x66, 0x98, 0xc1, 0x06,
   0xc3, 0x00, 0xd8, 0xc0, 0x30, 0x30, 0x33, 0x0c, 0x0c, 0x33, 0x0f, 0x6c,
   0xd8, 0x00, 0x00, 0x0f, 0x30, 0x30, 0x06, 0x06, 0x63, 0x30, 0xf3, 0xc0,
   0x80, 0x0d, 0x00, 0x06, 0x0c, 0x30, 0x00, 0x00, 0x30, 0x00, 0xc0, 0x0c,
   0x0c, 0xc6, 0xf1, 0x0c, 0x00, 0x18, 0x18, 0x18, 0x0c, 0x03, 0x0c, 0x00,
   0xc0, 0x60, 0x00, 0x3f, 0xfe, 0xfd, 0xcf, 0x0f, 0xc0, 0xfc, 0xf0, 0x03,
   0x03, 0x3f, 0xfe, 0x00, 0x80, 0x01, 0x60, 0x00, 0x18, 0x00, 0x03, 0xff,
   0x03, 0xff, 0xc3, 0xcf, 0x3f, 0xff, 0x0f, 0xc0, 0xcf, 0xc0, 0xfc, 0xf0,
   0x31, 0xf0, 0xff, 0x03, 0x0f, 0xcc, 0xcf, 0x00, 0xc0, 0x0c, 0xcc, 0x0f,
   0x0c, 0xfc, 0xc0, 0x10, 0xe0, 0xc0, 0x30, 0xfc, 0x8f, 0x0f, 0x60, 0xf8,
   0x00, 0xf0, 0x3f, 0x00, 0xfc, 0xff, 0xc3, 0x0f, 0xff, 0xfc, 0xc1, 0xe0,
   0xcf, 0xc0, 0xfc, 0xe0, 0x31, 0x18, 0x3f, 0x33, 0x0f, 0xcc, 0xcf, 0x00,
   0x00, 0x0f, 0xe0, 0x1f, 0x7c, 0xfc, 0x63, 0xe0, 0xdf, 0xc0, 0xfe, 0xfc,
   0x0f, 0x1c, 0x0c, 0x1c, 0x00, 0x00
};

small_ssd1306::small_ssd1306(int8_t MOSI, int8_t CLOCK, int8_t DC, int8_t RESET,
			     int8_t CS, int8_t POWER, int8_t INVERT_SCREEN, int8_t ORIENTATION){
  mosi = MOSI;
  clock = CLOCK;
  dc = DC;
  reset = RESET;
  cs = CS;
  power = POWER;
  invert_screen = INVERT_SCREEN;
  orientation = ORIENTATION;
  cursor_x = 0;
  cursor_y = 0;
  font_size = 0;
  pinMode(dc, OUTPUT);
  pinMode(cs, OUTPUT);
  pinMode(mosi, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(power, OUTPUT);


}

void small_ssd1306::on(void) {

  pinMode(mosi, OUTPUT);
  pinMode(dc, OUTPUT);
  pinMode(cs, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(reset, OUTPUT);
 
  digitalWrite(power, LOW); // turn oled on
  delay(20);
  // Setup reset pin direction (used by both SPI and I2C)  
  digitalWrite(reset, HIGH);
  // VDD (3.3V) goes high at start, lets just chill for a ms
  delay(1);
  // bring reset low
  digitalWrite(reset, LOW);
  // wait 10ms
  delay(10);
  // bring out of reset
  digitalWrite(reset, HIGH);
  // turn on VCC (9V?)
    // Init sequence for 128x32 OLED module
  spi_write(SSD1306_DISPLAYOFF);                    // 0xAE
  spi_write(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
  spi_write(0x80);                                  // the suggested ratio 0x80
  spi_write(SSD1306_SETMULTIPLEX);                  // 0xA8
  spi_write(0x1F);
  spi_write(SSD1306_SETDISPLAYOFFSET);              // 0xD3
  spi_write(0x0);                                   // no offset
  spi_write(SSD1306_SETSTARTLINE | 0x0);            // line #0
  spi_write(SSD1306_CHARGEPUMP);                    // 0x8D
  spi_write(0x14); //switchcap
  spi_write(SSD1306_MEMORYMODE);                    // 0x20
  spi_write(0x00);                                  // 0x0 act like ks0108
  spi_write(SSD1306_SEGREMAP | 0x1);
  spi_write(SSD1306_COMSCANDEC);
  spi_write(SSD1306_SETCOMPINS);                    // 0xDA
  spi_write(0x02);
  spi_write(SSD1306_SETCONTRAST);                   // 0x81
  spi_write(0xCF);
  spi_write(SSD1306_SETPRECHARGE);                  // 0xd9
  spi_write(0xF1); //switch cap
  spi_write(SSD1306_SETVCOMDETECT);                 // 0xDB
  spi_write(0x40);
  spi_write(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
  if(invert_screen) {
    spi_write(SSD1306_INVERTDISPLAY);
  } else {
    spi_write(SSD1306_NORMALDISPLAY);
  }
  if(orientation) {
    spi_write(SSD1306_SEGREMAP);
    spi_write(SSD1306_COMSCANINC);
  }
  spi_write(SSD1306_DISPLAYON); //--turn on oled panel

  //yuck?
}
void small_ssd1306::off(void) {
  spi_write(SSD1306_DISPLAYOFF);	// put the OLED display in sleep mode
  spi_write(0x8D);  // disable charge pump
  spi_write(0x10);  // disable charge pump

  delay(10);
  digitalWrite(power, HIGH);

  pinMode(mosi, INPUT);
  pinMode(dc, INPUT);
  pinMode(cs, INPUT);
  pinMode(clock, INPUT);
  pinMode(reset, INPUT);

  digitalWrite(reset, LOW);
  digitalWrite(mosi, LOW);
  digitalWrite(dc, LOW);
  digitalWrite(cs, LOW);
  digitalWrite(clock, LOW);
}

void small_ssd1306::invert(void) {
  if(invert_screen) {
    invert_screen=0;
    spi_write(SSD1306_NORMALDISPLAY);
  } else {
    invert_screen=1;
    spi_write(SSD1306_INVERTDISPLAY);
  }
}

void small_ssd1306::set_font(int8_t value) {
  font_size=value;
}

void small_ssd1306::clear(void) {
  memset(buffer, 0, (SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT/8));
}

void small_ssd1306::set_pixel(uint8_t x, uint8_t y, uint8_t on) {
  if ((x < 0) || (x >= SSD1306_LCDWIDTH) || (y < 0) || (y >= SSD1306_LCDHEIGHT))
    return;
  // x is which column
  if (on) 
    buffer[x+ (y/8)*SSD1306_LCDWIDTH] |= (1 << (y&7));  
  else
    buffer[x+ (y/8)*SSD1306_LCDWIDTH] &= ~(1 << (y&7)); 
}

void small_ssd1306::draw_bitmap(uint8_t x, uint8_t y, const uint8_t *bitmap,
				uint16_t w, uint16_t h, uint16_t w2, uint16_t h2,
				uint16_t w_size, uint16_t h_size, uint8_t on) {
  int16_t i, j, byteWidth = (w_size + 7) / 8;

  for(j=h; j<h_size; j++) {
    if(j >= h2) {
      break;
    }
    for(i=w; i<w_size; i++ ) {
      if( i >= w2) {
	break;
      }
      if(pgm_read_byte(bitmap + j * byteWidth + i / 8) & (1 << (i % 8))) {
	  set_pixel(x+i-w, y+j-h, on);
      }
    }
  }
}

size_t small_ssd1306::write(uint8_t c) {
  uint16_t character;
  if(font_size == 1) {
    if(c >= 0x30 && c < 0x40) {
      character = (c - 0x30)*13;
      draw_bitmap(cursor_x, cursor_y, terminus, character, 0, character+13, 20, 136, 20, 1);
      cursor_x+=17;
      return 1;
    }
  } 
  if (c == '\n') {
    cursor_y += 16;
    cursor_x  = 0;
  } else if (c == ' ') {
    cursor_x  += 11;
  } else if (c >= 0x21 && ( c <= 0x7E)) {
    character = (c-0x21)*10;
      draw_bitmap(cursor_x, cursor_y, terminus_font, character, 0, character+10, 15, 944, 15, 1);
      cursor_x+=11;

    if ((cursor_x > (SSD1306_LCDWIDTH - 11))) {
      cursor_y += 16;
      cursor_x = 0;
    }
  }
return 1;

}

void small_ssd1306::set_cursor(int8_t x, int8_t y) {
  cursor_x = x;
  cursor_y = y;
}

void small_ssd1306::update(void) {
  spi_write(SSD1306_COLUMNADDR);
  spi_write(0);   // Column start address (0 = reset)
  spi_write(127); // Column end address (127 = reset)

  spi_write(SSD1306_PAGEADDR);
  spi_write(0); // Page start address (0 = reset)
  spi_write(3); // Page end address

  for (uint16_t i=0; i<(SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT/8); i++) {
    digitalWrite(dc, HIGH);
    digitalWrite(cs, LOW);
    shiftOut(mosi, clock, MSBFIRST, buffer[i]);
    digitalWrite(cs, HIGH);
  }


}

void small_ssd1306::spi_write(uint8_t data) {
  digitalWrite(dc, LOW);
  digitalWrite(cs, LOW);
  shiftOut(mosi, clock, MSBFIRST, data);
  digitalWrite(cs, HIGH);
}

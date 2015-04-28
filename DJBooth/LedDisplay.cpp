//
//  LedDisplay.cpp
//  DJBooth
//
//  Created by Andrew Hughes on 4/26/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#include "LedDisplay.h"
#include "MicroColor.h"


DMAMEM int displayMemory[LEDS_PER_STRIP*6];
int drawingMemory[LEDS_PER_STRIP*6];

LedDisplay::LedDisplay() {
    leds = new OctoWS2811(LEDS_PER_STRIP, displayMemory, drawingMemory, WS2811_CONFIG);
    leds->begin();
}

LedDisplay::~LedDisplay() {
    delete(leds);
}

void LedDisplay::show() {
    leds->show();
}

void LedDisplay::setBrightness(double b) {
    //assert(b > 0.0 && b < 1.0);
    brightness = b;
}

void LedDisplay::setPixel(int num, byte r, byte g, byte b) {
    
    if (applyBrightness) {
        r = (byte)round((double)r * brightness);
        g = (byte)round((double)g * brightness);
        b = (byte)round((double)b * brightness);
    }
    
    leds->setPixel(num,r,g,b);
}

void LedDisplay::setPixel(int num, uint32_t color) {
    RGB rgb;
    MicroColor::int2Rgb(color, &rgb);
    setPixel(num, rgb.r, rgb.g, rgb.b);
}

void LedDisplay::setPixel(int row, int col, byte r, byte g, byte b) {
    leds->setPixel(pixelNumForRowCol(row,col), r,g,b);
}

void LedDisplay::setPixel(int row, int col, uint32_t color) {
    setPixel(pixelNumForRowCol(row,col), color);
}

int LedDisplay::pixelNumForRowCol(int row, int col) {
    return row*LEDS_PER_STRIP + col;
}

void LedDisplay::setPixelsAllRows(int col, byte r, byte g, byte b) {
    
   // assert(<#__e#>)ERT(num > 0, "Pixel num must be greater than 0");
    //assert(num < LEDS_PER_STRIP-1, "Pixel num must be less than (LEDS_PER_STRIP - 1)");

    int i;
    for (i=0;i<LEDS_NUM_STRIPS;i++) {
        setPixel(pixelNumForRowCol(i,col), r, g, b);
    }
    
    
}

void LedDisplay::setPixelsAllRows(int num, uint32_t color) {
    RGB rgb;
    MicroColor::int2Rgb(color, &rgb);
    setPixelsAllRows(num, rgb.r, rgb.g, rgb.b);
}

void LedDisplay::setAllPixels(byte r, byte g, byte b) {
    for (int i=0;i<LEDS_PER_STRIP;i++) {
        setPixelsAllRows(i,r,g,b);
    }
}

void LedDisplay::setAllPixels(uint32_t color) {
    RGB rgb;
    MicroColor::int2Rgb(color, &rgb);
    setAllPixels(rgb.r, rgb.g, rgb.b);
}

void LedDisplay::setAllPixelsOff() {
    int i;
    for(i=0;i< LEDS_NUM_STRIPS * LEDS_PER_STRIP; i++) {
        leds->setPixel(i,0);
    }
}

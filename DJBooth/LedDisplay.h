//
//  LedDisplay.h
//  DJBooth
//
//  Created by Andrew Hughes on 4/26/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#ifndef __DJBooth__LedDisplay__
#define __DJBooth__LedDisplay__

#include <OctoWS2811.h>

#define LEDS_PER_STRIP 66
#define LEDS_NUM_STRIPS 8
#define WS2811_CONFIG WS2811_GRB | WS2811_800kHz


class LedDisplay {
    
public:


    OctoWS2811 * leds;
    
    double brightness = 1.0;
    
    bool applyBrightness = true;

    LedDisplay();
    ~LedDisplay();
    
    void show();
    
    void setPixel(int row, int col, byte r, byte g, byte b);
    void setPixel(int row, int col, uint32_t color);
    
    void setPixel(int num, byte r, byte g, byte b);
    void setPixel(int num, uint32_t color);
    
    void setPixelsAllRows(int num, byte r, byte g, byte b);
    void setPixelsAllRows(int num, uint32_t color);

    void setAllPixels(byte r, byte g, byte b);
    void setAllPixels(uint32_t color);
    
    void setAllPixelsOff();

    void setBrightness(double b);
    
    int pixelNumForRowCol(int row, int col);

};







#endif /* defined(__DJBooth__LedDisplay__) */

//
//  ColorWheel.h
//  DJBooth
//
//  Created by Andrew Hughes on 4/26/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#ifndef __DJBooth__ColorWheel__
#define __DJBooth__ColorWheel__

#include "Arduino.h"
#include "MicroColor.h"

class ColorWheel {
private:
    byte wheelPosition = 0;
public:
    void increment();
    uint32_t getColor();
    uint32_t getColorAndIncrement();
    void getColorRgb(RGB * rgb);
    RGB getColorRgb();
};

#endif /* defined(__DJBooth__ColorWheel__) */

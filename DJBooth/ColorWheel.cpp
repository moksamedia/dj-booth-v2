//
//  ColorWheel.cpp
//  DJBooth
//
//  Created by Andrew Hughes on 4/26/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#include "ColorWheel.h"


uint32_t ColorWheel::getColorAndIncrement() {
    uint32_t color = getColor();
    increment();
    return color;
}

void ColorWheel::increment() {
    wheelPosition += 1;
    if (wheelPosition >= 255) {
        wheelPosition = 0;
    }
}

uint32_t ColorWheel::getColor() {
    if(wheelPosition < 85) {
        return MicroColor::rgb2Int(wheelPosition * 3, 255 - wheelPosition * 3, 0);
    }
    else if(wheelPosition < 170) {
        wheelPosition -= 85;
        return MicroColor::rgb2Int(255 - wheelPosition * 3, 0, wheelPosition * 3);
    }
    else {
        wheelPosition -= 170;
        return MicroColor::rgb2Int(0, wheelPosition * 3, 255 - wheelPosition * 3);
    }
}

RGB ColorWheel::getColorRgb() {
    RGB rgb;
    getColorRgb(&rgb);
    return rgb;
}

void ColorWheel::getColorRgb(RGB * rgb) {
    if(wheelPosition < 85) {
        rgb->r = wheelPosition * 3;
        rgb->g = 255 - wheelPosition * 3;
        rgb->b = 0;
    }
    else if(wheelPosition < 170) {
        wheelPosition -= 85;
        rgb->r = 255 - wheelPosition * 3;
        rgb->g = 0;
        rgb->b = wheelPosition * 3;
    }
    else {
        wheelPosition -= 170;
        rgb->r = 0;
        rgb->g = wheelPosition * 3;
        rgb->b = 255 - wheelPosition * 3;
    }
}
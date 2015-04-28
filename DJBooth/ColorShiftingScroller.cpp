//
//  ColorShiftingScroller.cpp
//  DJBooth
//
//  Created by Andrew Hughes on 4/26/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#include "ColorShiftingScroller.h"
#include "MicroColor.h"

ColorShiftingScroller::ColorShiftingScroller(LedDisplay * display) : Animation(display) {
    upAndDown = new UpAndDown(0,499);
    interp1 = new Interp(0,359,500);
    interp2 = new Interp(2000,80000,500);
}

ColorShiftingScroller::~ColorShiftingScroller() {
    delete(upAndDown);
    delete(interp1);
    delete(interp2);
}

bool ColorShiftingScroller::animate() {
    int i = upAndDown->getNext();
    flashOffset(i, 2, MicroColor::makeColor(interp1->linear(i), 80, 30), (uint32_t)0);
    additionalDelay = (unsigned int)interp2->smooth2(i);
}

int ColorShiftingScroller::getAdditionalDelayMicros() {
    return additionalDelay;
}

void ColorShiftingScroller::flashOffset(int offset, int spacing, uint32_t onColor, uint32_t offColor) {
    
    int x,y;
    
    for (y=0;y<LEDS_NUM_STRIPS;y++) {
        
        for (x=0;x<LEDS_PER_STRIP;x++) {
            
            if ( (x + offset) % spacing == 0 ) {
                display->setPixel(y, x, onColor);
            }
            else {
                display->setPixel(y, x, offColor);
            }
        }
    }
}




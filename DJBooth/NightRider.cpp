//
//  NightRider.cpp
//  DJBooth
//
//  Created by Andrew Hughes on 4/26/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#include "NightRider.h"

NightRider::NightRider(int repeats, LedDisplay * display) : Animation(display) {
    this->repeats = repeats;
    upAndDown = new UpAndDown(0, LEDS_PER_STRIP-1);
    colorWheel = new ColorWheel();
}

NightRider::~NightRider() {
    delete(upAndDown);
    delete(colorWheel);
}

int NightRider::getAdditionalDelayMicros() {
    return 0;
}

bool NightRider::animate() {
 
    uint32_t color = colorWheel->getColor();
    
    currentPosition = upAndDown->getNext();
    
    display->setAllPixelsOff();

    display->setPixelsAllRows(currentPosition, color);
    display->setPixelsAllRows(currentPosition+1, color);
    display->setPixelsAllRows(currentPosition-1, color);
    
    display->setPixelsAllRows(LEDS_PER_STRIP - currentPosition, color);
    display->setPixelsAllRows(LEDS_PER_STRIP - currentPosition+1, color);
    display->setPixelsAllRows(LEDS_PER_STRIP - currentPosition-1, color);
    
    if (upAndDown->hasLooped) {
        currentRepeat++;
        colorWheel->increment();
    }
    
    return currentRepeat <= repeats;
    
}
//
//  PushButton.cpp
//  DJBooth
//
//  Created by Andrew Hughes on 4/27/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#include "PushButton.h"
PushButton::PushButton(uint8_t pin) {
    this->pin = pin;
    pinMode(pin, INPUT_PULLUP);
}

bool PushButton::state() {
    
    int state = digitalRead(pin);
    
    if (state == LOW && !oncePerFlag) {
        oncePerFlag = true;
        return true;
    }
    else if (state == LOW) {
        return false;
    }
    else {
        oncePerFlag = false;
        return false;
    }
}


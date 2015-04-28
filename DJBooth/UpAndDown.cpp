//
//  UpAndDown.cpp
//  DJBooth
//
//  Created by Andrew Hughes on 4/26/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#include "UpAndDown.h"

UpAndDown::UpAndDown(int min, int max) {
    this->min = min;
    this->max = max;
}

int UpAndDown::getNext() {
    
    if (isFirstNext) {
        isFirstNext = false;
        return current;
    }
    
    int next = current;
    
    hasLooped = false;

    if (goingDown) {
        current -= 1;
        if (current < min) {
            current = min + 1;
            goingDown = false;
        }
        else if (current == min) {
            hasLooped = true;
        }
    }
    else {
        current += 1;
        if (current > max) {
            current = max-1;
            goingDown = true;
        }
    }
    
    return current;
    
}
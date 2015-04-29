//
//  ScrollArray.cpp
//  DJBooth
//
//  Created by Andrew Hughes on 4/28/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#include "ScrollArrayAnimation.h"

ScrollArrayAnimation::ScrollArrayAnimation(bool rightToLeft, uint32_t color) {
    this->rightToLeft = rightToLeft;
    this->color = color;
}

ScrollArrayAnimation::ScrollArrayAnimation(bool rightToLeft, uint32_t color, uint32_t * array, unsigned int arraySize) {
    
    this->rightToLeft = rightToLeft;
    this->color = color;
    
    setArray(array, arraySize);
}

void ScrollArrayAnimation::setArray(uint32_t * array, unsigned int arraySize) {
    
    this->array = array;
    this->arraySize = arraySize;
    this->setOffsetAtBeginning();
    
}

void ScrollArrayAnimation::setOffsetAtBeginning() {
    
    if (rightToLeft) {
        this->offset = LEDS_PER_STRIP;
    }
    else {
        this->offset = -arraySize;
    }
    
}

bool ScrollArrayAnimation::animate() {
    
    drawArray(array, arraySize, offset, color, (uint32_t)0);
    
    display->show();
    
    if (rightToLeft) {
        offset--;
        return (offset > -arraySize);
    }
    else {
        offset++;
        return (offset < LEDS_PER_STRIP)
    }
    
}

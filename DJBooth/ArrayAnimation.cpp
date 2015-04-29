//
//  ArrayAnimation.cpp
//  DJBooth
//
//  Created by Andrew Hughes on 4/28/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#include "ArrayAnimation.h"

void ArrayAnimation::drawArray(uint32_t * array, int arraySize, int offset, uint32_t onColor, uint32_t offColor) {
    
    int x, y, val;
    
    // Iterate over the rows
    for (y=0;y<LEDS_NUM_STRIPS;y++) {
        
        // Iterate through the columns
        for (x=0;x<LEDS_PER_STRIP;x++) {
            
            val = offsetArray(x,y,offset,array,arraySize);
            
            if ( val == 1 ) {
                display->setPixel(x + y*LEDS_PER_STRIP, onColor);
            }
            else {
                display->setPixel(x + y*LEDS_PER_STRIP, offColor);
            }
        }
    }
    
}

int ArrayAnimation::offsetArray(int x, int y, int offset, uint32_t * array, int arraySize) {
    
    if (x < offset) {
        return 0;
    }
    else if (x >= offset + arraySize) {
        return 0;
    }
    else {
        return *(array + y * arraySize + x - offset);
    }
    
}

//
//  ScrollArray.h
//  DJBooth
//
//  Created by Andrew Hughes on 4/28/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#ifndef __DJBooth__ScrollArray__
#define __DJBooth__ScrollArray__

#include "ArrayAnimation.h"
#include "Arduino.h"

class ScrollArrayAnimation : public ArrayAnimation {
public:
    
    uint32_t * array;
    
    unsigned int arraySize;
    
    int offset;

    bool rightToLeft = false;

    uint32_t color;
    
    ScrollArrayAnimation();
    ScrollArrayAnimation(uint32_t * array, unsigned int arraySize);
    
    void setArray(uint32_t * array, unsigned int arraySize);
    
    bool animate();
    
    
protected:
    
    int offset;
    
    void ArrayAnimation::scrollArrayRL(uint32_t * array, unsigned int arraySize, unsigned int delay);
    void ArrayAnimation::scrollArrayLR(uint32_t * array, unsigned int arraySize, unsigned int delay);
};

#endif /* defined(__DJBooth__ScrollArray__) */

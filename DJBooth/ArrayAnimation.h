//
//  ArrayAnimation.h
//  DJBooth
//
//  Created by Andrew Hughes on 4/28/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#ifndef __DJBooth__ArrayAnimation__
#define __DJBooth__ArrayAnimation__

#include "Arduino.h"
#include "Animation.h"

class ArrayAnimation : public Animation {
    
protected:
    void drawArray(unsigned int * array, int arraySize, int offset, uint32_t onColor, uint32_t offColor);
    int ArrayAnimation::offsetArray(int x, int y, int offset, uint32_t * array, int arraySize);
};


#endif /* defined(__DJBooth__ArrayAnimation__) */

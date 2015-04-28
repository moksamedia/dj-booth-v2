//
//  ColorShiftingScroller.h
//  DJBooth
//
//  Created by Andrew Hughes on 4/26/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#ifndef __DJBooth__ColorShiftingScroller__
#define __DJBooth__ColorShiftingScroller__

#include "Animation.h"
#include "Interp.h"
#include "UpAndDown.h"

class ColorShiftingScroller : public Animation {
public:
    ColorShiftingScroller(LedDisplay * display);
    ~ColorShiftingScroller();
    bool animate();
    int getAdditionalDelayMicros();
    void flashOffset(int offset, int spacing, uint32_t onColor, uint32_t offColor);
    
    bool flip = false;
    UpAndDown * upAndDown;
    Interp * interp1;
    Interp * interp2;
    unsigned int additionalDelay;
    
};

#endif /* defined(__DJBooth__ColorShiftingScroller__) */

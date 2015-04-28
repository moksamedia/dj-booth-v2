//
//  NightRider.h
//  DJBooth
//
//  Created by Andrew Hughes on 4/26/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#ifndef __DJBooth__NightRider__
#define __DJBooth__NightRider__

#include "Animation.h"
#include "UpAndDown.h"
#include "ColorWheel.h"

class NightRider : public Animation {
public:
    NightRider(int repeats, LedDisplay * display);
    ~NightRider();
    UpAndDown * upAndDown;
    ColorWheel * colorWheel;
    bool animate();
    int getAdditionalDelayMicros();
    int repeats = 50;
    int currentRepeat = 0;
    int currentPosition = 0;
};

#endif /* defined(__DJBooth__NightRider__) */

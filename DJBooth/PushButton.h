//
//  PushButton.h
//  DJBooth
//
//  Created by Andrew Hughes on 4/27/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#ifndef __DJBooth__PushButton__
#define __DJBooth__PushButton__

#include "Arduino.h"

class PushButton {
    uint8_t pin;
    bool oncePerFlag = false;
public:
    PushButton(uint8_t pint);
    bool state();
};


#endif /* defined(__DJBooth__PushButton__) */

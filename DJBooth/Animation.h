//
//  Animation.h
//  DJBooth
//
//  Created by Andrew Hughes on 4/26/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#ifndef __DJBooth__Animation__
#define __DJBooth__Animation__

#include "LedDisplay.h"

class Animation {
public:
    Animation(LedDisplay * display);
    virtual bool animate() = 0;
    virtual int getAdditionalDelayMicros() = 0;;
    
protected:
    LedDisplay * display;
    
};


#endif /* defined(__DJBooth__Animation__) */

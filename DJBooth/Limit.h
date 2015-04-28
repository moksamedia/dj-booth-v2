//
//  Limit.h
//  DJBooth
//
//  Created by Andrew Hughes on 4/26/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#ifndef __DJBooth__Limit__
#define __DJBooth__Limit__

#include "Arduino.h"

class Limit {
public:

    static int limit(int val, int min, int max);
    static byte limit(byte val, byte min, byte max);
    static uint16_t limit(uint16_t val, uint16_t min, uint16_t max);
    static float limit(float val, float min, float max);
    static double limit(double val, double min, double max);

};

#endif /* defined(__DJBooth__Limit__) */

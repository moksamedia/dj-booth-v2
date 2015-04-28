//
//  Limit.cpp
//  DJBooth
//
//  Created by Andrew Hughes on 4/26/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#include "Limit.h"

int Limit::limit(int val, int min, int max) {
    if (val > max) return max;
    if (val < min) return min;
    return val;
}

byte Limit::limit(byte val, byte min, byte max) {
    if (val > max) return max;
    if (val < min) return min;
    return val;
}

uint16_t Limit::limit(uint16_t val, uint16_t min, uint16_t max) {
    if (val > max) return max;
    if (val < min) return min;
    return val;
}

float Limit::limit(float val, float min, float max) {
    if (val > max) return max;
    if (val < min) return min;
    return val;
}

double Limit::limit(double val, double min, double max) {
    if (val > max) return max;
    if (val < min) return min;
    return val;
}
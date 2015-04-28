#ifndef ColorUtils_LocalLibrary_h
#define ColorUtils_LocalLibrary_h

#include "Arduino.h"

template<typename T>
T Limit(T val, T min, T max) {
    if (val > max) return max;
    if (val < min) return min;
    return val;
}

struct _RGB {
    byte r;
    byte g;
    byte b;
}; typedef struct _RGB RGB;

struct _HSV {
    double h;
    double s;
    double v;
}; typedef struct _HSV HSV;

struct _HSL {
    double h;
    double s;
    double v;
}; typedef struct _HSL HSL;

class MicroColor {
    
public:
    
    RGB rgb;
    
    MicroColor(int colorVal);
    MicroColor(uint32_t colorVal);
    MicroColor(byte r, byte g, byte b);
    
    void adjustBrightness(float val);
    
    void setColor(int colorVal);
    void setColor(uint32_t colorVal);
    void setColor(byte r, byte g, byte b);
   
    static void int2Rgb(uint32_t colorVal, RGB * rgb);
    static uint32_t rgb2Int(RGB * rgb);
    static uint32_t rgb2Int(byte r, byte g, byte b);
    
    static uint32_t makeColor(unsigned int hue, unsigned int saturation, unsigned int lightness);
    static unsigned int h2rgb(unsigned int v1, unsigned int v2, unsigned int hue);
    
};

#endif

#include "MicroColor.h"

MicroColor::MicroColor(int colorVal) {
    setColor((uint32_t)colorVal);
}

MicroColor::MicroColor(uint32_t colorVal) {
    setColor(colorVal);
}

MicroColor::MicroColor(byte r, byte g, byte b) {
    setColor(r, g, b);
}

void MicroColor::adjustBrightness(float val) {
    
}

void MicroColor::setColor(int colorVal) {
    MicroColor::int2Rgb((int)colorVal, &rgb);
}

void MicroColor::setColor(uint32_t colorVal) {
    MicroColor::int2Rgb(colorVal, &rgb);
}

void MicroColor::setColor(byte r, byte g, byte b) {
    rgb.r = r;
    rgb.g = g;
    rgb.b = b;
}

void MicroColor::int2Rgb(uint32_t colorVal, RGB * rgb)  {
    rgb->r = (colorVal >> 16) & 0xFF;  // Extract the RR byte
    rgb->g = (colorVal >> 8) & 0xFF;   // Extract the GG byte
    rgb->b = (colorVal) & 0xFF;
}

uint32_t MicroColor::rgb2Int(RGB * rgb) {
    return (rgb->r << 16) | (rgb->g << 8) | rgb->b;
}

uint32_t MicroColor::rgb2Int(byte r, byte g, byte b) {
    return (r << 16) | (g << 8) | b;
}

uint32_t MicroColor::makeColor(unsigned int hue, unsigned int saturation, unsigned int lightness) {
    unsigned int red, green, blue;
    unsigned int var1, var2;
    
    if (hue > 359) hue = hue % 360;
    if (saturation > 100) saturation = 100;
    if (lightness > 100) lightness = 100;
    
    // algorithm from: http://www.easyrgb.com/index.php?X=MATH&H=19#text19
    if (saturation == 0) {
        red = green = blue = lightness * 255 / 100;
    } else {
        if (lightness < 50) {
            var2 = lightness * (100 + saturation);
        } else {
            var2 = ((lightness + saturation) * 100) - (saturation * lightness);
        }
        var1 = lightness * 200 - var2;
        red = h2rgb(var1, var2, (hue < 240) ? hue + 120 : hue - 240) * 255 / 600000;
        green = h2rgb(var1, var2, hue) * 255 / 600000;
        blue = h2rgb(var1, var2, (hue >= 120) ? hue - 120 : hue + 240) * 255 / 600000;
    }
    return (red << 16) | (green << 8) | blue;
}

unsigned int MicroColor::h2rgb(unsigned int v1, unsigned int v2, unsigned int hue)
{
    if (hue < 60) return v1 * 60 + (v2 - v1) * hue;
    if (hue < 180) return v2 * 60;
    if (hue < 240) return v1 * 60 + (v2 - v1) * (240 - hue);
    return v1 * 60;
}

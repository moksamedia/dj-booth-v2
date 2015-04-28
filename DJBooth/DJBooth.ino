#include "Arduino.h"
#include <ArduinoUnit.h>
#include "MicroColor.h"
#include "constants.h"
#include "LedDisplay.h"
#include "UpAndDown.h"
#include "NightRider.h"
#include "Interp.h"
#include "ColorShiftingScroller.h"
#include "AnimationPool.h"
#include "PushButton.h"

//#define TESTING

#ifndef TESTING

////////////////////////////////////////////////////////////////////////////////////

LedDisplay display;

#define MAX_CYCLE_DELAY 500000

NightRider nightRider(30, &display);

ColorShiftingScroller colorShiftingScroller(&display);

AnimationPool animationPool(2);

Animation * currentAnimation;

PushButton * nextAnimationButton;

bool button2toggle = false;
bool readButton2() {
    nextAnimationButton->state();
}

int readKnob1() {
    return analogRead(17);
}

int readKnob2() {
    return analogRead(18);
}

int getCycleDelayMicros() {
    int val = readKnob2();
    Serial.print("Knob2 = ");Serial.println(val);
    val = Interp::SLOWACC(4, 0, 1024, 1024, val);
    int dly = int(((float)val / 1024.0) * (float)MAX_CYCLE_DELAY);
    return dly;
}

double getBrightness() {
    int val = readKnob1();
    Serial.print("Knob1 = ");Serial.println(val);
    val = Interp::SLOWACC(2, 0, 1024, 1024, val);
    return (double)val / 1024;
}

void setup() {
    
    nextAnimationButton = new PushButton(19);
    
    animationPool.addAnimation(&nightRider,0);
    animationPool.addAnimation(&colorShiftingScroller,1);

    currentAnimation = animationPool.getNextAnimation();

    pinMode(0,INPUT_PULLUP);
    pinMode(1, OUTPUT);
    digitalWrite(1, HIGH);
    pinMode(19, INPUT_PULLUP);

}

unsigned long previousMicros = 0;
unsigned long cycleDelayMicros = 5;

void loop() {
    
    cycleDelayMicros = getCycleDelayMicros() + currentAnimation->getAdditionalDelayMicros();

    currentAnimation->animate();
    
    double brightness = getBrightness();
    display.setBrightness(brightness);
    
    display.show();

    delayMicroseconds(cycleDelayMicros);
    
    if (readButton2()) {
        currentAnimation = animationPool.getNextAnimation();
    }
    
    
    /*
     unsigned long currentMicros = micros();

    Serial.print("currentMicros = ");Serial.print(currentMicros);Serial.print(", previousMicros = ");Serial.print(previousMicros);Serial.print(", cycleDelayMicros = ");Serial.println(cycleDelayMicros);
    
    if(currentMicros - previousMicros > cycleDelayMicros) {
        previousMicros = currentMicros;
        currentAnimation->animate();
        double brightness = getBrightness();
        display.setBrightness(brightness);
        display.show();
        Serial.println("Showing ...");
    }
    else {
        Serial.println("Skipping...");
    }
    */
    
}

#else

test(Limit) {
    byte v = 10;
    v = Limit<byte>(v, 0, 11);
    assertEqual(v, 10);
    v = Limit<byte>(v, 5, 8);
    assertEqual(v, 8);
    v = 0;
    v = Limit<byte>(v, 22, 0xFF);
    assertEqual(v, 22);
}

test(MicroColor1)
{
    MicroColor mc((uint32_t)0xFFFFFF);
    assertEqual(mc.rgb.r, 0xFF);
    assertEqual(mc.rgb.g, 0xFF);
    assertEqual(mc.rgb.b, 0xFF);
    
    mc.setColor((uint32_t)0);
    assertEqual(mc.rgb.r, 0);
    assertEqual(mc.rgb.g, 0);
    assertEqual(mc.rgb.b, 0);

    mc.setColor((uint32_t)0xA1B1CC);
    assertEqual(mc.rgb.r, 0xA1);
    assertEqual(mc.rgb.g, 0xB1);
    assertEqual(mc.rgb.b, 0xCC);

}

test(UpAndDown) {
    
    UpAndDown ud(0,10);
    
    assertEqual(ud.getNext(), 0);
    assertEqual(ud.getNext(), 1);
    assertEqual(ud.getNext(), 2);
    assertEqual(ud.getNext(), 3);
    assertEqual(ud.getNext(), 4);
    assertEqual(ud.getNext(), 5);
    assertEqual(ud.getNext(), 6);
    assertEqual(ud.getNext(), 7);
    assertEqual(ud.getNext(), 8);
    assertEqual(ud.getNext(), 9);
    assertEqual(ud.goingDown, false);
    assertEqual(ud.getNext(), 10);
    assertEqual(ud.getNext(), 9);
    assertEqual(ud.goingDown, true);
    assertEqual(ud.getNext(), 8);
    assertEqual(ud.getNext(), 7);
    assertEqual(ud.getNext(), 6);
    assertEqual(ud.getNext(), 5);
    assertEqual(ud.getNext(), 4);
    assertEqual(ud.getNext(), 3);
    assertEqual(ud.getNext(), 2);
    assertEqual(ud.getNext(), 1);
    assertEqual(ud.hasLooped, false);
    assertEqual(ud.getNext(), 0);
    assertEqual(ud.hasLooped, true);
    
}

void setup()
{
    Serial.begin(9600);
    while(!Serial); // for the Arduino Leonardo/Micro only
    Serial.println("Running...");
}

void loop()
{
    Test::min_verbosity |= TEST_VERBOSITY_ASSERTIONS_ALL;
    Test::run();
    delay(5000);
}

#endif
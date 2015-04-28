//
//  AnimationPool.cpp
//  DJBooth
//
//  Created by Andrew Hughes on 4/27/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#include "AnimationPool.h"

AnimationPool::AnimationPool(int numAnimations) {
    this->numAnimations = numAnimations;
    animations = new Animation*[numAnimations];
}

AnimationPool::~AnimationPool() {
    delete(animations);
}

void AnimationPool::addAnimation(Animation * anim, int index) {
    animations[index] = anim;
}

Animation * AnimationPool::getAnimation(int index) {
    return animations[index];
}

int AnimationPool::getNumberOfAnimations() {
    return numAnimations;
}

Animation* AnimationPool::getNextAnimation() {
    currentAnimation += 1;
    if (currentAnimation >= numAnimations) currentAnimation = 0;
    return animations[currentAnimation];
}
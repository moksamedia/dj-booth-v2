//
//  AnimationPool.h
//  DJBooth
//
//  Created by Andrew Hughes on 4/27/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#ifndef __DJBooth__AnimationPool__
#define __DJBooth__AnimationPool__

#include "Animation.h"

class AnimationPool {
private:
    int numAnimations;
    int currentAnimation = 0;
    Animation ** animations;
public:
    AnimationPool(int numAnimations);
    ~AnimationPool();
    void addAnimation(Animation * anim,  int index);
    Animation * getAnimation(int index);
    int getNumberOfAnimations();
    Animation * getNextAnimation();
};

#endif /* defined(__DJBooth__AnimationPool__) */

//
//  UpAndDown.h
//  DJBooth
//
//  Created by Andrew Hughes on 4/26/15.
//  Copyright (c) 2015 Andrew Hughes. All rights reserved.
//

#ifndef __DJBooth__UpAndDown__
#define __DJBooth__UpAndDown__

class UpAndDown {
public:
    int min;
    int max;
    int current = 0;
    bool goingDown = false;
    bool hasLooped = false;
    UpAndDown(int min, int max);
    int getNext();
private:
    bool isFirstNext = true;
};

#endif /* defined(__DJBooth__UpAndDown__) */

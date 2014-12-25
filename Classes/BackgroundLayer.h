//
//  BackgroundLayer.h
//  MyGame
//
//  Created by Barbayar Dashzeveg on 2014/12/22.
//
//

#ifndef __MyGame__BackgroundLayer__
#define __MyGame__BackgroundLayer__

#include "cocos2d.h"

class BackgroundLayer : public cocos2d::Scene
{
public:
    virtual bool init();
    CREATE_FUNC(BackgroundLayer);
};

#endif /* defined(__MyGame__BackgroundLayer__) */

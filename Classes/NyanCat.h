//
//  NyanCat.h
//  MyGame
//
//  Created by Barbayar Dashzeveg on 2014/12/25.
//
//

#ifndef __MyGame__NyanCat__
#define __MyGame__NyanCat__

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class NyanCat : public Sprite
{
public:
    bool init();
    CREATE_FUNC(NyanCat);
    void increaseCoin();
private:
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    void onTouchCancelled(Touch* touch, Event* event);
    float currentSpeed;
    void update(float delta);
    void showScore();
    unsigned int coinCount;
    float touchBeganRotation;
};

#endif /* defined(__MyGame__NyanCat__) */

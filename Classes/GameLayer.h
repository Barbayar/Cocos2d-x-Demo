//
//  GameLayer.h
//  MyGame
//
//  Created by Barbayar Dashzeveg on 2014/12/22.
//
//

#ifndef __MyGame__GameLayer__
#define __MyGame__GameLayer__

#include "cocos2d.h"
#include "NyanCat.h"
#include "CoinSprite.h"

USING_NS_CC;
using namespace std;

class GameLayer : public Scene
{
public:
    virtual bool init();
    CREATE_FUNC(GameLayer);
private:
    void createCoins(unsigned int count);
    void update(float delta);
    Vector<CoinSprite *> coins;
    Vector<NyanCat *> cats;
    float touchBeganRotation;
};

#endif /* defined(__MyGame__GameLayer__) */

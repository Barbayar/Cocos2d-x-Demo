//
//  CoinSprite.h
//  MyGame
//
//  Created by Barbayar Dashzeveg on 2014/12/25.
//
//

#ifndef __MyGame__CoinSprite__
#define __MyGame__CoinSprite__

#include "cocos2d.h"
#include "NyanCat.h"

USING_NS_CC;
using namespace std;

class CoinSprite : public Sprite
{
public:
    bool init();
    CREATE_FUNC(CoinSprite);
    void ateBy(NyanCat *cat);
private:
};

#endif /* defined(__MyGame__CoinSprite__) */

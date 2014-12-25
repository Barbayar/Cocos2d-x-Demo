//
//  CoinSprite.cpp
//  MyGame
//
//  Created by Barbayar Dashzeveg on 2014/12/25.
//
//

#include "CoinSprite.h"
#include "SimpleAudioEngine.h"

bool CoinSprite::init() {
    if (!this->initWithFile("coin_0.png")) {
        return false;
    }

    char fileName[100] = {0};
    Vector<SpriteFrame *> coinFrames(10);

    for (unsigned int j = 0; j < 10; j++) {
        sprintf(fileName, "coin_%d.png", j);
        auto frame = SpriteFrame::create(fileName, Rect(0, 0, 44, 40));
        coinFrames.pushBack(frame);
    }

    auto animation = Animation::createWithSpriteFrames(coinFrames, 0.1f);
    auto animate = Animate::create(animation);
    this->runAction(RepeatForever::create(animate));

    return true;
}

void CoinSprite::ateBy(NyanCat *cat) {
    auto scaleBy = ScaleBy::create(0.5, 3.0);
    auto fadeOut = FadeOut::create(0.5);
    auto coinHideSequence = Sequence::create(fadeOut, CallFunc::create([this](){
        this->removeFromParent();
    }), NULL);

    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("coin.wav");
    this->runAction(Spawn::create(scaleBy, coinHideSequence, NULL));
    cat->increaseCoin();
}
//
//  GameLayer.cpp
//  MyGame
//
//  Created by Barbayar Dashzeveg on 2014/12/22.
//
//

#include "GameLayer.h"

bool GameLayer::init() {
    srand(time(NULL));

    Size visibleSize = Director::getInstance()->getVisibleSize();

    for (unsigned int i = 0; i < 4; i++) {
        cats.pushBack(NyanCat::create());
        cats.at(i)->setPosition(Vec2(rand() % (int)visibleSize.width, rand() % (int)visibleSize.height));
        this->addChild(cats.at(i));
    }

    this->schedule(schedule_selector(GameLayer::update));

    return true;
}

void GameLayer::createCoins(unsigned int count) {
    Size visibleSize = Director::getInstance()->getVisibleSize();

    for (unsigned int i = 0; i < count; i++) {
        coins.pushBack(CoinSprite::create());
        coins.at(i)->setPosition(Vec2(rand() % (int)visibleSize.width, rand() % (int)visibleSize.height));
        this->addChild(coins.at(i));
    }
}

void GameLayer::update(float delta) {
    for (auto cat = cats.begin(); cat < cats.end(); ++cat) {
        for (auto coin = coins.begin(); coin < coins.end(); ++coin) {
            if ((*cat)->getBoundingBox().intersectsRect((*coin)->getBoundingBox())) {
                (*coin)->ateBy(*cat);

                coins.erase(coins.find(*coin));
            }
        }
    }

    if (coins.size() == 0) {
        this->createCoins(100);
    }
}

//
//  BackgroundLayer.cpp
//  MyGame
//
//  Created by Barbayar Dashzeveg on 2014/12/22.
//
//

USING_NS_CC;

#include "BackgroundLayer.h"

bool BackgroundLayer::init() {
    auto backgroundImage = Sprite::create("background.jpg");
    Size visibleSize = Director::getInstance()->getVisibleSize();

    backgroundImage->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height / 2.0));
    this->addChild(backgroundImage);

    return true;
}
//
//  MainScene.cpp
//  MyGame
//
//  Created by Barbayar Dashzeveg on 2014/12/22.
//
//

USING_NS_CC;

#include "MainScene.h"
#include "BackgroundLayer.h"
#include "GameLayer.h"

bool MainScene::init() {
    auto backgroundLayer = BackgroundLayer::create();
    auto gameLayer = GameLayer::create();
    
    this->addChild(backgroundLayer);
    this->addChild(gameLayer);
    
    return true;
}

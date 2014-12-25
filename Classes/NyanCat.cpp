//
//  NyanCat.cpp
//  MyGame
//
//  Created by Barbayar Dashzeveg on 2014/12/25.
//
//

#include "NyanCat.h"

bool NyanCat::init() {
    if (!this->initWithFile("nyan.png")) {
        return false;
    }

    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(NyanCat::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(NyanCat::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(NyanCat::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(NyanCat::onTouchCancelled, this);

    auto dispatcher = this->getEventDispatcher();
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    coinCount = 0;
    currentSpeed = 0.0;
    
    this->schedule(schedule_selector(NyanCat::update));
    
    return true;
}

void NyanCat::update(float delta) {
    if (currentSpeed < 0.0) {
        return;
    }

    //currentSpeed -= delta * 100.0;
    float degree = -this->getRotation() * MATH_PIOVER2 / 90.0;

    this->setPosition(Vec2(this->getPosition().x + currentSpeed * cos(degree), this->getPosition().y + currentSpeed * sin(degree)));

    Size visibleSize = Director::getInstance()->getVisibleSize();

    if (this->getPositionY() < 0.0) {
        this->setPositionY(-this->getPositionY());
        this->setRotation(-this->getRotation());
    }

    if (this->getPositionY() > visibleSize.height) {
        this->setPositionY(2 * visibleSize.height - this->getPositionY());
        this->setRotation(-this->getRotation());
    }

    if (this->getPositionX() < 0.0) {
        this->setPositionX(-this->getPositionX());
        this->setRotation(-this->getRotation() - 180);
    }

    if (this->getPositionX() > visibleSize.width) {
        this->setPositionX(2 * visibleSize.width - this->getPositionX());
        this->setRotation(-this->getRotation() - 180);
    }
}

bool NyanCat::onTouchBegan(Touch* touch, Event *event) {
    if (this->getBoundingBox().containsPoint(touch->getLocation())) {
        float degree = atan2((this->getPosition().x - touch->getLocation().x), (this->getPosition().y - touch->getLocation().y)) * 90.0 / MATH_PIOVER2;
        touchBeganRotation = this->getRotation() - degree;

        return true;
    }
    
    return false;
}

void NyanCat::onTouchMoved(Touch* touch, Event *event) {
    float degree = atan2((this->getPosition().x - touch->getLocation().x), (this->getPosition().y - touch->getLocation().y)) * 90.0 / MATH_PIOVER2;
    
    this->setRotation(touchBeganRotation + degree);
}

void NyanCat::onTouchEnded(Touch* touch, Event *event) {
    currentSpeed = 30.0;
    
    return;
}

void NyanCat::onTouchCancelled(Touch* touch, Event *event) {
    CCLOG("onTouchesCancelled");
}

void NyanCat::increaseCoin() {
    coinCount++;
    this->showScore();
    //this->setScale(this->getScale() + 0.03);
}

void NyanCat::showScore() {
    char coinCountStr[15];
    sprintf(coinCountStr, "%d", coinCount);

    auto coinCountLabel = Label::createWithTTF(coinCountStr, "fonts/Marker Felt.ttf", 24);
    coinCountLabel->setColor(Color3B(255, 0, 0));
    coinCountLabel->setPosition(this->getPosition().x, this->getPosition().y);
    this->getParent()->addChild(coinCountLabel);

    auto scaleBy = ScaleBy::create(0.5, 3.0);
    auto fadeOut = FadeOut::create(0.5);
    auto labelHideSequence = Sequence::create(fadeOut, CallFunc::create([coinCountLabel](){
        coinCountLabel->removeFromParent();
    }), NULL);

    coinCountLabel->runAction(Spawn::create(scaleBy, labelHideSequence, NULL));
}

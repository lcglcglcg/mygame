
#include "MyJoystick.h"

bool HRocker::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    isActive = false;
    radius = 100;
    centerPoint = Point(150, 150);
    currentPoint = centerPoint;
    
    jsSprite = Sprite::create("joystick/joystick_fg.png");
    jsSprite->setPosition(centerPoint);
    this->addChild(jsSprite, 1);
    
    auto aJsBg = Sprite::create("joystick/joystick_bg.png");
    aJsBg->setPosition(centerPoint);
    aJsBg->setTag(100);
    addChild(aJsBg);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(HRocker::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(HRocker::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(HRocker::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    Active();
    
    return true;
}

void HRocker::updatePos(float dt)
{
    jsSprite->setPosition(jsSprite->getPosition() + ((currentPoint - jsSprite->getPosition()) * 0.5));
}

void HRocker::Active()
{
    if (!isActive) {
        isActive = true;
        schedule(schedule_selector(HRocker::updatePos));
    }
}

void HRocker::Inactive()
{
    if (isActive) {
        isActive = false;
        this->unschedule(schedule_selector(HRocker::updatePos));
    }
}

Point HRocker::getDirection()
{
    return ccpNormalize(currentPoint - centerPoint);
}

bool HRocker::onTouchBegan(Touch *touch, Event *unused_event)
{
    if (!isActive) {
        return false;
    }
    
    this->setVisible(true);
    auto touchLocation = touch->getLocation();
    touchLocation = this->convertToNodeSpace(touchLocation);
    
    if (ccpDistance(touchLocation, centerPoint) > radius) {
        return false;
    }
    
    currentPoint = touchLocation;
    return true;
}

void HRocker::onTouchMoved(Touch *touch, Event *unused_event)
{
    auto touchLocation = touch->getLocation();
    touchLocation = this->convertToNodeSpace(touchLocation);
    if (ccpDistance(touchLocation, centerPoint) > radius) {
        currentPoint = centerPoint + ccpMult(ccpNormalize(ccpSub(touchLocation, centerPoint)), radius);
        
    } else {
        currentPoint = touchLocation;
    }
}

void HRocker::onTouchEnded(Touch *touch, Event *unused_event)
{
    currentPoint = centerPoint;
    
}








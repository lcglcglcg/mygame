
#ifndef HRocker_H
#define HRocker_H

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class HRocker :public Layer {
    
public:
    virtual bool init();
    CREATE_FUNC(HRocker);
    
    void Active();
    void Inactive();

    Point centerPoint;
    Point currentPoint;
    bool isActive;
    float radius;
    Sprite  *jsSprite;

    Point getDirection();
    void updatePos(float dt);
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
};

#endif 








#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocostudio/CocoStudio.h"

#include "MyMap.h"
#include "MyHero.h"
#include "MyJoystick.h"
#include "MyNetwork.h"

USING_NS_CC;
USING_NS_CC_EXT;

class MyGame : public Layer
{
    
public:
    virtual bool init();
    CREATE_FUNC(MyGame);
    static Scene *createScene();
    
    MyMap *_map;
    MyHero *_hero;
    HRocker *_joystick;
    Vector <MyHero *> _hero_list;
    MyNetwork _net;
    
    void netwrok(float dt);
    void update(float dt);
    void joystick_buttion_attack_Event(Ref *ref, Control::EventType env);
    void joystick_buttion_skill_Event(Ref *ref, Control::EventType env);
    void joystick_hero_select_Event(Ref *ref, Control::EventType env);
    
};

#endif // __HELLOWORLD_SCENE_H__






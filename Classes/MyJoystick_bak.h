//
//  MyJoystick.hpp
//  lcglcg
//
//  Created by 李春光 on 16/3/10.
//
//

#ifndef MyJoystick_hpp
#define MyJoystick_hpp

#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocostudio;


class MyJoystick : public Sprite
{
    
public:
    virtual bool init();
    CREATE_FUNC(MyJoystick);
    
    ControlButton *joystick_buttion_up;
    ControlButton *joystick_buttion_down;
    ControlButton *joystick_buttion_left;
    ControlButton *joystick_buttion_right;
    ControlButton *joystick_buttion_attack;
    ControlButton *joystick_buttion_attack2;
    ControlButton *joystick_buttion_skill;
    
    void joystick_Event_s(Ref *ref, Control::EventType env);
    void joystick_Event_e(Ref *ref, Control::EventType env);
    
    Armature *_frame;
    int status = 0;
};


#endif /* MyJoystick_hpp */

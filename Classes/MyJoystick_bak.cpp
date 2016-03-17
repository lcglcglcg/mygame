//
//  MyJoystick.cpp
//  lcglcg
//
//  Created by 李春光 on 16/3/10.
//
//

#include "MyJoystick2.h"

bool MyJoystick::init()
{
    
    joystick_buttion_up = ControlButton::create(cocos2d::ui::Scale9Sprite::create("joystick/joystick_up.png"));
    joystick_buttion_down = ControlButton::create(cocos2d::ui::Scale9Sprite::create("joystick/joystick_down.png"));
    joystick_buttion_left = ControlButton::create(cocos2d::ui::Scale9Sprite::create("joystick/joystick_left.png"));
    joystick_buttion_right = ControlButton::create(cocos2d::ui::Scale9Sprite::create("joystick/joystick_right.png"));
    joystick_buttion_attack = ControlButton::create(cocos2d::ui::Scale9Sprite::create("joystick/joystick_buttion.png"));
    joystick_buttion_attack2 = ControlButton::create(cocos2d::ui::Scale9Sprite::create("joystick/joystick_buttion.png"));
    joystick_buttion_skill = ControlButton::create(cocos2d::ui::Scale9Sprite::create("joystick/joystick_buttion.png"));
    
    joystick_buttion_up->setPosition(150, 250);
    joystick_buttion_down->setPosition(150, 50);
    joystick_buttion_left->setPosition(50, 150);
    joystick_buttion_right->setPosition(250, 150);
    
    joystick_buttion_attack->setPosition(810, 50);
    joystick_buttion_attack2->setPosition(910, 50);
    joystick_buttion_skill->setPosition(910, 150);
    
    addChild(joystick_buttion_down);
    addChild(joystick_buttion_up);
    addChild(joystick_buttion_left);
    addChild(joystick_buttion_right);
    addChild(joystick_buttion_attack);
    addChild(joystick_buttion_attack2);
    addChild(joystick_buttion_skill);
    
    // up
    joystick_buttion_up->addTargetWithActionForControlEvents(this,
                                                             cccontrol_selector(MyJoystick::joystick_Event_s),
                                                             Control::EventType::TOUCH_DOWN);
    joystick_buttion_up->addTargetWithActionForControlEvents(this,
                                                             cccontrol_selector(MyJoystick::joystick_Event_e),
                                                             Control::EventType::TOUCH_UP_INSIDE);
    joystick_buttion_up->addTargetWithActionForControlEvents(this,
                                                             cccontrol_selector(MyJoystick::joystick_Event_e),
                                                             Control::EventType::TOUCH_UP_OUTSIDE);
    
    // down
    joystick_buttion_down->addTargetWithActionForControlEvents(this,
                                                               cccontrol_selector(MyJoystick::joystick_Event_s),
                                                               Control::EventType::TOUCH_DOWN);
    joystick_buttion_down->addTargetWithActionForControlEvents(this,
                                                               cccontrol_selector(MyJoystick::joystick_Event_e),
                                                               Control::EventType::TOUCH_UP_INSIDE);
    joystick_buttion_down->addTargetWithActionForControlEvents(this,
                                                               cccontrol_selector(MyJoystick::joystick_Event_e),
                                                               Control::EventType::TOUCH_UP_OUTSIDE);
    // left
    joystick_buttion_left->addTargetWithActionForControlEvents(this,
                                                               cccontrol_selector(MyJoystick::joystick_Event_s),
                                                               Control::EventType::TOUCH_DOWN);
    joystick_buttion_left->addTargetWithActionForControlEvents(this,
                                                               cccontrol_selector(MyJoystick::joystick_Event_e),
                                                               Control::EventType::TOUCH_UP_INSIDE);
    joystick_buttion_left->addTargetWithActionForControlEvents(this,
                                                               cccontrol_selector(MyJoystick::joystick_Event_e),
                                                               Control::EventType::TOUCH_UP_OUTSIDE);
    
    // right
    joystick_buttion_right->addTargetWithActionForControlEvents(this,
                                                                cccontrol_selector(MyJoystick::joystick_Event_s),
                                                                Control::EventType::TOUCH_DOWN);
    joystick_buttion_right->addTargetWithActionForControlEvents(this,
                                                                cccontrol_selector(MyJoystick::joystick_Event_e),
                                                                Control::EventType::TOUCH_UP_INSIDE);
    joystick_buttion_right->addTargetWithActionForControlEvents(this,
                                                                cccontrol_selector(MyJoystick::joystick_Event_e),
                                                                Control::EventType::TOUCH_UP_OUTSIDE);
    // attack
    joystick_buttion_attack->addTargetWithActionForControlEvents(this,
                                                                 cccontrol_selector(MyJoystick::joystick_Event_s),
                                                                 Control::EventType::TOUCH_DOWN);
    joystick_buttion_attack->addTargetWithActionForControlEvents(this,
                                                                 cccontrol_selector(MyJoystick::joystick_Event_e),
                                                                 Control::EventType::TOUCH_UP_INSIDE);
    joystick_buttion_attack->addTargetWithActionForControlEvents(this,
                                                                 cccontrol_selector(MyJoystick::joystick_Event_e),
                                                                 Control::EventType::TOUCH_UP_OUTSIDE);
    
    // attack2
    joystick_buttion_attack2->addTargetWithActionForControlEvents(this,
                                                                  cccontrol_selector(MyJoystick::joystick_Event_s),
                                                                  Control::EventType::TOUCH_DOWN);
    joystick_buttion_attack2->addTargetWithActionForControlEvents(this,
                                                                  cccontrol_selector(MyJoystick::joystick_Event_e),
                                                                  Control::EventType::TOUCH_UP_INSIDE);
    joystick_buttion_attack2->addTargetWithActionForControlEvents(this,
                                                                  cccontrol_selector(MyJoystick::joystick_Event_e),
                                                                  Control::EventType::TOUCH_UP_OUTSIDE);
    
    // skill
    joystick_buttion_skill->addTargetWithActionForControlEvents(this,
                                                                cccontrol_selector(MyJoystick::joystick_Event_s),
                                                                Control::EventType::TOUCH_DOWN);
    joystick_buttion_skill->addTargetWithActionForControlEvents(this,
                                                                cccontrol_selector(MyJoystick::joystick_Event_e),
                                                                Control::EventType::TOUCH_UP_INSIDE);
    joystick_buttion_skill->addTargetWithActionForControlEvents(this,
                                                                cccontrol_selector(MyJoystick::joystick_Event_e),
                                                                Control::EventType::TOUCH_UP_OUTSIDE);
    
    return true;
}

void MyJoystick::joystick_Event_s(Ref *ref, Control::EventType env)
{
    
    if (ref == joystick_buttion_up) {
        
        _frame->getAnimation()->playWithIndex(1);
        status = 1;
        
    } else if (ref == joystick_buttion_down) {
        
        _frame->getAnimation()->playWithIndex(1);
        status = 2;
        
    } else if (ref == joystick_buttion_left) {
        
        _frame->getAnimation()->playWithIndex(1);
        status = 3;
        
    } else if (ref == joystick_buttion_right) {
        
        _frame->getAnimation()->playWithIndex(1);
        status = 4;
        
    } else if (ref == joystick_buttion_attack) {
        
        _frame->getAnimation()->playWithIndex(17, -1, -1);
        status = 5;
        
    } else if (ref == joystick_buttion_attack2) {
        
        _frame->getAnimation()->playWithIndex(4, -1, -1);
        status = 6;
        
    } else if (ref == joystick_buttion_skill) {
        
        _frame->getAnimation()->playWithIndex(3, -1, -1);
        status = 7;
    }
}

void MyJoystick::joystick_Event_e(Ref *ref, Control::EventType env)
{
    
    
    if (ref == joystick_buttion_attack) {
        
    } else if (ref == joystick_buttion_attack2) {
        
    } else if (ref == joystick_buttion_skill) {
        
    } else {
        
        _frame->getAnimation()->playWithIndex(0);
        status = 0;
    }
}






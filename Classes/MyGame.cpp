
#include "MyGame.h"

Scene* MyGame::createScene()
{
    auto scene = Scene::create();
    auto layer = MyGame::create();
    scene->addChild(layer);
    return scene;
}

bool MyGame::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    _map = MyMap::create();
    _map->select(1);
    addChild(_map);
    
    _hero = MyHero::create();
    _hero->select(0);
    addChild(_hero);
    
//    for (int i = 0; i < 5; i++) {
//        
//        MyHero *node = MyHero::create();
//        node->select(i % 3);
//        addChild(node);
//        _hero_list.pushBack(node);
//        
//        printf("[1]%p\n", node);
//    }
//    
//    Vector<MyHero *>::iterator iter;
//    for (iter=_hero_list.begin(); iter != _hero_list.end(); iter++) {
//        
//        
//        MyHero *node = *iter;
//        printf("[2]%p\n", node);
//        node->removeFromParentAndCleanup(true);
//    }
    
    _joystick = HRocker::create();
    addChild(_joystick);
    
    ControlButton *joystick_buttion_attack = ControlButton::create(cocos2d::ui::Scale9Sprite::create("joystick/joystick_fg.png"));
    joystick_buttion_attack->setPosition(800, 100);
    addChild(joystick_buttion_attack);
    joystick_buttion_attack->addTargetWithActionForControlEvents(this,
                                                                 cccontrol_selector(MyGame::joystick_buttion_attack_Event),
                                                                 Control::EventType::TOUCH_DOWN);
    
    ControlButton *joystick_buttion_skill = ControlButton::create(cocos2d::ui::Scale9Sprite::create("joystick/joystick_fg.png"));
    joystick_buttion_skill->setPosition(900, 100);
    addChild(joystick_buttion_skill);
    joystick_buttion_skill->addTargetWithActionForControlEvents(this,
                                                                cccontrol_selector(MyGame::joystick_buttion_skill_Event),
                                                                Control::EventType::TOUCH_DOWN);
    
    ControlButton *joystick_hero_select = ControlButton::create(cocos2d::ui::Scale9Sprite::create("joystick/joystick_fg.png"));
    joystick_hero_select->setPosition(900, 200);
    addChild(joystick_hero_select);
    joystick_hero_select->addTargetWithActionForControlEvents(this,
                                                              cccontrol_selector(MyGame::joystick_hero_select_Event),
                                                              Control::EventType::TOUCH_DOWN);
    
    scheduleUpdate();
    schedule(schedule_selector(MyGame::netwrok), 0.5);
    return true;
}

void MyGame::netwrok(float dt)
{
    // _network.post_send(_hero->name, _hero->hero_index, _hero->x, _hero->y, _hero->_frame_status, _map->x, _map->y);
}

void MyGame::joystick_buttion_attack_Event(Ref *ref, Control::EventType env)
{
    _hero->attack();
}

void MyGame::joystick_buttion_skill_Event(Ref *ref, Control::EventType env)
{
    _hero->skill();
}

void MyGame::joystick_hero_select_Event(Ref *ref, Control::EventType env)
{
    static int index = 1;
    _hero->select(index++);
    _hero->_idle(0);
    if (index == 3) index = 0;
}

void MyGame::update(float dt)
{
    
    Point poi = _joystick->getDirection();
    if ((poi.x  >  0) && (poi.x - poi.y) >0 && (poi.x + poi.y) > 0) {
        
        if (_hero->walk_right() == true) {
            
            _map->right();
        }
    }
    else if ((poi.x < 0) && (poi.x + poi.y) < 0 && (poi.x - poi.y) < 0) {
        
        if (_hero->walk_left() == true) {
            
            _map->left();
        }
    }
    else if ((poi.y > 0) && (poi.y - poi.x) > 0 && (poi.y + poi.x) >0) {
        
        // _hero->walk_up();
        
    }
    else if ((poi.y < 0) && (poi.y - poi.x) < 0 && (poi.y + poi.x) < 0) {
        
        // _hero->walk_down();
        
    } else {
        
        _hero->idle();
    }
}







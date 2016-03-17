//
//  hero.cpp
//  lcglcg
//
//  Created by 李春光 on 16/2/23.
//

#include "MyHero.h"

bool MyHero::init()
{
    
    Sprite::init();
    setPosition(150, 150);
    
    //    std::vector <int> arr;
    //    for (int i = 0; i <= 3; i++)
    //        arr.push_back(i);
    //    _frame->getAnimation()->playWithIndexes(arr);
    // schedule(schedule_selector(MyHero::sleep), 5);
    
    return true;
}

void MyHero::frame_init(const char *frame_json_path, const char *name)
{
    
    if (_frame) {
        
        _frame->removeFromParentAndCleanup(true);
    }
    
    cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(frame_json_path);
    _frame = cocostudio::Armature::create(name);
    addChild(_frame);
}

void MyHero::select(int index)
{
    
    if (index == 0) {
        
        frame_init("hero/minren1.ExportJson", "minren1");
        hero_index = index;
        attack_time = 0.4;
        skill_time = 2.0;
        
    } else if (index == 1) {
        
        frame_init("hero/NewProject.ExportJson", "NewProject");
        hero_index = index;
        attack_time = 0.4;
        skill_time = 1.8;
        
    } else if (index == 2) {
        
        frame_init("hero/xiaoyin.ExportJson", "xiaoyin");
        hero_index = index;
        attack_time = 0.4;
        skill_time = 1.4;
    }
}

void MyHero::sleep(float dt)
{
    
    _frame->getAnimation()->playWithIndex(index);
    printf("index=%d\n", index++);
}

int MyHero::walk_up()
{
    
    if (_frame_status == 0) {
        
        _frame_status = 1;
        _frame->getAnimation()->playWithIndex(_frame_status);
    }
    
    if (_frame_status == 1) {
        
        y = getPositionY();
        if (y < 230) {
            
            setPosition(getPositionX(), y + 8);
            return false;
        }
        
        return true;
    }
    
    return false;
}

int MyHero::walk_down()
{
    
    if (_frame_status == 0) {
        
        _frame_status = 1;
        _frame->getAnimation()->playWithIndex(_frame_status);
    }
    
    if (_frame_status == 1) {
        y = getPositionY();
        if (y > 30) {
            
            setPosition(getPositionX(), y - 8);
            return false;
        }
        
        return true;
    }
    
    return false;
}

int MyHero::walk_left()
{
    
    if (_frame_status == 0) {
        
        _frame_status = 1;
        _frame->getAnimation()->playWithIndex(_frame_status);
    }
    
    if (_frame_status == 1) {
        
        _frame->setScaleX(-1);
        x = getPositionX();
        if (x > 100) {
            
            setPosition(x - 8, getPositionY());
            return false;
            
        }
        return true;
    }
    
    return false;
}

int MyHero::walk_right()
{
    
    if (_frame_status == 0) {
        
        _frame_status = 1;
        _frame->getAnimation()->playWithIndex(_frame_status);
    }
    
    if (_frame_status == 1) {
        
        _frame->setScaleX(1);
        x = getPositionX();
        if (x < 850) {
            
            setPosition(x + 8, getPositionY());
            return false;
        }
        
        return true;
    }
    
    return false;
    
}

void MyHero::_idle(float dt)
{
    _frame_status = 0;
    _frame->getAnimation()->playWithIndex(_frame_status);
}

void MyHero::idle()
{
    
    if (_frame_status == 1) {
        
        _frame_status = 0;
        _frame->getAnimation()->playWithIndex(_frame_status);
    }
}

void MyHero::attack()
{
    
    if (_frame_status != 3) {
        
        _frame_status = 3;
        _frame->getAnimation()->playWithIndex(_frame_status);
        scheduleOnce(schedule_selector(MyHero::_idle), attack_time);
    }
}

void MyHero::skill()
{
    
    if (_frame_status != 3) {
        
        _frame_status = 3;
        _frame->getAnimation()->playWithIndex(_frame_status);
        scheduleOnce(schedule_selector(MyHero::_idle), skill_time);
    }
}















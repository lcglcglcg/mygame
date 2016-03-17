//
//  hero.hpp
//  lcglcg
//
//  Created by 李春光 on 16/2/23.
//
//

#ifndef hero_hpp
#define hero_hpp

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace cocostudio;

class MyHero : public Sprite
{
    
public:
    virtual bool init();
    CREATE_FUNC(MyHero);
    
    const char *name = "abc";
    
    int x, y;
    int hero_index = 0; //0鸣人 1佐助 2小樱
    void select(int index);
    
    
    
    // frame
    Armature *_frame_my;
    Armature *_frame_zz;
    Armature *_frame_xy;
    Armature *_frame;
    int _frame_status = 0;
    void frame_init(const char *frame_json_path, const char *name);
    
    
    // 空闲
    void idle();
    void _idle(float dt);
    
    // 行走
    int walk_up();
    int walk_down();
    int walk_left();
    int walk_right();
    
    // 攻击
    float attack_time = 0;
    void attack();
    
    // 必杀技
    float skill_time = 0;
    void skill();
    
    void sleep(float dt);
    int index = 0;
    
    //    Action *frame_idle;     //闲置
    //    Action *frame_walk;     //行走
    //    Action *frame_attack;   //攻击
    //    Action *frame_hurt;     //受伤
    //    Action *frame_knockout; //死亡
    
    
};

#endif /* hero_hpp */







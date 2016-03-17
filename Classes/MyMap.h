//
//  MyMap.hpp
//  lcglcg
//
//  Created by 李春光 on 16/3/6.
//
//

#ifndef MyMap_hpp
#define MyMap_hpp

#include "cocos2d.h"

USING_NS_CC;

class MyMap : public TMXTiledMap
{
    
public:
    virtual bool init();
    CREATE_FUNC(MyMap);
    
    int x, y;
    void select(int index);
    
    void left();
    void right();
    
};

#endif /* MyMap_hpp */

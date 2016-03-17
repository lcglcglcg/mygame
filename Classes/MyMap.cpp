//
//  MyMap.cpp
//  lcglcg
//
//  Created by 李春光 on 16/3/6.
//
//

#include "MyMap.h"

USING_NS_CC;


bool MyMap::init()
{
    
    TMXTiledMap::initWithTMXFile("map/town_1_3.tmx");
    TMXTiledMap::initWithTMXFile("map/town_1_2.tmx");
    TMXTiledMap::initWithTMXFile("map/town_1_1.tmx");
    return true;
}

void MyMap::select(int index)
{
    
}

void MyMap::left()
{
    x = getPositionX();
    if (x < 0)
    {
        setPositionX(x + 8);
        
    }
}

void MyMap::right()
{
    x = getPositionX();
    if (x > -1300)
    {
        setPositionX(x - 8);
    }
}







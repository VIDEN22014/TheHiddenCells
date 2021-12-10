#pragma once


#ifndef __LEVEL_3_SCENE_H__
#define __LEVEL_3_SCENE_H__

#include "cocos2d.h"

class Level3Scene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(Level3Scene);
    void update(float dt);
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void checkTouch(float touchX, float touchY);
};

#endif // __LEVEL_SELECT_SCENE_H__


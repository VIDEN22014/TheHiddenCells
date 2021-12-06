#pragma once

#ifndef __ENDGAMESCENE_H__
#define __ENDGAMESCEN_H__

#include "cocos2d.h"
#include <proj.win32/GameData.h>
class EndGameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(EndGameScene);
   // void update(float dt);

   // bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

};


#endif // __ENDGAMESCEN_H__
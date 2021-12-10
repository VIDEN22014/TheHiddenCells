
#pragma once


#ifndef _INFO_SCENE2_
#define _INFO_SCENE2_

#include "cocos2d.h"
#include <string>
class InfoScene2 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(InfoScene2);
    void update(float dt);
    void CreateInfo(char* path, char* InfoText);
};

#endif // __LEVEL_SELECT_SCENE_H__


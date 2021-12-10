#pragma once


#ifndef _INFO_SCENE_
#define _INFO_SCENE_

#include "cocos2d.h"
#include <string>
class InfoScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(InfoScene);
    void update(float dt);
    void CreateInfo(std::string path, char* InfoText,bool isVisible);
};

#endif // __LEVEL_SELECT_SCENE_H__


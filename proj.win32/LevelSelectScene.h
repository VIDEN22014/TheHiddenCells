#ifndef __LEVEL_SELECT_SCENE_H__
#define __LEVEL_SELECT_SCENE_H__

#include "cocos2d.h"

class LevelSelectScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(LevelSelectScene);
    void update(float dt);
};

#endif // __LEVEL_SELECT_SCENE_H__


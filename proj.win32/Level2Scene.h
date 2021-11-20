#ifndef __LEVEL_2_SCENE_H__
#define __LEVEL_2_SCENE_H__

#include "cocos2d.h"

class Level2Scene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(Level2Scene);
    void update(float dt);
};

#endif // __LEVEL_SELECT_SCENE_H__


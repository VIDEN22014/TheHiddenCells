#ifndef __LEVEL_1_SCENE_H__
#define __LEVEL_1_SCENE_H__

#include "cocos2d.h"

class Level1Scene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(Level1Scene);
    void update(float dt);
};

#endif // __LEVEL_SELECT_SCENE_H__


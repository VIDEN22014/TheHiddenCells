#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    cocos2d::Sprite* spriteRiver;
    cocos2d::Size size;
    virtual bool init();
    virtual void update(float dt);
    CREATE_FUNC(GameScene);
};

#endif // __GAME_SCENE_H__


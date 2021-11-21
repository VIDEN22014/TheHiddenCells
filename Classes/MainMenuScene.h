#ifndef __MAINMENU_SCENE_H__
#define __HMAINMENU_SCENE_H__

#include "cocos2d.h"

class MainMenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    cocos2d::Sprite* spriteStartHero;

    void MainMenuScene::changeTextureHeroes();
    virtual bool init();
    void CreateButtonSound();
    CREATE_FUNC(MainMenuScene);
    void update(float dt);
};

#endif // __HELLOWORLD_SCENE_H__

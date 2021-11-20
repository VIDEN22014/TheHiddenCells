#ifndef __MAINMENU_SCENE_H__
#define __HMAINMENU_SCENE_H__

#include "cocos2d.h"

class MainMenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void GoToGameScene(Ref* pSender);
    void GoToShopScene(Ref* pSender);
    void GoToExit(Ref* pSender);
    void CreateButtonSound();
    CREATE_FUNC(MainMenuScene);
    void update(float dt);
};

#endif // __HELLOWORLD_SCENE_H__

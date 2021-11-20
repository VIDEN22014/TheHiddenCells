#ifndef __SHOP_SCENE_H__
#define __SHOP_SCENE_H__

#include "cocos2d.h"

class ShopScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void GoToGameScene(Ref* pSender);
    void GoToShopScene(Ref* pSender);
    CREATE_FUNC(ShopScene);
};

#endif // __HELLOWORLD_SCENE_H__


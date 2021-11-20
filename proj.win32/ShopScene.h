#ifndef __SHOP_SCENE_H__
#define __SHOP_SCENE_H__

#include "cocos2d.h"

class ShopScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	CREATE_FUNC(ShopScene);
	void update(float dt);
};

#endif // __HELLOWORLD_SCENE_H__


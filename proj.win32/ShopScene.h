#pragma once


#ifndef __SHOP_SCENE_H__
#define __SHOP_SCENE_H__

#include "cocos2d.h"

class ShopScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	cocos2d::Sprite* spriteStartHero;
	cocos2d::Sprite* lineExpAmmo;
	cocos2d::Sprite* lineExpXP;
	
	virtual bool init();
	void changeTextureHeroes(int index,bool ThisHeroBuy);
	void changeTexturelineExp(int index,int sprite);
	void Shoping(int price, int index);
	//void whichHeroBuy();
	CREATE_FUNC(ShopScene);

	//void update(float dt);
};

#endif // __HELLOWORLD_SCENE_H__


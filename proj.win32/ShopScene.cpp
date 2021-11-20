#include "ShopScene.h"

USING_NS_CC;
Scene* ShopSceneObj;


Scene* ShopScene::createScene()
{
	return ShopSceneObj = ShopScene::create();
}

bool ShopScene::init()
{

	if (!Scene::init())
	{
		return false;
	}

	auto sprite = Sprite::create("backmenu.png");
	Size size = Director::getInstance()->getWinSize();
	sprite->setPosition(Vec2(size.width / 2, size.height / 2));
	sprite->setScale(0.5);
	this->addChild(sprite);

	return true;
}

void ShopScene::update(float dt) {};


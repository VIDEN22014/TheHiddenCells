#include <proj.win32/Level2Scene.h>

USING_NS_CC;

Scene* Level2SceneObj;

Scene* Level2Scene::createScene()
{
	return Level2SceneObj = Level2Scene::create();
}

bool Level2Scene::init()
{

	if (!Scene::init())
	{
		return false;
	}

	auto sprite = Sprite::create("backmenu.png");
	Size size = Director::getInstance()->getWinSize();
	sprite->setAnchorPoint(Vec2(0, 0));
	sprite->setPosition(Vec2(0, 0));
	this->addChild(sprite);

	return true;
}

void Level2Scene::update(float dt) {};




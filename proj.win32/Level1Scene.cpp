#include <proj.win32/Level1Scene.h>

USING_NS_CC;

Scene* Level1SceneObj;

Scene* Level1Scene::createScene()
{
	return Level1SceneObj = Level1Scene::create();
}

bool Level1Scene::init()
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

void Level1Scene::update(float dt) {};




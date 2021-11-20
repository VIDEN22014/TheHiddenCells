#include <proj.win32/Level3Scene.h>

USING_NS_CC;

Scene* Level3SceneObj;

Scene* Level3Scene::createScene()
{
	return Level3SceneObj = Level3Scene::create();
}

bool Level3Scene::init()
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

void Level3Scene::update(float dt) {};




#include <proj.win32/LevelSelectScene.h>

USING_NS_CC;

Scene* LevelSelectSceneObj;

Scene* LevelSelectScene::createScene()
{
	return LevelSelectSceneObj = LevelSelectScene::create();
}

bool LevelSelectScene::init()
{

	if (!Scene::init())
	{
		return false;
	}

	auto sprite = Sprite::create("Assets/Backgrounds/BG_4_960.png");
	Size size = Director::getInstance()->getWinSize();
	sprite->setAnchorPoint(Vec2(0, 0));
	sprite->setPosition(Vec2(0, 0));
	this->addChild(sprite);

	return true;
}

void LevelSelectScene::update(float dt) {};




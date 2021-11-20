#include <cocos/ui/UIButton.h>
#include <proj.win32/LevelSelectScene.h>
#include <proj.win32/Game.h>

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
	//Background Sprite
	auto spriteBackground = Sprite::create("Assets/Backgrounds/BG_4_960.png");
	Size size = Director::getInstance()->getWinSize();
	spriteBackground->setAnchorPoint(Vec2(0, 0));
	spriteBackground->setPosition(Vec2(0, 0));
	this->addChild(spriteBackground);

	

	auto level1Button = ui::Button::create("Assets/UI/StoneButtonsLight/tile002.png", "Assets/UI/StoneButtonsLightPressed/tile002.png");
	level1Button->setAnchorPoint(Vec2(0, 0));
	level1Button->setScale(4.5);
	level1Button->setPosition(Vec2(440, 375));

	level1Button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Game::GoToLevelSelect();
			break;
		default:
			break;
		}
		});


	this->addChild(level1Button);






	return true;
}

void LevelSelectScene::update(float dt) {};




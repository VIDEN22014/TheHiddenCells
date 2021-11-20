#include "ui/CocosGUI.h"
#include "ShopScene.h"
#include <proj.win32/Game.h>

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
	//Background Sprite
	auto spriteBackground = Sprite::create("Assets/Backgrounds/BG_4_960.png");
	Size size = Director::getInstance()->getWinSize();
	spriteBackground->setAnchorPoint(Vec2(0, 0));
	spriteBackground->setPosition(Vec2(0, 0));
	this->addChild(spriteBackground);




	//Return Button
	auto returnButton = ui::Button::create("Assets/UI/StoneButtonsLight/tile005.png", "Assets/UI/StoneButtonsLightPressed/tile005.png");
	returnButton->setScale(5);
	returnButton->setAnchorPoint(Vec2(0, 0));
	returnButton->setPosition(Vec2(8 * returnButton->getScale(), 8 * returnButton->getScale()));
	returnButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Game::GoToMainMenu();
			break;
		default:
			break;
		}
		});
	this->addChild(returnButton);



	return true;
}

void ShopScene::update(float dt) {};


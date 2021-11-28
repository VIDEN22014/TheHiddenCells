#include "ui/CocosGUI.h"
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
	auto spriteBackground = Sprite::create("Assets/Backgrounds/BG 4.png");
	Size size = Director::getInstance()->getWinSize();
	spriteBackground->setAnchorPoint(Vec2(0, 0));
	spriteBackground->setPosition(Vec2(0, 0));
	this->addChild(spriteBackground);


	//Level Buttons
	auto level1Button = ui::Button::create("Assets/UI/StoneButtonsLight/tile002.png", "Assets/UI/StoneButtonsLightPressed/tile002.png");
	level1Button->setScale(5);
	level1Button->setPosition(Vec2(size.width / 2.0, size.height / 2.0));
	level1Button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Game::GoToLevel1();
			break;
		default:
			break;
		}
		});
	this->addChild(level1Button);
	auto level1Label = Label::createWithTTF("Level 1", "Fonts/DungeonFont.ttf", level1Button->getContentSize().height * level1Button->getScale());
	level1Label->setAnchorPoint(Vec2(0, 0.5));
	level1Label->setPosition(Vec2(level1Button->getPositionX() + level1Button->getContentSize().width * level1Button->getScale() / 1.75, level1Button->getPositionY()));
	this->addChild(level1Label);


	auto level2Button = ui::Button::create("Assets/UI/StoneButtonsLight/tile002.png", "Assets/UI/StoneButtonsLightPressed/tile002.png");
	level2Button->setScale(level1Button->getScale());
	level2Button->setPosition(Vec2(level1Button->getPositionX(), level1Button->getPositionY() - level1Button->getContentSize().height * level1Button->getScale() * 1.5));
	level2Button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Game::GoToLevel2();
			break;
		default:
			break;
		}
		});
	this->addChild(level2Button);
	auto level2Label = Label::createWithTTF("Level 2", "Fonts/DungeonFont.ttf", level2Button->getContentSize().height * level2Button->getScale());
	level2Label->setAnchorPoint(Vec2(0, 0.5));
	level2Label->setPosition(Vec2(level2Button->getPositionX() + level2Button->getContentSize().width * level2Button->getScale() / 1.75, level2Button->getPositionY()));
	this->addChild(level2Label);


	auto level3Button = ui::Button::create("Assets/UI/StoneButtonsLight/tile002.png", "Assets/UI/StoneButtonsLightPressed/tile002.png");
	level3Button->setScale(level2Button->getScale());
	level3Button->setPosition(Vec2(level2Button->getPositionX(), level2Button->getPositionY() - level2Button->getContentSize().height * level2Button->getScale() * 1.5));
	level3Button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Game::GoToLevel3();
			break;
		default:
			break;
		}
		});
	this->addChild(level3Button);
	auto level3Label = Label::createWithTTF("Level 3", "Fonts/DungeonFont.ttf", level3Button->getContentSize().height * level3Button->getScale());
	level3Label->setAnchorPoint(Vec2(0, 0.5));
	level3Label->setPosition(Vec2(level3Button->getPositionX() + level3Button->getContentSize().width * level3Button->getScale() / 1.75, level3Button->getPositionY()));
	this->addChild(level3Label);

	//Coin Sprite
	auto CoinSprite = Sprite::create("Assets/Icons/Coins_0/coin_01.png");
	CoinSprite->setPosition(Vec2(0 + CoinSprite->getContentSize().width, 960 - CoinSprite->getContentSize().height));//820 900
	this->addChild(CoinSprite);
	auto animation = Animation::create();
	animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_01.png");
	animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_02.png");
	animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_03.png");
	animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_04.png");
	animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_05.png");
	animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_06.png");
	animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_07.png");
	animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_08.png");
	animation->setDelayPerUnit(0.1111111112f);
	animation->setLoops(-1);
	CoinSprite->runAction(Animate::create(animation));
	auto CoinLabel = Label::createWithTTF(std::to_string(gameData::money), "Fonts/DungeonFont.ttf", 42);
	CoinLabel->setAnchorPoint(Vec2(0, 0.5));
	CoinLabel->setPosition(Vec2(CoinSprite->getPositionX() + CoinSprite->getContentSize().width, CoinSprite->getPositionY()));
	this->addChild(CoinLabel);

	//Return Button
	auto returnButton = ui::Button::create("Assets/UI/StoneButtonsLight/tile005.png", "Assets/UI/StoneButtonsLightPressed/tile005.png");
	returnButton->setScale(level1Button->getScale());
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

void LevelSelectScene::update(float dt) {};




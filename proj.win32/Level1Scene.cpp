#include "ui/CocosGUI.h"
#include <proj.win32/Level1Scene.h>
#include <proj.win32/Cards.h>
#include <proj.win32/GameData.h>
#include <proj.win32/Game.h>
#include <proj.win32/GeneratorCard.h>
#include <proj.win32/CardGenerator.h>


USING_NS_CC;

Scene* Level1SceneObj;
Label* Coin1Label;
Card* cards[3][3];

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
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cards[i][j] = GeneratorCard(1, Level1SceneObj).GenerateRandomCard(*(new position(278 + j * 192 + 10, 682 - i * 192 + 10)));
			if (i == 1&&j == 1) {
				cards[i][j] = GeneratorCard(1, Level1SceneObj).GenerateHeroCard(*(new position(480, 480)));
			}
		}
	}
	
	//Background Sprite
	auto spriteBackground = Sprite::create("Assets/Backgrounds/BG 4.png");
	Size size = Director::getInstance()->getWinSize();
	spriteBackground->setAnchorPoint(Vec2(0, 0));
	spriteBackground->setPosition(Vec2(0, 0));
	this->addChild(spriteBackground);

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

	Coin1Label = Label::create(std::to_string(gameData::money), "Fonts/DungeonFont.ttf", 42);
	Coin1Label->setAnchorPoint(Vec2(0, 0.5));
	Coin1Label->setPosition(Vec2(CoinSprite->getPositionX() + CoinSprite->getContentSize().width, CoinSprite->getPositionY()));
	this->addChild(Coin1Label);

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
			Game::GoToLevelSelect();
			break;
		default:
			break;
		}
		});
	this->addChild(returnButton);


	return true;
}

void Level1Scene::update(float dt) {};




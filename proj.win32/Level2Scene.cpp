#include "ui/CocosGUI.h"
#include <proj.win32/Level2Scene.h>
#include <proj.win32/Cards.h>
#include <proj.win32/GameData.h>
#include <proj.win32/Game.h>
#include <proj.win32/GeneratorCard.h>



USING_NS_CC;

Scene* Level2SceneObj;
Label* Coin1Label;
Sprite* touchSprite[3][3];
Card* cards[3][3];
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
	gameData::isHeroArmed = false;
	srand(time(NULL));
	gameData::currentLevel = 2;
	gameData::heroPosition = position(1, 1);
	gameData::isSceneLocked = false;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				cards[i][j] = GeneratorCard(1, this).GenerateHeroCard(*(new position(i, j)));
			}
			else if (i == 1 && j == 2) { cards[i][j] = GeneratorCard(1, this).GenerateHeroWeapon(*(new position(i, j))); }
			else {
				cards[i][j] = GeneratorCard(1, this).GenerateRandomCard(*(new position(i, j)));
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
	auto CoinLabel = Label::createWithTTF(std::to_string(gameData::money), "Fonts/DungeonFont.ttf", 42);
	CoinLabel->setAnchorPoint(Vec2(0, 0.5));
	CoinLabel->setPosition(Vec2(CoinSprite->getPositionX() + CoinSprite->getContentSize().width, CoinSprite->getPositionY()));
	this->addChild(CoinLabel);


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

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			touchSprite[i][j] = Sprite::create("Assets/UI/StoneButtonsLight/tile005.png");
			touchSprite[i][j]->setScale(12);
			touchSprite[i][j]->setPosition(Vec2(278 + j * (touchSprite[i][j]->getContentSize().width * touchSprite[i][j]->getScale() + 10),
				682 - i * (touchSprite[i][j]->getContentSize().width * touchSprite[i][j]->getScale() + 10)));
			touchSprite[i][j]->setVisible(false);
			this->addChild(touchSprite[i][j]);
		}
	}

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Level2Scene::onTouchBegan, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}

void checkTouch(float touchX, float touchY) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (touchX >= touchSprite[i][j]->getPositionX() - 192 / 2.0 && touchX <= touchSprite[i][j]->getPositionX() + 192 / 2.0 && touchY >= touchSprite[i][j]->getPositionY() - 192 / 2.0 && touchY <= touchSprite[i][j]->getPositionY() + 192 / 2.0) {
				Game::Turn(position(i, j), cards, 1);
			}
		}
	}
}

bool Level2Scene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	checkTouch(touch->getLocation().x, touch->getLocation().y);
	return true;
}



void Level2Scene::update(float dt) {};




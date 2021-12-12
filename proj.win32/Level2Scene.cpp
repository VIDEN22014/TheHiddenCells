#include "ui/CocosGUI.h"
#include <proj.win32/Level2Scene.h>
#include <proj.win32/Cards.h>
#include <proj.win32/GameData.h>
#include <proj.win32/Game.h>
#include <proj.win32/GeneratorCard.h>
#include "SimpleAudioEngine.h"


USING_NS_CC;

Scene* Level2SceneObj;
Label* Coin2Label;
Sprite* touch2Sprite[3][3];
Card* cards2[3][3];

Scene* Level2Scene::createScene()
{
	return gameData::currentScene = Level2SceneObj = Level2Scene::create();

}

bool Level2Scene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	gameData::ScaleCard = 0;
	gameData::isHeroArmed = false;
	srand(time(NULL));
	gameData::currentLevel = 2;
	gameData::heroPosition = position(1, 1);
	gameData::isSceneLocked = false;

	if (gameData::playMusic) {
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Sound/3RoadChariot.mp3.mp3", true);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				cards2[i][j] = GeneratorCard(2, this).GenerateHeroCard(*(new position(i, j)));
			}
			else if (i == 1 && j == 2) { cards2[i][j] = GeneratorCard(1, this).GenerateHeroWeapon(*(new position(i, j))); }
			else {
				cards2[i][j] = GeneratorCard(2, this).GenerateRandomCard(*(new position(i, j)));
			}
		}
	}

	//Background Sprite
	auto spriteBackground = Sprite::create("Assets/Backgrounds/2.png");
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

	auto Coin2Label = Label::createWithTTF(std::to_string(gameData::money), "Fonts/DungeonFont.ttf", 42);
	Coin2Label->setAnchorPoint(Vec2(0, 0.5));
	Coin2Label->setPosition(Vec2(CoinSprite->getPositionX() + CoinSprite->getContentSize().width, CoinSprite->getPositionY()));
	this->addChild(Coin2Label);

	gameData::currentMoneyLabel = Coin2Label;

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
			if (gameData::playMusic) {

				CocosDenshion::SimpleAudioEngine::getInstance()->unloadEffect("Sound/2GoldenWin.mp3");
				CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
				CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Sound/backgroundmusic.mp3", true);
			}
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
			touch2Sprite[i][j] = Sprite::create("Assets/UI/StoneButtonsLight/tile005.png");
			touch2Sprite[i][j]->setScale(12);
			touch2Sprite[i][j]->setPosition(Vec2(278 + j * (touch2Sprite[i][j]->getContentSize().width * touch2Sprite[i][j]->getScale() + 10),
				682 - i * (touch2Sprite[i][j]->getContentSize().width * touch2Sprite[i][j]->getScale() + 10)));
			touch2Sprite[i][j]->setVisible(false);
			this->addChild(touch2Sprite[i][j]);
		}
	}

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Level2Scene::onTouchBegan, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}

void Level2Scene::checkTouch(float touchX, float touchY) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (touchX >= touch2Sprite[i][j]->getPositionX() - 192 / 2.0 && touchX <= touch2Sprite[i][j]->getPositionX() + 192 / 2.0 && touchY >= touch2Sprite[i][j]->getPositionY() - 192 / 2.0 && touchY <= touch2Sprite[i][j]->getPositionY() + 192 / 2.0) {
				Game::Turn(position(i, j), cards2, 2);
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




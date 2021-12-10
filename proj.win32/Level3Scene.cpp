#include "ui/CocosGUI.h"
#include "ui/CocosGUI.h"
#include <proj.win32/Level3Scene.h>
#include <proj.win32/Cards.h>
#include <proj.win32/GameData.h>
#include <proj.win32/Game.h>
#include "SimpleAudioEngine.h"



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
	if (gameData::playMusic) {
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Sound/3RoadChariot.mp3", true);
	}

	//Background Sprite
	auto spriteBackground = Sprite::create("Assets/Backgrounds/jeff-nixon-skull-valley.png");
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
			if (gameData::playMusic) {

				CocosDenshion::SimpleAudioEngine::getInstance()->unloadEffect("Sound/3RoadChariot.mp3");
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



	return true;
}

void Level3Scene::update(float dt) {};




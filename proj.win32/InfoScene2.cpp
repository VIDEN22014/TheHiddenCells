#include "ui/CocosGUI.h"
#include <proj.win32/Level3Scene.h>
#include <proj.win32/InfoScene2.h>
#include <proj.win32/InfoScene.h>
#include <proj.win32/Cards.h>
#include <proj.win32/GameData.h>
#include <proj.win32/Game.h>
#include "SimpleAudioEngine.h"


using namespace gameData;

USING_NS_CC;
int count2 = 0;
Scene* InfoScene2Obj;

Scene* InfoScene2::createScene()
{
	return InfoScene2Obj = InfoScene2::create();
}

bool InfoScene2::init()
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
			if (playSound) {
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound/SoundBlip.wav");
			}
			Game::GoToInfo();
			break;
		default:
			break;
		}
		});
	this->addChild(returnButton);


	count2 = 0;


	CreateInfo("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Elite/EliteKnight_Idle_1(Big).png", "hello word");
	CreateInfo("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_1(Big).png", "hello word");
	CreateInfo("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_1(Big).png", "hello word");
	CreateInfo("Assets/Monsters/Enchanted Forest - Individual Frames/Elven King/HighElf_M_Idle + Walk_1(Big).png", "hello word");
	CreateInfo("Assets/Monsters/Enchanted Forest - Individual Frames/Wizard/Wizard_Idle + Walk_1(Big).png", "hello word");

	CreateInfo("Assets/Icons/Coins_0/coin_01.png", "hello word");
	
	return true;
}
int X = 70;
void InfoScene2::CreateInfo(char* path, char* InfoText) {
	Size size = Director::getInstance()->getWinSize();

	int countY = (count2 % 6) + 1;


	if (count2 % 6 == 0) {
		X = 70 + (count2 / 6) * 450;
	}
	auto InfoCard = cocos2d::Sprite::create(path);
	InfoCard->setPosition(Vec2(X, size.height - (130 * countY) + 20));
	this->addChild(InfoCard);

	auto InfoTextlabl = Label::create(InfoText, "Fonts/DungeonFont.ttf", gameData::fontSize);
	InfoTextlabl->setPosition(Vec2(X + 150, size.height - (130 * countY)));
	this->addChild(InfoTextlabl);


	count2++;
}

void InfoScene2::update(float dt) {};


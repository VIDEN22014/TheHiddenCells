#include "ui/CocosGUI.h"
#include <proj.win32/Level3Scene.h>
#include <proj.win32/InfoScene.h>
#include <proj.win32/Cards.h>
#include <proj.win32/GameData.h>
#include <proj.win32/Game.h>
#include "SimpleAudioEngine.h"


using namespace gameData;

USING_NS_CC;
int count = 0;
Scene* InfoSceneObj;

Scene* InfoScene::createScene()
{
	return InfoSceneObj = InfoScene::create();
}

bool InfoScene::init()
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
			Game::GoToMainMenu();
			break;
		default:
			break;
		}
		});
	this->addChild(returnButton);
	//scrollRightButton

	auto nextButton = ui::Button::create("Assets/UI/StoneButtonsLight/tile002.png", "Assets/UI/StoneButtonsLightPressed/tile002.png");
	nextButton->setScale(5);
	nextButton->setAnchorPoint(Vec2(0, 0));
	nextButton->setPosition(Vec2(size.width - 23 * nextButton->getScale(), 8 * nextButton->getScale()));
	nextButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (playSound) {
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound/SoundBlip.wav");
			}
			Game::GoToInfo2();
			break;
		default:
			break;
		}
		});
	this->addChild(nextButton);

	// на сцену вміщається 12 штук
	count = 0;
	CreateInfo("Assets/Items/Flasks/Flasks_Big/flask_big_red.png", "hello word");
	CreateInfo("Assets/Items/Flasks/Flasks_Small/flask_small_green.png", "hello word");
	CreateInfo("Assets/Items/Flasks/Flasks_Small/flask_small_blue.png", "hello word");
	CreateInfo("Assets/Items/Flasks/Flasks_Small/flask_small_yellow.png", "hello word");

	CreateInfo("Assets/Items/Chests/Chest_Gold/chest_gold_empty_open_anim/chest_empty_open_anim_f1.png", "hello word");
	CreateInfo("Assets/Items/Chests/Chest_Gold/chest_gold_empty_open_anim/chest_empty_open_anim_f1(bad).png", "hello word");

	


	CreateInfo("Assets/Weapons/weapon_regular_sword.png", "hello word");
	CreateInfo("Assets/Weapons/weapon_knight_sword.png", "hello word");
	CreateInfo("Assets/Weapons/weapon_red_gem_sword.png", "hello word");

	CreateInfo("Assets/Weapons/androide.png", "hello word");

	


	

	return true;
}
	int x = 70;
void InfoScene::CreateInfo(char *path, char* InfoText) {
	Size size = Director::getInstance()->getWinSize();

	int countY = (count % 6)+1;


	if (count%6==0) {
		x= 70+ (count / 6)*450;
	}
	auto InfoCard = cocos2d::Sprite::create(path);
	InfoCard->setPosition(Vec2(x, size.height-(130* countY)+20 ));
	this->addChild(InfoCard);

	auto InfoTextlabl = Label::create(InfoText, "Fonts/DungeonFont.ttf", gameData::fontSize);
	InfoTextlabl->setPosition(Vec2( x+150, size.height - (130* countY) ));
	this->addChild(InfoTextlabl);


	count++;
}

void InfoScene::update(float dt) {};




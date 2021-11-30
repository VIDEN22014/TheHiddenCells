#include "ui/CocosGUI.h"
#include <proj.win32/Level1Scene.h>
#include <proj.win32/Cards.h>
#include <proj.win32/GameData.h>
#include <proj.win32/Game.h>


USING_NS_CC;

Scene* Level1SceneObj;
Label* Coin1Label;
Scene* Level1Scene::createScene()
{
	return Level1SceneObj = Level1Scene::create();
}

bool Level1Scene::init()
{
	ui::Button* buttons[] = { ui::Button::create(),ui::Button::create(),ui::Button::create(),ui::Button::create(),ui::Button::create(),ui::Button::create(),ui::Button::create(),ui::Button::create(),ui::Button::create() };

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

	Coin1Label = Label::create(std::to_string(gameData::money), "Fonts/DungeonFont.ttf", 42);
	Coin1Label->setAnchorPoint(Vec2(0, 0.5));
	Coin1Label->setPosition(Vec2(CoinSprite->getPositionX() + CoinSprite->getContentSize().width, CoinSprite->getPositionY()));
	this->addChild(Coin1Label);

	Card& Dist = *(new CardHero());
	//x
	int i=0 ;
	for ( i= 0; i < 9; i++) {
		buttons[i]->loadTextures("Assets/UI/StoneButtons/tile00" + std::to_string(i) + ".png", "Assets/UI/StoneButtonsLight/tile00" + std::to_string(i) + ".png");
		buttons[i]->setScale(8.0);
		buttons[i]->setAnchorPoint(Vec2(0.5, 0.5));
		buttons[i]->setPosition(Vec2((352 + 8*16 * (i % 3)), (608 - 8*16 * (i / 3))));
		
		buttons[i]->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				//Sprite* sprite;
				//Coin1Label->setString(std::to_string(i));
				buttons[i]->loadTextures("Assets/UI/StoneButtons/tile001.png", "Assets/UI/StoneButtonsLight/tile00" + std::to_string(i) + ".png");
				//Dist.moveCard();
				break;
			case ui::Widget::TouchEventType::ENDED:
				
				break;
			default:
				break;
			}
			});
		this->addChild(buttons[i]);
	}
    //
	
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
			Dist.moveCard();
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




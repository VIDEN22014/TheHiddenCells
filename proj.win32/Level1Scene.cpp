#include "ui/CocosGUI.h"
#include <proj.win32/Level1Scene.h>
#include <proj.win32/Cards.h>

USING_NS_CC;

Scene* Level1SceneObj;


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

	//Background Sprite
	auto spriteBackground = Sprite::create("Assets/Backgrounds/BG_4_960.png");
	Size size = Director::getInstance()->getWinSize();
	spriteBackground->setAnchorPoint(Vec2(0, 0));
	spriteBackground->setPosition(Vec2(0, 0));
	this->addChild(spriteBackground);

	//Coin Sprite
	auto CoinSprite = Sprite::create("coin_01.png");
	CoinSprite->setPosition(Vec2(0 + CoinSprite->getContentSize().width, 960 - CoinSprite->getContentSize().height));//820 900
	this->addChild(CoinSprite);
	auto animation = Animation::create();
	animation->addSpriteFrameWithFile("coin_01.png");
	animation->addSpriteFrameWithFile("coin_02.png");
	animation->addSpriteFrameWithFile("coin_03.png");
	animation->addSpriteFrameWithFile("coin_04.png");
	animation->addSpriteFrameWithFile("coin_05.png");
	animation->addSpriteFrameWithFile("coin_06.png");
	animation->addSpriteFrameWithFile("coin_07.png");
	animation->addSpriteFrameWithFile("coin_08.png");
	animation->setDelayPerUnit(0.1111111112f);
	animation->setLoops(-1);
	CoinSprite->runAction(Animate::create(animation));
	auto CoinLabel = Label::createWithTTF(std::to_string(gameData::money), "DungeonFont.ttf", 42);
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

	CardHero crd;
	crd.moveCard();
	return true;
}

void Level1Scene::update(float dt) {};




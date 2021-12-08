#include<proj.win32/EndGameScene.h>
#include <cocos/ui/UIButton.h>
#include <proj.win32/Game.h>

USING_NS_CC;

Scene* EndGameScene::createScene()
{
	return  EndGameScene::create();
}

bool EndGameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	
	auto spriteBackground = Sprite::create("Assets/Backgrounds/BG 4.png");
	Size size = Director::getInstance()->getWinSize();
	spriteBackground->setAnchorPoint(Vec2(0, 0));
	spriteBackground->setPosition(Vec2(0, 0));
	this->addChild(spriteBackground);

	auto CoinSprite = Sprite::create("Assets/Icons/Coins_0/coin_01.png");
	CoinSprite->setPosition(Vec2(480.0,480.0));
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
	



	auto InfoLabel= Label::createWithTTF("Game Over", "Fonts/DungeonFont.ttf", 42);
	InfoLabel->setAnchorPoint(Vec2(0, 0.5));
	InfoLabel->setPosition(Vec2(CoinSprite->getPositionX() + CoinSprite->getContentSize().width - 70, CoinSprite->getPositionY()+70));
	this->addChild(InfoLabel);

	auto spriteDeadHero = Sprite::create();
	spriteDeadHero->setAnchorPoint(Vec2(0, 0));
	spriteDeadHero->setScale(5.0);
	spriteDeadHero->setPosition(Vec2(CoinSprite->getPositionX() + CoinSprite->getContentSize().width - 50, CoinSprite->getPositionY() + 100));
	this->addChild(spriteDeadHero);
	if (gameData::chosenHero == 0) {
		spriteDeadHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_3(Die).png");
	}
	else if (gameData::chosenHero == 1) { 
		spriteDeadHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Elite/EliteKnight_Idle_3(Die).png");
	}
	else if (gameData::chosenHero == 2) {
		spriteDeadHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_3(Die).png");
	}
	else if (gameData::chosenHero == 3) {
		spriteDeadHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_3(Die).png");
	}

	auto CoinLabel = Label::createWithTTF(std::to_string(gameData::tempMoney), "Fonts/DungeonFont.ttf", 42);
	CoinLabel->setAnchorPoint(Vec2(0, 0.5));
	CoinLabel->setPosition(Vec2(CoinSprite->getPositionX() + CoinSprite->getContentSize().width, CoinSprite->getPositionY()));
	this->addChild(CoinLabel);

	auto InfoLabel2 = Label::createWithTTF("Restart game", "Fonts/DungeonFont.ttf", 42);
	InfoLabel2->setAnchorPoint(Vec2(0, 0.5));
	InfoLabel2->setPosition(Vec2(CoinSprite->getPositionX() + CoinSprite->getContentSize().width - 90, CoinSprite->getPositionY() - 80));
	this->addChild(InfoLabel2);

	auto Accept = ui::Button::create("Assets/UI/StoneButtons/tile020.png", "Assets/UI/StoneButtonsLight/tile020.png");
	Accept->setAnchorPoint(Vec2(0, 0));
	Accept->setScale(4.5);
	Accept->setPosition(Vec2(CoinSprite->getPositionX() + CoinSprite->getContentSize().width + 50, CoinSprite->getPositionY() - 190));

	Accept->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (gameData::currentLevel == 1) {
				Game::GoToLevel1();
			}
			if (gameData::currentLevel == 2) {
				Game::GoToLevel2();
			}
			if (gameData::currentLevel == 3) {
				Game::GoToLevel3();
			}
			break;
		default:
			break;
		}
		});
	this->addChild(Accept);

	auto Reject = ui::Button::create("Assets/UI/StoneButtons/tile016.png", "Assets/UI/StoneButtonsLight/tile016.png");
	Reject->setAnchorPoint(Vec2(0, 0));
	Reject->setScale(4.5);
	Reject->setPosition(Vec2(CoinSprite->getPositionX() + CoinSprite->getContentSize().width - 50, CoinSprite->getPositionY() - 190));

	Reject->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
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
	this->addChild(Reject);

	return true;
}
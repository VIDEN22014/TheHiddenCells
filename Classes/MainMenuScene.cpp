#include "MainMenuScene.h"
#include <cocos/ui/UIButton.h>
#include <proj.win32/Game.h>
#include <proj.win32/ShopScene.h>
#include "SimpleAudioEngine.h"
#include <proj.win32/GameData.h>


USING_NS_CC;


Scene* MainMenuScene::createScene()
{
	return MainMenuScene::create();
}
bool playSound = true;
bool playMusic = true;
cocos2d::Label* LabelAmountXP1;
cocos2d::Label* LabelAmountAmmo1;
cocos2d::Sprite* minixp1;
cocos2d::Sprite* miniammo1;
bool MainMenuScene::init()
{

	if (!Scene::init())
	{
		return false;
	}

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sound/SoundBlip.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sound/backgroundmusic.mp3");



	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Sound/backgroundmusic.mp3", true);
	CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.25f);

	auto spriteBackground = Sprite::create("Assets/Backgrounds/BG 4.png");
	Size size = Director::getInstance()->getWinSize();
	spriteBackground->setPosition(Vec2(0, 0));
	spriteBackground->setAnchorPoint(Vec2(0, 0));
	this->addChild(spriteBackground);



	auto CoinSprite = Sprite::create("Assets/Icons/Coins_0/coin_01.png");
	CoinSprite->setPosition(Vec2(0 + CoinSprite->getContentSize().width, 960- CoinSprite->getContentSize().height));//820 900
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
	CoinLabel->setAnchorPoint(Vec2(0,0.5));
	CoinLabel->setPosition(Vec2(CoinSprite->getPositionX()+CoinSprite->getContentSize().width, CoinSprite->getPositionY()));
	this->addChild(CoinLabel);



	auto spriteIcon = Sprite::create("Assets/Icons/iconForHero.png");
	spriteIcon->setPosition(Vec2(size.width / 2, 555));
	spriteIcon->setScale(5.0);
	this->addChild(spriteIcon);

	

	spriteStartHero = Sprite::create("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_1.png");
	spriteStartHero->setPosition(Vec2(size.width / 2, 555));
	spriteStartHero->setScale(5.0);
	this->addChild(spriteStartHero);

	auto animationHero = Animation::create();
	animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_1.png");
	animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_2.png");
	animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_3.png");
	animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_4.png");
	animationHero->setDelayPerUnit(0.1111111112f);
	animationHero->setLoops(-1);

	spriteStartHero->runAction(Animate::create(animationHero));

	//встановлення іконки хп на іконку героя
	minixp1 = Sprite::create("Assets/Icons/04_heart/heart.png");
	minixp1->setScale(1.7);
	minixp1->setPosition(420, 615);
	this->addChild(minixp1);
	//встановлення іконки зброї на іконку героя
	miniammo1 = Sprite::create("Assets/Weapons/weapon_regular_sword.png");
	miniammo1->setScale(2.0);
	miniammo1->setPosition(520, 610);
	this->addChild(miniammo1);

	//встановлення лейбла к-сті хп
	LabelAmountXP1 = Label::create("", "Fonts/DungeonFont.ttf", 18);
	LabelAmountXP1->setAnchorPoint(Vec2(0, 0.5));
	LabelAmountXP1->setPosition(435, 615);
	this->addChild(LabelAmountXP1);
	// встановлення лейбла к-сті хп зброї(урону)
	LabelAmountAmmo1 = Label::create("", "Fonts/DungeonFont.ttf", 18);
	LabelAmountAmmo1->setAnchorPoint(Vec2(0, 0.5));
	LabelAmountAmmo1->setPosition(535, 610);
	this->addChild(LabelAmountAmmo1);

	changeTextureHeroes();

	auto spriteKNIS = Sprite::create("Assets/Icons/KNIS-Gerb/knisback.png");
	spriteKNIS->setPosition(Vec2(825, 135));
	this->addChild(spriteKNIS);

	auto spriteKNISGerb = Sprite::create("Assets/Icons/KNIS-Gerb/knisGerb01.png");
	spriteKNISGerb->setPosition(Vec2(825, 135));
	this->addChild(spriteKNISGerb);

	auto animationGerb = Animation::create();
	animationGerb->addSpriteFrameWithFile("Assets/Icons/KNIS-Gerb/knisGerb02.png");
	animationGerb->addSpriteFrameWithFile("Assets/Icons/KNIS-Gerb/knisGerb03.png");
	animationGerb->addSpriteFrameWithFile("Assets/Icons/KNIS-Gerb/knisGerb04.png");
	animationGerb->addSpriteFrameWithFile("Assets/Icons/KNIS-Gerb/knisGerb05.png");
	animationGerb->addSpriteFrameWithFile("Assets/Icons/KNIS-Gerb/knisGerb06.png");
	animationGerb->addSpriteFrameWithFile("Assets/Icons/KNIS-Gerb/knisGerb07.png");
	animationGerb->addSpriteFrameWithFile("Assets/Icons/KNIS-Gerb/knisGerb08.png");
	animationGerb->addSpriteFrameWithFile("Assets/Icons/KNIS-Gerb/knisGerb09.png");
	animationGerb->addSpriteFrameWithFile("Assets/Icons/KNIS-Gerb/knisGerb10.png");
	animationGerb->addSpriteFrameWithFile("Assets/Icons/KNIS-Gerb/knisGerb11.png");
	animationGerb->addSpriteFrameWithFile("Assets/Icons/KNIS-Gerb/knisGerb12.png");
	animationGerb->setDelayPerUnit(0.322222222f);
	animationGerb->setLoops(-1);

	spriteKNISGerb->runAction(Animate::create(animationGerb));

	

	auto levelSelectButton = ui::Button::create("Assets/UI/Test-Button/startButton.png", "Assets/UI/Test-Button/startButtonPressed.png");
	levelSelectButton->setAnchorPoint(Vec2(0, 0));
	levelSelectButton->setScale(4.5);
	levelSelectButton->setPosition(Vec2(440, 375));

	levelSelectButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (playSound) {
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("SoundBlip.wav");
			}
			Game::GoToLevelSelect();
			break;
		default:
			break;
		}
		});
	this->addChild(levelSelectButton);
	//
	auto shopButton = ui::Button::create("Assets/UI/Test-Button/shopButton.png", "Assets/UI/Test-Button/shopButtonPressed.png");
	shopButton->setAnchorPoint(Vec2(0, 0));
	shopButton->setScale(4.5);
	shopButton->setPosition(Vec2(440, 275));

	shopButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (playSound) {
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound/SoundBlip.wav");
			}
			Game::GoToShop();
			break;
		default:
			break;
		}
		});
	this->addChild(shopButton);
	//
	auto exitButton = ui::Button::create("Assets/UI/StoneButtons/tile000.png", "Assets/UI/Test-Button/exitButtonPressed.png");
	exitButton->setAnchorPoint(Vec2(0, 0));
	exitButton->setScale(4.5);
	exitButton->setPosition(Vec2(440, 175));

	exitButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:

			break;
		case ui::Widget::TouchEventType::ENDED:
			if (playSound) {
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound/SoundBlip.wav");
				Game::GoToExit();
			}
			break;
		default:
			break;
		}
		});
	this->addChild(exitButton);
	//

	auto startSoundButton = ui::Button::create("Assets/UI/Test-Button/sountButton.png", "Assets/UI/Test-Button/sountButtonPressed.png");
	startSoundButton->setAnchorPoint(Vec2(0, 0));
	startSoundButton->setScale(4.5);
	startSoundButton->setPosition(Vec2(735, 855));
	this->addChild(startSoundButton);
	startSoundButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			playSound = true;
			CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sound/SoundBlip.wav");
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound/SoundBlip.wav");
			break;
		default:
			break;
		}
		});
	//
	auto endSoundButton = ui::Button::create("Assets/UI/Test-Button/sountEndButton.png", "Assets/UI/Test-Button/sountEndButtonPressed.png");
	endSoundButton->setAnchorPoint(Vec2(0, 0));
	endSoundButton->setScale(4.5);
	endSoundButton->setPosition(Vec2(825, 855));
	this->addChild(endSoundButton);
	endSoundButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound/SoundBlip.wav");
			playSound = false;
			CocosDenshion::SimpleAudioEngine::getInstance()->unloadEffect("Sound/SoundBlip.wav");
			break;
		default:
			break;
		}
		});
	//
	auto startMusicButton = ui::Button::create("Assets/UI/Test-Button/musicButton.png", "Assets/UI/Test-Button/musicButtonPressed.png");
	startMusicButton->setAnchorPoint(Vec2(0, 0));
	startMusicButton->setScale(4.5);	
	startMusicButton->setPosition(Vec2(735, 775));
	this->addChild(startMusicButton);
	startMusicButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			playMusic = true;
			if (playSound) {
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound/SoundBlip.wav");
			}
			CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sound/backgroundmusic.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Sound/backgroundmusic.mp3", true);
			break;
		default:
			break;
		}
		});
	//
	auto endMusicButton = ui::Button::create("Assets/UI/Test-Button/musicEndButton.png", "Assets/UI/Test-Button/musicEndButtonPressed.png");
	endMusicButton->setAnchorPoint(Vec2(0, 0));
	endMusicButton->setScale(4.5);
	endMusicButton->setPosition(Vec2(825, 775));
	this->addChild(endMusicButton);
	endMusicButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			playMusic = false;
			if (playSound) {
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound/SoundBlip.wav");
			}
			CocosDenshion::SimpleAudioEngine::getInstance()->unloadEffect("Sound/backgroundmusic.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
			break;
		default:
			break;
		}
		});
	
	this->scheduleUpdate();

	return true;
}
void MainMenuScene::changeTextureHeroes() {

		if (gameData::chosenHero==0&&gameData::lockHero[0]){
			miniammo1->setTexture("Assets/Weapons/weapon_regular_sword.png");
			LabelAmountXP1->setString(std::to_string(gameData::amountXPHeros[0]));
			LabelAmountAmmo1->setString(std::to_string(gameData::amountAmmoHeros[0]));

			spriteStartHero->stopAllActions();
			spriteStartHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_1.png");

			auto animationHero = Animation::create();
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_1.png");
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_2.png");
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_3.png");
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_4.png");
			animationHero->setDelayPerUnit(0.1111111112f);
			animationHero->setLoops(-1);

			spriteStartHero->runAction(Animate::create(animationHero));
			return;
		}
		else if (gameData::chosenHero == 1 && gameData::lockHero[1]) {
			miniammo1->setTexture("Assets/Weapons/weapon_hammer.png");
			LabelAmountXP1->setString(std::to_string(gameData::amountXPHeros[1]));
			LabelAmountAmmo1->setString(std::to_string(gameData::amountAmmoHeros[1]));
			spriteStartHero->stopAllActions();
			spriteStartHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_1.png");

			auto animationHero = Animation::create();
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_1.png");
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_2.png");
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_3.png");
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_4.png");
			animationHero->setDelayPerUnit(0.1111111112f);
			animationHero->setLoops(-1);

			spriteStartHero->runAction(Animate::create(animationHero));
			return;
		}
		else if (gameData::chosenHero == 2 && gameData::lockHero[2]) {
			miniammo1->setTexture("Assets/Weapons/weapon_red_magic_staff.png");
			miniammo1->setScale(1.5);
			LabelAmountXP1->setString(std::to_string(gameData::amountXPHeros[2]));
			LabelAmountAmmo1->setString(std::to_string(gameData::amountAmmoHeros[2]));
			spriteStartHero->stopAllActions();
			spriteStartHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_1.png");

			auto animationHero = Animation::create();
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_1.png");
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_2.png");
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_3.png");
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_4.png");
			animationHero->setDelayPerUnit(0.1111111112f);
			animationHero->setLoops(-1);

			spriteStartHero->runAction(Animate::create(animationHero));
			return;

		}
		else if (gameData::chosenHero == 3 && gameData::lockHero[3]) {
			miniammo1->setTexture("Assets/Weapons/weapon_golden_sword.png");
			LabelAmountXP1->setString(std::to_string(gameData::amountXPHeros[3]));
			LabelAmountAmmo1->setString(std::to_string(gameData::amountAmmoHeros[3]));
			spriteStartHero->stopAllActions();
			spriteStartHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_1.png");

			auto animationHero = Animation::create();
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_1.png");
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_2.png");
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_3.png");
			animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_4.png");
			animationHero->setDelayPerUnit(0.1111111112f);
			animationHero->setLoops(-1);

			spriteStartHero->runAction(Animate::create(animationHero));
			return;
		}
			if (gameData::lastBuyHero == 3) {
				miniammo1->setTexture("Assets/Weapons/weapon_golden_sword.png");
				LabelAmountXP1->setString(std::to_string(gameData::amountXPHeros[3]));
				LabelAmountAmmo1->setString(std::to_string(gameData::amountAmmoHeros[3]));
				spriteStartHero->stopAllActions();
				spriteStartHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_1.png");

				auto animationHero = Animation::create();
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_1.png");
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_2.png");
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_3.png");
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_4.png");
				animationHero->setDelayPerUnit(0.1111111112f);
				animationHero->setLoops(-1);

				spriteStartHero->runAction(Animate::create(animationHero));
				return;
			}
			else if (gameData::lastBuyHero == 2) {
				miniammo1->setTexture("Assets/Weapons/weapon_red_magic_staff.png");
				miniammo1->setScale(1.5);
				LabelAmountXP1->setString(std::to_string(gameData::amountXPHeros[2]));
				LabelAmountAmmo1->setString(std::to_string(gameData::amountAmmoHeros[2]));
				spriteStartHero->stopAllActions();
				spriteStartHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_1.png");

				auto animationHero = Animation::create();
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_1.png");
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_2.png");
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_3.png");
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_4.png");
				animationHero->setDelayPerUnit(0.1111111112f);
				animationHero->setLoops(-1);

				spriteStartHero->runAction(Animate::create(animationHero));
				return;
			}
			else if (gameData::lastBuyHero == 1) {
				miniammo1->setTexture("Assets/Weapons/weapon_hammer.png");
				LabelAmountXP1->setString(std::to_string(gameData::amountXPHeros[1]));
				LabelAmountAmmo1->setString(std::to_string(gameData::amountAmmoHeros[1]));
				spriteStartHero->stopAllActions();
				spriteStartHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_1.png");

				auto animationHero = Animation::create();
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_1.png");
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_2.png");
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_3.png");
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_4.png");
				animationHero->setDelayPerUnit(0.1111111112f);
				animationHero->setLoops(-1);

				spriteStartHero->runAction(Animate::create(animationHero));
				return;
			}
			else if (gameData::lastBuyHero == 0) {
				miniammo1->setTexture("Assets/Weapons/weapon_regular_sword.png");
				LabelAmountXP1->setString(std::to_string(gameData::amountXPHeros[0]));
				LabelAmountAmmo1->setString(std::to_string(gameData::amountAmmoHeros[0]));
				//if(spriteStartHero->numberOfRunningActions()!=0)
				spriteStartHero->stopAllActions();
				spriteStartHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_1.png");

				auto animationHero = Animation::create();
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_1.png");
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_2.png");
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_3.png");
				animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_4.png");
				animationHero->setDelayPerUnit(0.1111111112f);
				animationHero->setLoops(-1);

				spriteStartHero->runAction(Animate::create(animationHero));
				return;
	         }
}
void MainMenuScene::update(float dt) {}
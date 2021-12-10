#pragma once

#ifndef __CARDS_H__
#define __CARDS_H__

#include <proj.win32/GameData.h>
#include "cocos2d.h"
using namespace cocos2d;



class Card {
public:
	Card(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) {
		pathToSprite = spriteCardPath;
		pos = *(new position(cardpos.x, cardpos.y));
		spriteFrame = cocos2d::Sprite::create(spriteFramePath);
		spriteCard = cocos2d::Sprite::create(spriteCardPath);
		spriteCard->setPosition(Vec2(278 + cardpos.y * (192 + 10), 682 - cardpos.x * (192 + 10)));
		spriteFrame->setPosition(Vec2(278 + cardpos.y * (192 + 10), 682 - cardpos.x * (192 + 10)));
		scene->addChild(spriteFrame, 1);
		scene->addChild(spriteCard, 2);
		cardMaxHP = 10;
		cardCurrentHP = cardMaxHP;
		labelCard = Label::create(std::to_string(cardCurrentHP), "Fonts/DungeonFont.ttf", gameData::fontSize);
		labelCard->setAnchorPoint(Vec2(0, 1));
		labelCard->setPosition(Vec2(spriteCard->getPositionX() - 192 / 2 + 16, spriteCard->getPositionY() + 192 / 2 - 16));
		scene->addChild(labelCard, 2);


		spriteRegenXP = cocos2d::Sprite::create("Assets/Icons/heart/24.png");
		spriteRegenXP->setAnchorPoint(Vec2(1, 1));
		spriteRegenXP->setPosition(Vec2(spriteCard->getPositionX() + 142 / 2 + 16, spriteCard->getPositionY() + 192 / 2 - 16));
		spriteRegenXP->setVisible(false);
		scene->addChild(spriteRegenXP, 4);

		spritePoisned = cocos2d::Sprite::create("Assets/Icons/heart/47.png");
		spritePoisned->setAnchorPoint(Vec2(1, 1));
		spritePoisned->setPosition(Vec2(spriteCard->getPositionX() + 142 / 2 + 16, spriteCard->getPositionY() + 192 / 2 - 16));
		spritePoisned->setVisible(false);
		scene->addChild(spritePoisned, 3);

		
	};
	Card(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene, int cardMaxHP) {
		pos = *(new position(cardpos.x, cardpos.y));
		spriteFrame = cocos2d::Sprite::create(spriteFramePath);
		spriteCard = cocos2d::Sprite::create(spriteCardPath);
		spriteCard->setPosition(Vec2(278 + cardpos.y * (192 + 10), 682 - cardpos.x * (192 + 10)));
		spriteFrame->setPosition(Vec2(278 + cardpos.y * (192 + 10), 682 - cardpos.x * (192 + 10)));
		scene->addChild(spriteFrame, 1);
		scene->addChild(spriteCard, 2);
		this->cardMaxHP = cardMaxHP;
		cardCurrentHP = this->cardMaxHP;
		labelCard = Label::create(std::to_string(cardCurrentHP), "Fonts/DungeonFont.ttf", gameData::fontSize);
		labelCard->setAnchorPoint(Vec2(0, 1));
		labelCard->setPosition(Vec2(spriteCard->getPositionX() - 192 / 2 + 16, spriteCard->getPositionY() + 192 / 2 - 16));
		scene->addChild(labelCard, 2);

		spriteRegenXP = cocos2d::Sprite::create("Assets/Icons/heart/47.png");
		spriteRegenXP->setAnchorPoint(Vec2(1, 1));
		spriteRegenXP->setPosition(Vec2(spriteCard->getPositionX() + 142 / 2 + 16, spriteCard->getPositionY() + 192 / 2 - 10));
		spriteRegenXP->setVisible(false);
		scene->addChild(spriteRegenXP, 4);

		spritePoisned = cocos2d::Sprite::create("Assets/Icons/heart/24.png");
		spritePoisned->setAnchorPoint(Vec2(1, 1));
		spritePoisned->setPosition(Vec2(spriteCard->getPositionX() + 142 / 2 + 16, spriteCard->getPositionY() + 192 / 2 - 10));
		spritePoisned->setVisible(false);
		scene->addChild(spritePoisned, 3);


	};
	virtual ~Card() {
		spriteFrame->removeFromParentAndCleanup(true);
		spriteCard->removeFromParentAndCleanup(true);
		labelCard->removeFromParentAndCleanup(true);

		spritePoisned->removeFromParentAndCleanup(true);
		spriteRegenXP->removeFromParentAndCleanup(true);
		if (spriteWeapon!=nullptr && labelWeapon!=nullptr)
		{
			spriteWeapon->removeFromParentAndCleanup(true);
			labelWeapon->removeFromParentAndCleanup(true);
		}
		delete weapon;
	}
	int cardMaxHP;
	int cardCurrentHP;
	int cardBuff = 0;//0- None ;1- Regen ;2- Poisoned
	//double ScaleCard = 1;
	bool isBoss = false;
	bool isPoisned=false;
	bool isHealing = false;
	std::string pathToSprite;
	//std::string pathToFrame;
	cocos2d::Sprite* spriteFrame = nullptr;
	cocos2d::Sprite* spriteCard = nullptr;
    cocos2d::Sprite* spriteWeapon = nullptr;

	cocos2d::Sprite* spritePoisned = nullptr;
	cocos2d::Sprite* spriteRegenXP = nullptr;

	cocos2d::Label* labelCard = nullptr;
	cocos2d::Label* labelWeapon = nullptr;
	position pos;
	Card* weapon = nullptr;

	virtual int cardInteract(Card* cards[3][3]);
	virtual void cardOnTurn(Card* cards[3][3]);
	virtual void labelUpdate(bool isHeroLabel, Card* card);
	virtual void deleteCard();

	virtual void weaponEffect(Card* cards[3][3], Card* enemy);
	virtual void openTreasure(std::string typeChest);
	virtual void lockScene();
	virtual void unlockScene();
};

class CardHero : public Card {
public:
	;
	CardHero(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene, gameData::amountXPHeros[gameData::chosenHero]) {
		this->labelUpdate(true,this);
	};
	~CardHero() override {};
	void cardOnTurn(Card* cards[3][3]) override;
};

class CardCoin : public Card {
public:
	CardCoin(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene) {
		cardMaxHP = rand() % 12 + 1;
		cardCurrentHP = cardMaxHP;
		this->labelUpdate(false,this);
	};
	~CardCoin() override {};
	int cardInteract(Card* cards[3][3]) override;
};

//Potion Cards
class CardPotion : public Card {
public:
	CardPotion(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene) {};
	~CardPotion() override {};
	int cardInteract(Card* cards[3][3]) override;
};

class CardRedPotion :public CardPotion {
public:
	CardRedPotion(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardPotion(cardpos, spriteCardPath, spriteFramePath, scene) {};
	~CardRedPotion() override {};
	int cardInteract(Card* cards[3][3]) override;
};

class CardGreenPotion :public CardPotion {
public:
	CardGreenPotion(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardPotion(cardpos, spriteCardPath, spriteFramePath, scene) {
		cardMaxHP = 1;
		cardCurrentHP = cardMaxHP;
		this->labelUpdate(false,this);
	};
	~CardGreenPotion() override {};
	int cardInteract(Card* cards[3][3]) override;
};

class CardBluePotion :public CardPotion {
public:
	CardBluePotion(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardPotion(cardpos, spriteCardPath, spriteFramePath, scene) {
		cardMaxHP = 1;
		cardCurrentHP = cardMaxHP;
		this->labelUpdate(false,this);

	};
	~CardBluePotion() override {};
	int cardInteract(Card* cards[3][3]) override;
};

class CardYellowPotion :public CardPotion {
public:
	CardYellowPotion(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardPotion(cardpos, spriteCardPath, spriteFramePath, scene) {  };
	~CardYellowPotion() override {};
	int cardInteract(Card* cards[3][3]) override;
};

//Weapon Cards
class CardWeapon : public Card {
public:
	CardWeapon(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene) {};
	CardWeapon(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene, int cardMaxHP) : Card(cardpos, spriteCardPath, spriteFramePath, scene, cardMaxHP) {};

	~CardWeapon() override {};
	int cardInteract(Card* cards[3][3]) override;
	void weaponEffect(Card* cards[3][3], Card* enemy) override;

};

class CardCommonWeapon :public CardWeapon {
public:
	CardCommonWeapon(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardWeapon(cardpos, spriteCardPath, spriteFramePath, scene) {
		isPoisned = false;
		isHealing = false;
	}
	CardCommonWeapon(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene, int cardMaxHP) : CardWeapon(cardpos, spriteCardPath, spriteFramePath, scene, cardMaxHP) { 
		isPoisned = false;
		isHealing = false;
	};
	
	~CardCommonWeapon() override {};
};

class CardHealingWeapon :public CardWeapon {
public:
	CardHealingWeapon(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardWeapon(cardpos, spriteCardPath, spriteFramePath, scene) {
		isPoisned = false;
		isHealing = true;
	};
	CardHealingWeapon(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene, int cardMaxHP) : CardWeapon(cardpos, spriteCardPath, spriteFramePath, scene, cardMaxHP) { 
		isPoisned = false;
		isHealing = true;
	};
	~CardHealingWeapon() override {};
	int cardInteract(Card* cards[3][3]) override;
	void weaponEffect(Card* cards[3][3], Card* enemy) override;
};

class CardPoisonedWeapon :public CardWeapon {
public:
	CardPoisonedWeapon(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardWeapon(cardpos, spriteCardPath, spriteFramePath, scene) { 
	isPoisned = true; 
	isHealing = false;

	};
	CardPoisonedWeapon(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene, int cardMaxHP) : CardWeapon(cardpos, spriteCardPath, spriteFramePath, scene, cardMaxHP) {
	isPoisned = true; 
	isHealing = false;

	 };
	~CardPoisonedWeapon() override {};
	int cardInteract(Card* cards[3][3]) override;
	void weaponEffect(Card* cards[3][3], Card* enemy) override;
};


//Monster Cards
class CardCommonMonster : public Card {
public:
	cocos2d::Sprite* spritePoisned = nullptr;
	CardCommonMonster(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene, int cardMaxHP) : Card(cardpos, spriteCardPath, spriteFramePath, scene, cardMaxHP) {  };
	~CardCommonMonster() override {};
	int cardInteract(Card* cards[3][3]) override;
};
class CardRegenXPMonster : public Card {
public:
	cocos2d::Sprite* spritePoisned = nullptr;
	CardRegenXPMonster(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene, int cardMaxHP) : Card(cardpos, spriteCardPath, spriteFramePath, scene, cardMaxHP) {
		gameData::posBossHpRegen = cardpos;
		isBoss = true;
		
	};
	~CardRegenXPMonster() override {};
	int cardInteract(Card* cards[3][3]) override;
};
class CardPoisonedMonster : public Card {
public:
	cocos2d::Sprite* spritePoisned = nullptr;
	CardPoisonedMonster(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene, int cardMaxHP) : Card(cardpos, spriteCardPath, spriteFramePath, scene, cardMaxHP) {
		gameData::posBossHpRegen = cardpos;
		isBoss = true;
	
	};
	~CardPoisonedMonster() override {};
	int cardInteract(Card* cards[3][3]) override;
};
//Chest Cards
class CardTreasure : public Card {
public:

	CardTreasure(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene) {
		cardMaxHP = 1;
		cardCurrentHP = cardMaxHP;
		this->labelCard->setVisible(false);
	};
	~CardTreasure() override {};
	void deleteCard() override;
};

class CardGoodTreasure :public CardTreasure {
public:
	CardGoodTreasure(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardTreasure(cardpos, spriteCardPath, spriteFramePath, scene) {};
	~CardGoodTreasure() override {};
	int cardInteract(Card* cards[3][3]) override;
};

class CardBadTreasure :public CardTreasure {
public:
	CardBadTreasure(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardTreasure(cardpos, spriteCardPath, spriteFramePath, scene) {  };
	~CardBadTreasure() override {};
	int cardInteract(Card* cards[3][3]) override;
};

#endif // __CARDS_H__
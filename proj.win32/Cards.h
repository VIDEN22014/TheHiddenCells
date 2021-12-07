#pragma once

#ifndef __CARDS_H__
#define __CARDS_H__

#include <proj.win32/GameData.h>
#include "cocos2d.h"
using namespace cocos2d;



class Card {
public:
	Card(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) {
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
	};
	int cardMaxHP;
	int cardCurrentHP;
	int cardBuff = 0;//0- None ;1- Regen ;2- Poisoned
	double ScaleCard = 1;
	bool isBoss = false;
	cocos2d::Sprite* spriteFrame = nullptr;
	cocos2d::Sprite* spriteCard = nullptr;
    cocos2d::Sprite* spriteWeapon = nullptr;

	cocos2d::Label* labelCard = nullptr;
	cocos2d::Label* labelWeapon = nullptr;
	position pos;
	Card* weapon = nullptr;

	virtual int cardInteract(Card* cards[3][3]);
	virtual void cardOnTurn(Card* cards[3][3]);
	virtual void labelUpdate(bool isHeroLabel);
	virtual void deleteCard();

	virtual void weaponEffect(Card* cards[3][3], Card* enemy);
	virtual void openTreasure(std::string typeChest);
	virtual void lockScene();
	virtual void unlockScene();
};

class CardHero : public Card {
public:

	CardHero(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene, gameData::amountXPHeros[gameData::chosenHero]) {
		this->labelUpdate(true);
	};
	void cardOnTurn(Card* cards[3][3]) override;
};

class CardCoin : public Card {
public:
	CardCoin(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene) {
		cardMaxHP = rand() % 12 + 1;
		cardCurrentHP = cardMaxHP;
		this->labelUpdate(false);
	};
	int cardInteract(Card* cards[3][3]) override;
};

//Potion Cards
class CardPotion : public Card {
public:
	CardPotion(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene) {};
	int cardInteract(Card* cards[3][3]) override;
};

class CardRedPotion :public CardPotion {
public:
	CardRedPotion(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardPotion(cardpos, spriteCardPath, spriteFramePath, scene) {};
	int cardInteract(Card* cards[3][3]) override;
};

class CardGreenPotion :public CardPotion {
public:
	CardGreenPotion(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardPotion(cardpos, spriteCardPath, spriteFramePath, scene) {
		cardMaxHP = 1;
		cardCurrentHP = cardMaxHP;
		this->labelUpdate(false);
	};
	int cardInteract(Card* cards[3][3]) override;
};

class CardBluePotion :public CardPotion {
public:
	CardBluePotion(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardPotion(cardpos, spriteCardPath, spriteFramePath, scene) {
		cardMaxHP = 1;
		cardCurrentHP = cardMaxHP;
		this->labelUpdate(false);
	};
	int cardInteract(Card* cards[3][3]) override;
};

class CardYellowPotion :public CardPotion {
public:
	CardYellowPotion(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardPotion(cardpos, spriteCardPath, spriteFramePath, scene) {};
	int cardInteract(Card* cards[3][3]) override;
};

//Weapon Cards
class CardWeapon : public Card {
public:
	CardWeapon(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene) {};
	int cardInteract(Card* cards[3][3]) override;
	void weaponEffect(Card* cards[3][3], Card* enemy) override;

};

class CardCommonWeapon :public CardWeapon {
public:
	CardCommonWeapon(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardWeapon(cardpos, spriteCardPath, spriteFramePath, scene) {};
};

class CardHealingWeapon :public CardWeapon {
public:
	CardHealingWeapon(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardWeapon(cardpos, spriteCardPath, spriteFramePath, scene) {};
	void weaponEffect(Card* cards[3][3], Card* enemy) override;
};

class CardPoisonedWeapon :public CardWeapon {
public:
	CardPoisonedWeapon(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardWeapon(cardpos, spriteCardPath, spriteFramePath, scene) {};
	void weaponEffect(Card* cards[3][3], Card* enemy) override;
};


//Monster Cards
class CardCommonMonster : public Card {
public:
	CardCommonMonster(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene, int cardMaxHP) : Card(cardpos, spriteCardPath, spriteFramePath, scene, cardMaxHP) {};
	int cardInteract(Card* cards[3][3]) override;
};
class CardRegenXPMonster : public Card {
public:
	CardRegenXPMonster(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene, int cardMaxHP) : Card(cardpos, spriteCardPath, spriteFramePath, scene, cardMaxHP) {
		gameData::posBossHpRegen = cardpos;
		isBoss = true;
	};
	int cardInteract(Card* cards[3][3]) override;
};
class CardPoisonedMonster : public Card {
public:
	CardPoisonedMonster(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene, int cardMaxHP) : Card(cardpos, spriteCardPath, spriteFramePath, scene, cardMaxHP) {
		gameData::posBossHpRegen = cardpos;
		isBoss = true;
	};
	int cardInteract(Card* cards[3][3]) override;
};
//Chest Cards
class CardTeasure : public Card {
public:

	CardTeasure(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene) {
		cardMaxHP = 1;
		cardCurrentHP = cardMaxHP;
		this->labelCard->setVisible(false);
	};
};

class CardGoodTreasure :public CardTeasure {
public:
	CardGoodTreasure(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardTeasure(cardpos, spriteCardPath, spriteFramePath, scene) {};
	int cardInteract(Card* cards[3][3]) override;
};

class CardBadTreasure :public CardTeasure {
public:
	CardBadTreasure(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardTeasure(cardpos, spriteCardPath, spriteFramePath, scene) {  };
	int cardInteract(Card* cards[3][3]) override;
};

#endif // __CARDS_H__
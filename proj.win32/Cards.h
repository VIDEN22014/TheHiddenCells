#pragma once

#ifndef __CARDS_H__
#define __CARDS_H__

#include <proj.win32/GameData.h>
#include "cocos2d.h"
using namespace cocos2d;



class Card {
public:
	Card(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) {
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
	double ScaleCard = 1;
	cocos2d::Sprite* spriteFrame = nullptr;
	cocos2d::Sprite* spriteCard = nullptr;
	cocos2d::Label* labelCard = nullptr;
	position pos();
	virtual int cardInteract();
	virtual void cardOnTurn();
	virtual void moveCard(position vecDirection);
	virtual void deleteCard();
};

class CardHero : public Card {
public:
	CardHero(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene, gameData::amountXPHeros[gameData::chosenHero]) {};
};

class CardCoin : public Card {
public:
	CardCoin(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene) {};
	int cardInteract() override;
};
class CardMonster : public Card {
public:
	CardMonster(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene) {};
	//int cardInteract() override;
};

class CardTeasure : public Card {
public:
	bool goodTreasure;
	CardTeasure(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos, spriteCardPath, spriteFramePath, scene) {};
	//int cardInteract() override;
};
class CardGoodTreasure :public CardTeasure {
public:
	CardGoodTreasure(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardTeasure(cardpos, spriteCardPath, spriteFramePath, scene) { this->goodTreasure = true; };
};
class CardBadTreasure :public CardTeasure {
public:
	CardBadTreasure(position cardpos, std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) :CardTeasure(cardpos, spriteCardPath, spriteFramePath, scene) { this->goodTreasure = false; };
};
#endif // __CARDS_H__
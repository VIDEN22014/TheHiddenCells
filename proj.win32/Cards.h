#pragma once

#ifndef __CARDS_H__
#define __CARDS_H__

#include <proj.win32/GameData.h>
#include "cocos2d.h"
using namespace cocos2d;



class Card {
public:
	Card(position cardpos,std::string spriteCardPath,std::string spriteFramePath,cocos2d::Scene *scene) {
		spriteFrame = cocos2d::Sprite::create(spriteFramePath);
		spriteCard = cocos2d::Sprite::create(spriteCardPath);
		spriteCard->setPosition(Vec2(278 + cardpos.y * (192 + 10),682 - cardpos.x *( 192 + 10)));
		spriteFrame->setPosition(Vec2(278 + cardpos.y * (192 + 10), 682 - cardpos.x *( 192 + 10)));
		scene->addChild(spriteFrame, 1);
		scene->addChild(spriteCard, 2);
	};
	double ScaleCard=1;
	cocos2d::Sprite* spriteFrame = nullptr;
	cocos2d::Sprite* spriteCard = nullptr;
	position pos();
	virtual void moveCard();
	virtual void deleteCard();
};

class CardHero : public Card {
public:
	CardHero(position cardpos,std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene): Card(cardpos,spriteCardPath, spriteFramePath,scene) {};
	void moveCard() override;
};

class CardCoin : public Card {
public:
	CardCoin(position cardpos,std::string spriteCardPath, std::string spriteFramePath, cocos2d::Scene* scene) : Card(cardpos,spriteCardPath, spriteFramePath,scene) {};
	//void moveCard() override;
};
#endif // __CARDS_H__
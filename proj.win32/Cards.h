#pragma once

#ifndef __CARDS_H__
#define __CARDS_H__

#include <proj.win32/GameData.h>
#include "cocos2d.h"




class Card {
public:
	Card() {};
	double ScaleCard=1;
	cocos2d::Sprite* spriteFrame = nullptr;
	cocos2d::Sprite* spriteCard = nullptr;
	position pos();
	virtual void moveCard();
};

class CardHero : public Card {
public:
	CardHero(): Card() {};
	void moveCard() override;
};

class CardCoin : public Card {
public:
	CardCoin() : Card() {};
	//void moveCard() override;
};
#endif // __CARDS_H__
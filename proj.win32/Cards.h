#include "cocos2d.h"
#include <proj.win32/Game.h>


class Card {
public:
	Card() {};
	cocos2d::Sprite* spriteFrame;
	cocos2d::Sprite* spriteCard;
	position pos;
	virtual void moveCard();
};

class CardHero : public Card {
public:
	void moveCard() override;
};
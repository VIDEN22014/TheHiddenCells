#include <proj.win32/Game.h>

USING_NS_CC;

class Card {
public:
	cocos2d::Sprite* spriteFrame = nullptr;
	cocos2d::Sprite* spriteCard = nullptr;
	position pos;
	virtual void moveCard();
};

class CardHero : public Card {
public:
	void moveCard() override;
};

void Card::moveCard() {
	gameData::money = 0;
	return;
}

void CardHero::moveCard(){
	gameData::money += 100;
}
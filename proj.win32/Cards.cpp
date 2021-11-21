#include <proj.win32/Game.h>

USING_NS_CC;

class Card {
public:
	cocos2d::Sprite* spriteFrame = nullptr;
	cocos2d::Sprite* spriteCard = nullptr;
	position pos;
	virtual void moveCard();
};

class CardHero: public Card {
	void moveCard() override {
		gameData::money += 100;
	}
};

void Card::moveCard() {
	gameData::money = 0;
	return;
}
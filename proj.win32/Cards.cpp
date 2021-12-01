#include "cocos2d.h"
#include <proj.win32/Cards.h>
#include <proj.win32/Game.h>
#include <proj.win32/GameData.h>


void Card::moveCard(position vecDirection) {
	spriteCard->runAction(MoveBy::create(1,Vec2(vecDirection.y *(192+10), -vecDirection.x * (192 + 10))));
	spriteFrame->runAction(MoveBy::create(1,Vec2(vecDirection.y *(192+10), -vecDirection.x * (192 + 10))));
}

int Card::cardInteract() {
	return 1;
}

void Card::cardOnTurn() {
}

void Card::deleteCard() {
	if (spriteFrame != nullptr) { spriteFrame->removeFromParent(); }
	if (spriteCard != nullptr) { spriteCard->removeFromParent(); }
	//cardlabel->removeFromParent();

}


int CardCoin::cardInteract() {
	Game::MoneyChange(cardCurrentHP, gameData::currentMoneyLabel);
	gameData::tempMoney += cardCurrentHP;
	return 1;
}
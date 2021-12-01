#include "cocos2d.h"
#include <proj.win32/Cards.h>
#include <proj.win32/GameData.h>


void Card::moveCard() {
	gameData::money = 0;
}

void Card::deleteCard() {
	spriteFrame->removeFromParent();
	spriteCard->removeFromParent();

}

void CardHero::moveCard(){
	gameData::money += 100;
}
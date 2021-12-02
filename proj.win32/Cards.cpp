#include "cocos2d.h"
#include <proj.win32/Cards.h>
#include <proj.win32/Game.h>
#include <proj.win32/GameData.h>


int Card::cardInteract(Card* cards[3][3]) {
	return 1;
}

void Card::cardOnTurn(Card* cards[3][3]) {
	this->labelUpdate(false);
	if (cardBuff == 1)//Regen
	{
		if (cardCurrentHP >= cardMaxHP)
		{
			cardBuff == 0;//None
		}
		else
		{
			cardCurrentHP++;
		}
	}
	if (cardBuff == 2)//Poisoned
	{
		if (cardCurrentHP <= 1)
		{
			cardBuff == 0;//None
		}
		else
		{
			cardCurrentHP--;
		}
	}
}

void Card::deleteCard() {
	if (spriteFrame != nullptr) { spriteFrame->removeFromParent(); }
	if (spriteCard != nullptr) { spriteCard->removeFromParent(); }
	if (labelCard != nullptr) { labelCard->removeFromParent(); }
}

void Card::labelUpdate(bool isHeroLabel) {
	if (isHeroLabel)
	{
		labelCard->setString(std::to_string(cardCurrentHP) + "/" + std::to_string(cardMaxHP));
		return;
	}
	labelCard->setString(std::to_string(cardCurrentHP));
}


int CardCoin::cardInteract(Card* cards[3][3]) {
	Game::MoneyChange(cardCurrentHP, gameData::currentMoneyLabel);
	gameData::tempMoney += cardCurrentHP;
	return 1;
}

void CardHero::cardOnTurn(Card* cards[3][3]) {
	this->labelUpdate(true);
	if (cardCurrentHP > cardMaxHP)//Overheal Decreases
	{
		cardCurrentHP--;
	}
	if (cardBuff == 1)//Regen
	{
		if (cardCurrentHP >= cardMaxHP)
		{
			cardBuff == 0;//None
		}
		else
		{
			cardCurrentHP++;
		}
	}
	if (cardBuff == 2)//Poisoned
	{
		if (cardCurrentHP <= 1)
		{
			cardBuff == 0;//None
		}
		else
		{
			cardCurrentHP--;
		}
	}
}

int CardRedPotion::cardInteract(Card* cards[3][3]) {
	if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardBuff == 2)//Canel Poision
	{
		cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardBuff = 0;
	}
	if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP < cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardMaxHP)
	{
		cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP += cardCurrentHP;
		if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP > cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardMaxHP)
		{
			cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP = cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardMaxHP;
		}
	}
	return 1;
}

int CardGreenPotion::cardInteract(Card* cards[3][3]) {
	cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP--;
	cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardBuff = 2;
	return 1;
}

int CardBluePotion::cardInteract(Card* cards[3][3]) {
	cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardBuff = 1;//Regen
	return 1;
}

int CardYellowPotion::cardInteract(Card* cards[3][3]) {
	if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardBuff == 2)//Canel Poision
	{
		cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardBuff = 0;
	}
	cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP += cardCurrentHP;//Grants Overheal
	return 1;
}
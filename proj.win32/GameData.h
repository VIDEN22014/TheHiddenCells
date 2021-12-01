#pragma once
#include "cocos2d.h"


struct position {
	int x;
	int y;
	position() {
		this->x = 0;
		this->y = 0;
	};
	position(int x, int y) {
		this->x = x;
		this->y = y;
	};
	position operator+(position pos2)
	{
		return position(this->x + pos2.x, this->y + pos2.y);
	}

	position operator-(position pos2)
	{
		return position(this->x - pos2.x, this->y - pos2.y);
	}

};



namespace gameData {
	extern int money;
	extern int tempMoney;
	extern int chosenHero;
	extern int lvlHeart[4];
	extern int lvlAmmo[4];
	extern bool lockHero[4];
	extern int priceHero[4];
	extern int  lastBuyHero;
	extern int priceHeart;
	extern int priceAmmo;
	extern int amountXPHeros[4];
	extern int amountAmmoHeros[4];
	extern position heroPosition;
	extern cocos2d::Scene* currentScene;
	extern int currentLevel;
	extern cocos2d::Label* currentMoneyLabel;
	extern bool isSceneLocked;
}



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
	~position() {};
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
	extern bool FirstStart;
	extern bool playSound;
	extern bool playMusic;
	extern int money;
	extern double tempSpeedMove;
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
	extern cocos2d::Sprite* kickSprite;
	extern int fontSize;
	extern bool isSceneLocked;
	extern bool isbought[4];

	extern std::string pathToWeaponLvl1[4];
	extern int WeaponMaxXPLvl1[4];

	extern std::string pathToMonstersLvl1[7];
	extern std::string pathToMonstersLvl2[7];
	extern std::string pathToMonstersLvl3[7];

	extern int MonstersMaxXPLvl1[8];
	extern int MonstersMaxXPLvl2[8];
	extern int MonstersMaxXPLvl3[8];
	extern int RatioBossMonster;
	extern bool isHeroArmed;
	extern position posBossHpRegen;
	extern bool weaponIsPoisned;
	extern bool weaponIsHeling;
	extern double ScaleCard;

}



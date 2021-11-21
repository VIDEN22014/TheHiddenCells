#include "cocos2d.h"

struct position
{
	//Позиції як в двовимірному масиві
	int x;
	int y;
	position() {}
	position(int X, int Y) {
		x = X;
		y = Y;
	}
};


namespace gameData {
	extern int money;
	extern int changeHero;
	extern int lvlHero[4];
	extern int lvlAmmo[4];
	extern position heroPosition;
}


class Game
{
public:
	static void GoToExit();
	static void GoToMainMenu();
	static void GoToShop();
	static void GoToLevelSelect();
	static void GoToLevel1();
	static void GoToLevel2();
	static void GoToLevel3();
	static void GoToGameScene();
	static void MoneyChange(int moneyDiff, cocos2d::Label* label);
};
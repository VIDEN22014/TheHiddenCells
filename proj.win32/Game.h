#include "cocos2d.h"

namespace gameData {
	extern int money;
	extern int changeHero;
	extern int lvlHero[4];
	extern int lvlAmmo[4];
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



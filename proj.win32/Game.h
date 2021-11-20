#include "cocos2d.h"

namespace gameData {
	extern int money;
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
	static void MoneyChange(int moneyDiff);
	int Game::GetMoney();
};



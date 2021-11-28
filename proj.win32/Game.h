#include "cocos2d.h"

namespace gameData {
	extern int money;
	extern int changeHero;
	extern int lvlHeart[4];
	extern int lvlAmmo[4];
	extern bool lockHero[4];
	extern int priceHero[4];
	extern int  lastBuyHero;
	extern int priceHeart;
	extern int priceAmmo;
	extern int amountXPHeros[4];
	extern int amountAmmoHeros[4];
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
struct position
{
	int x, y;
};
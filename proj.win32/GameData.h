#pragma once
//#include <proj.win32/Cards.h>
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
	//extern Card *itemCards;
}


struct position {
	int x;
	int y;
};
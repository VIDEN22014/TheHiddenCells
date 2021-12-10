#pragma once

#ifndef __GAME_H__
#define __GAME_H__

#include "cocos2d.h"
#include <proj.win32/Cards.h>




class Game
{
public:
	static void GoToExit();
	static void GoToMainMenu();
	static void GoToShop();
	static void GoToInfo();
	static void GoToInfo2();
	static void GoToLevelSelect();
	static void GoToLevel1();
	static void GoToLevel2();
	static void GoToLevel3();
	static void GoToEndGame();
	static void GoToGameScene();
	static void lockScene();
	static void unlockScene();
	static void MoneyChange(int moneyDiff, cocos2d::Label* label);
	static void Turn(position pos, Card* cards[3][3], int level);
	static void CardCreate(position pos, Card* cards[3][3], int level);
	static void Game::CardDelete(Card* card);
};


#endif // __GAME_H__
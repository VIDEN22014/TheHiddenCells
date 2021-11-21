#include <proj.win32/Game.h>
#include <MainMenuScene.h>
#include <proj.win32/ShopScene.h>
#include <proj.win32/LevelSelectScene.h>
#include <proj.win32/Level1Scene.h>
#include <proj.win32/Level2Scene.h>
#include <proj.win32/Level3Scene.h>
#include "GameScene.h"

USING_NS_CC;

namespace gameData {
	int  money = 200;
	int  changeHero = 0; 
	int  lastBuyHero = 0;
	int  lvlHeart[4] = { 0,0,0,0 };
	int  lvlAmmo[4] = { 0,0,0,0 };
	bool lockHero[4] = { true,false,false,false };
	int  priceHero[4] = {0,-150,-300,-350};
	int priceHeart=20;
	int priceAmmo=20;
}

void Game::GoToExit() {
	CCDirector::sharedDirector()->end();
}

void Game::GoToMainMenu() {
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game::GoToShop() {
	auto scene = ShopScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game::GoToLevelSelect() {
	auto scene = LevelSelectScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game::GoToLevel1() {
	auto scene = Level1Scene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game::GoToLevel2() {
	auto scene = Level2Scene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game::GoToLevel3() {
	auto scene = Level3Scene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game::GoToGameScene() {
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game::MoneyChange(int moneyDiff, cocos2d::Label* label) {
	gameData::money += moneyDiff;
	label->setString(std::to_string(gameData::money));
}







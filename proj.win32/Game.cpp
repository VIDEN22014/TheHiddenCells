#include <proj.win32/Game.h>
#include <proj.win32/GameData.h>
#include <MainMenuScene.h>
#include <proj.win32/ShopScene.h>
#include <proj.win32/LevelSelectScene.h>
#include <proj.win32/Level1Scene.h>
#include <proj.win32/Level2Scene.h>
#include <proj.win32/Level3Scene.h>
#include <Math.h>

USING_NS_CC;

void Game::Turn(position pos, Card* cards[3][3], int level) {
	if (abs(pos.x - gameData::heroPosition.x) + abs(pos.y - gameData::heroPosition.y) == 1) {
		
		cards[0][0]->moveCard();

	}
	return;
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



void Game::MoneyChange(int moneyDiff, cocos2d::Label* label) {
	gameData::money += moneyDiff;
	label->setString(std::to_string(gameData::money));
}







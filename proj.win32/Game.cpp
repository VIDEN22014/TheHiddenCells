#include <proj.win32/Game.h>
#include <proj.win32/GameData.h>
#include <MainMenuScene.h>
#include <proj.win32/ShopScene.h>
#include <proj.win32/LevelSelectScene.h>
#include <proj.win32/Level1Scene.h>
#include <proj.win32/Level2Scene.h>
#include <proj.win32/Level3Scene.h>
#include <proj.win32/GeneratorCard.h>
#include <proj.win32/CardIterator.h>
#include <Math.h>

USING_NS_CC;

void Game::Turn(position pos, Card* cards[3][3], int level) {
	if (abs(pos.x - gameData::heroPosition.x) + abs(pos.y - gameData::heroPosition.y) == 1) {
		if (cards[pos.x][pos.y]->cardInteract() == 1) {
			std::vector<position> cardVector;
			CardIterator cardIterator(gameData::heroPosition, pos);
			Card* tempCard;
			cards[pos.x][pos.y]->deleteCard();


			cardVector.push_back(pos);
			while (cardIterator.hasNext())
			{
				cardVector.push_back(cardIterator.getNext());
			}


			for (int i = 0; i < cardVector.size() - 1; i++)
			{
				cards[cardVector[i].x][cardVector[i].y] = cards[cardVector[i + 1].x][cardVector[i + 1].y];
				cards[cardVector[i].x][cardVector[i].y]->moveCard(position(cardVector[i].x - cardVector[i + 1].x, cardVector[i].y - cardVector[i + 1].y));
			}
			position endPos = cardVector[cardVector.size() - 1];
			cards[endPos.x][endPos.y] = GeneratorCard(1, gameData::currentScene).GenerateRandomCard(*(new position(endPos)));



			/*cards[pos.x][pos.y]->deleteCard();
			cards[pos.x][pos.y] = cards[gameData::heroPosition.x][gameData::heroPosition.y];
			cards[pos.x][pos.y]->moveCard(position(pos.x - gameData::heroPosition.x, pos.y - gameData::heroPosition.y));
			cards[gameData::heroPosition.x][gameData::heroPosition.y] = GeneratorCard(1, gameData::currentScene).GenerateRandomCard(*(new position(gameData::heroPosition.x, gameData::heroPosition.y)));
			gameData::heroPosition = position(pos);*/

			gameData::heroPosition = position(pos);
		}
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







#include <proj.win32/Game.h>
#include <proj.win32/GameData.h>
#include <MainMenuScene.h>
#include <proj.win32/ShopScene.h>
#include <proj.win32/InfoScene.h>
#include <proj.win32/InfoScene2.h>
#include <proj.win32/LevelSelectScene.h>
#include <proj.win32/Level1Scene.h>
#include <proj.win32/Level2Scene.h>
#include <proj.win32/Level3Scene.h>
#include <proj.win32/GeneratorCard.h>
#include <proj.win32/CardIterator.h>
#include<proj.win32/EndGameScene.h>
#include <Math.h>

USING_NS_CC;
void Game::lockScene() {
	gameData::isSceneLocked = true;
}
void Game::unlockScene() {
	gameData::isSceneLocked = false;
}
void Game::Turn(position pos, Card* cards[3][3], int level) {
	int interact = 0;
	if (abs(pos.x - gameData::heroPosition.x) + abs(pos.y - gameData::heroPosition.y) == 1 && !gameData::isSceneLocked) {
		if (gameData::RatioBossMonster != 135) {
			gameData::RatioBossMonster += 9;
		}
		if (cards[pos.x][pos.y]->cardInteract(cards) == 1) {
			//cardOnTurn
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cards[i][j]->cardOnTurn(cards);
				}
			}
			std::vector<position> cardVector;
			CardIterator cardIterator(gameData::heroPosition, pos);

			//Lock Scene
			gameData::isSceneLocked = true;

			//Game::CardDelete(cards[pos.x][pos.y]);
			cards[pos.x][pos.y]->deleteCard();


			cardVector.push_back(pos);
			while (cardIterator.hasNext())
			{
				cardVector.push_back(cardIterator.getNext());
			}


			//Card*[][] Replace
			for (int i = 0; i < cardVector.size() - 1; i++)
			{
				cards[cardVector[i].x][cardVector[i].y] = cards[cardVector[i + 1].x][cardVector[i + 1].y];
			}


			//Creating CallBack Functions
			position endPos = *(new position(cardVector[cardVector.size() - 1]));
			auto FinalCB = CallFunc::create([endPos, cardVector, cards, level]() {
				cards[endPos.x][endPos.y] = GeneratorCard(level, gameData::currentScene).GenerateRandomCard(*(new position(endPos)));
				//Position Normalization
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						cards[i][j]->pos = *(new position(i, j));
					}
				}


				});

			auto unlockCB = CallFunc::create([endPos, cardVector, cards, level]() {
				gameData::isSceneLocked = false;
				});

			//Card Move With Delays
			for (int i = 0; i < cardVector.size() - 1; i++)
			{
				position vecDirection = cardVector[i] - cardVector[i + 1];
				if (i == 0 && gameData::isHeroArmed)
				{
					cards[cardVector[i].x][cardVector[i].y]->spriteWeapon->runAction(Sequence::create(DelayTime::create(i * 0.75), MoveBy::create(gameData::tempSpeedMove, Vec2(vecDirection.y * (192 + 10), -vecDirection.x * (192 + 10)))->clone(), nullptr));
					cards[cardVector[i].x][cardVector[i].y]->labelWeapon->runAction(Sequence::create(DelayTime::create(i * 0.75), MoveBy::create(gameData::tempSpeedMove, Vec2(vecDirection.y * (192 + 10), -vecDirection.x * (192 + 10)))->clone(), nullptr));
				}
				cards[cardVector[i].x][cardVector[i].y]->spriteCard->runAction(Sequence::create(DelayTime::create(i * 0.75), MoveBy::create(gameData::tempSpeedMove, Vec2(vecDirection.y * (192 + 10), -vecDirection.x * (192 + 10)))->clone(), nullptr));
				cards[cardVector[i].x][cardVector[i].y]->spriteFrame->runAction(Sequence::create(DelayTime::create(i * 0.75), MoveBy::create(gameData::tempSpeedMove, Vec2(vecDirection.y * (192 + 10), -vecDirection.x * (192 + 10)))->clone(), nullptr));
				cards[cardVector[i].x][cardVector[i].y]->labelCard->runAction(Sequence::create(DelayTime::create(i * 0.75), MoveBy::create(gameData::tempSpeedMove, Vec2(vecDirection.y * (192 + 10), -vecDirection.x * (192 + 10)))->clone(), nullptr));
				cards[cardVector[i].x][cardVector[i].y]->spriteRegenXP->runAction(Sequence::create(DelayTime::create(i * 0.75), MoveBy::create(gameData::tempSpeedMove, Vec2(vecDirection.y * (192 + 10), -vecDirection.x * (192 + 10)))->clone(), nullptr));
				cards[cardVector[i].x][cardVector[i].y]->spritePoisned->runAction(Sequence::create(DelayTime::create(i * 0.75), MoveBy::create(gameData::tempSpeedMove, Vec2(vecDirection.y * (192 + 10), -vecDirection.x * (192 + 10)))->clone(), nullptr));
				if (i == cardVector.size() - 2)
				{
					cards[cardVector[i].x][cardVector[i].y]->spriteFrame->runAction(Sequence::create(DelayTime::create((i + 1) * 0.75 + 0.15), FinalCB, unlockCB, nullptr));
				}
			}
			gameData::heroPosition = position(pos);
		}
		else
		{
			//Card OnTurn
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cards[i][j]->cardOnTurn(cards);
				}
			}
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
void Game::GoToInfo() {
	auto scene = InfoScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
void Game::GoToInfo2() {
	auto scene = InfoScene2::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game::GoToLevelSelect() {
	gameData::isHeroArmed = false;
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

void Game::GoToEndGame() {
	auto scene = EndGameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game::MoneyChange(int moneyDiff, cocos2d::Label* label) {
	gameData::money += moneyDiff;
	label->setString(std::to_string(gameData::money));
}

void Game::CardDelete(Card* card) {
	delete card;
	return;
}







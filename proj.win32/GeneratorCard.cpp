#include <proj.win32/GeneratorCard.h>

//dddddddddddddddddddddddddddddddddd

Card* GeneratorCard::GenerateHeroCard(position pos) {
	return factory->createHero(pos, this->scene);
};
Card* GeneratorCard::GenerateRandomCard(position pos) {
	int GenerateCard;
	GenerateCard = rand() % 400;
	//while ( GenerateCard >= gameData::generateTypeCard[0] &&  GenerateCard< gameData::generateTypeCard[1]) { GenerateCard = rand() % 18; }
	if (GenerateCard >= 0 && GenerateCard < 100)
	{
		/*gameData::generateTypeCard[0] = 0;
		gameData::generateTypeCard[1] = 2;*/
		return factory->createCoin(pos, this->scene);
	}
	else if (GenerateCard >= 100 && GenerateCard < 400)
	{
		/*	gameData::generateTypeCard[0] = 2;
			gameData::generateTypeCard[1] = 4;*/
		return factory->createBadTreasure(pos, this->scene);
	}
	else if (GenerateCard >= 300 && GenerateCard < 500)
	{
		/*	gameData::generateTypeCard[0] = 2;
			gameData::generateTypeCard[1] = 4;*/
		//return factory->createMonster(pos, this->scene, gameData::pathToMonsters[1]);
		return factory->createGoodTreasure(pos, this->scene);
	}
	else if (GenerateCard >= 500 && GenerateCard < 850)
	{
		/*	gameData::generateTypeCard[0] = 2;
			gameData::generateTypeCard[1] = 4;*/
		return factory->createMonster(pos, this->scene, gameData::pathToMonsters[1]);
	}
	else if (GenerateCard >= 850 && GenerateCard < 1000)
	{
		/*gameData::generateTypeCard[0] = 16;
		gameData::generateTypeCard[1] = 18;*/
		return factory->createPotion(pos, this->scene);
	}
}
//Card* GeneratorCard::GenerateGoodCard(position pos) {};
Card* GeneratorCard::GenerateBadCard(position pos) { 
	int GeneraTeCard;
	srand(time(NULL));
	GeneraTeCard = rand() % 700;
	if (GeneraTeCard >= 0 && GeneraTeCard < 1)
	{
		return factory->createMonster(pos, this->scene, gameData::pathToMonsters[1]);
	}
	else if (GeneraTeCard >= 1 && GeneraTeCard < 200)
	{
		return factory->createMonster(pos, this->scene, gameData::pathToMonsters[0]);
		
	}
	else if (GeneraTeCard >=200 && GeneraTeCard < 300)
	{
		return factory->createMonster(pos, this->scene, gameData::pathToMonsters[2]);
	}
	else if (GeneraTeCard >= 300 && GeneraTeCard < 400)
	{
		return factory->createMonster(pos, this->scene, gameData::pathToMonsters[3]);
	}
	else if (GeneraTeCard >= 400 && GeneraTeCard < 500)
	{
		return factory->createMonster(pos, this->scene, gameData::pathToMonsters[4]);
	}
	else if (GeneraTeCard >= 500 && GeneraTeCard < 600)
	{
		return factory->createMonster(pos, this->scene, gameData::pathToMonsters[5]);
	}
	else if (GeneraTeCard >= 600 && GeneraTeCard < 700)
	{
		return factory->createMonster(pos, this->scene, gameData::pathToMonsters[6]);
	}

};

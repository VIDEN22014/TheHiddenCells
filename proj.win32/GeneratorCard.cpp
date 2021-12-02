#include <proj.win32/GeneratorCard.h>



Card* GeneratorCard::GenerateHeroCard(position pos) {
	return factory->createHero(pos, this->scene);
};
Card* GeneratorCard::GenerateRandomCard(position pos) {
	int generateCard;
	srand(time(NULL));
	generateCard = rand() % 10;
	while (gameData::generateTypeCard == generateCard) { generateCard = rand() % 10; }
	if (generateCard == 0) { gameData::generateTypeCard = generateCard; return factory->createCoin(pos, this->scene); }
	else if (generateCard == 1) { gameData::generateTypeCard = generateCard; return factory->createMonster(pos, this->scene, gameData::pathTosprites[0]); }
	else if (generateCard == 2) { gameData::generateTypeCard = generateCard; return factory->createMonster(pos, this->scene, gameData::pathTosprites[1]); }
	else if (generateCard == 3) { gameData::generateTypeCard = generateCard; return factory->createMonster(pos, this->scene, gameData::pathTosprites[2]); }
	else if (generateCard == 4) { gameData::generateTypeCard = generateCard; return factory->createMonster(pos, this->scene, gameData::pathTosprites[3]); }
	else if (generateCard == 5) { gameData::generateTypeCard = generateCard; return factory->createMonster(pos, this->scene, gameData::pathTosprites[4]); }
	else if (generateCard == 6) { gameData::generateTypeCard = generateCard; return factory->createPotion(pos, this->scene, gameData::pathTosprites[5]); }
	else if (generateCard == 7) { gameData::generateTypeCard = generateCard; return factory->createPotion(pos, this->scene, gameData::pathTosprites[6]); }
	else if (generateCard == 8) { gameData::generateTypeCard = generateCard; return factory->createGoodTreasure(pos, this->scene); }
	else if (generateCard == 9) { gameData::generateTypeCard = generateCard; return factory->createBadTreasure(pos, this->scene); }

	//return factory->createCoin(pos, this->scene);
};
//Card* GeneratorCard::GenerateGoodCard(position pos) {};
//Card* GeneratorCard::GenerateBadCard(position pos) {};

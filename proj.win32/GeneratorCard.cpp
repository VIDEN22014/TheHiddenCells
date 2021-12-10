#include <proj.win32/GeneratorCard.h>



Card* GeneratorCard::GenerateHeroCard(position pos) {
	return factory->createHero(pos, this->scene);
};
Card* GeneratorCard::GenerateRandomCard(position pos) {
	if (gameData::ScaleCard <= 8.125) { gameData::ScaleCard += 0.125; }
	int GenerateCard;
	GenerateCard = rand() % 1000;
	if (GenerateCard >= 0 && GenerateCard < 200)
	{
		return factory->createCoin(pos, this->scene);
	}
	
	else if (GenerateCard >= 200 && GenerateCard < 300)
	{
		return factory->createBadTreasure(pos, this->scene);
	}
	else if (GenerateCard >= 300 && GenerateCard < 400)
	{
		return factory->createGoodTreasure(pos, this->scene);
	}
	else if (GenerateCard >= 400 && GenerateCard < 650)
	{
		return factory->createMonster(pos, this->scene);
	}
	else if (GenerateCard >= 650 && GenerateCard < 750)
	{
		return factory->createPotion(pos, this->scene);
	}
	else if (GenerateCard >= 750 && GenerateCard < 1000)
	{
		return factory->createWeapon(pos, this->scene);
	}
	
}

Card* GeneratorCard::GenerateBadCard(position pos) {
	if (gameData::ScaleCard != 8) { gameData::ScaleCard += 0.125; }
	return factory->createMonster(pos, this->scene);
};

Card* GeneratorCard::GenerateHeroWeapon(position pos) {

	return factory->createHeroWeapon(pos, this->scene);
};


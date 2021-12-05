#include <proj.win32/GeneratorCard.h>

//dddddddddddddddddddddddddddddddddd

Card* GeneratorCard::GenerateHeroCard(position pos) {
	return factory->createHero(pos, this->scene);
};
Card* GeneratorCard::GenerateRandomCard(position pos) {
	int GenerateCard;
	GenerateCard = rand() % 751;
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
}
//Card* GeneratorCard::GenerateGoodCard(position pos) {};
Card* GeneratorCard::GenerateBadCard(position pos) { 
	return factory->createMonster(pos, this->scene);
	

};

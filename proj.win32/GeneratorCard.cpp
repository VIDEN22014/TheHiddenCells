#include <proj.win32/GeneratorCard.h>

	


Card* GeneratorCard::GenerateHeroCard(position pos) {
	return factory->createHero(pos,this->scene);
 };
Card* GeneratorCard::GenerateRandomCard(position pos) {
	return factory->createCoin(pos, this->scene);
};
//Card* GeneratorCard::GenerateGoodCard(position pos) {};
//Card* GeneratorCard::GenerateBadCard(position pos) {};

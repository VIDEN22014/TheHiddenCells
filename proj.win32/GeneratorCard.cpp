#include <proj.win32/GeneratorCard.h>

	


Card* GeneratorCard::GenerateHeroCard(position pos) {
		factory->createHero(pos,this->scene);
    };
Card* GeneratorCard::GenerateRandomCard(position pos) {
	factory->createCoin(pos, this->scene);
};
//Card* GeneratorCard::GenerateGoodCard(position pos) {};
//Card* GeneratorCard::GenerateBadCard(position pos) {};

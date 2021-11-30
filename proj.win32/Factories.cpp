#include <proj.win32/Factories.h>


Card* AbstractFactory::createMonster(position pos) {
	return new Card();
}
Card* Level1Factory::createHero(position pos) {
	return new CardHero();
}
Card* AbstractFactory::createCoin(position pos) {
	return new CardCoin();
}



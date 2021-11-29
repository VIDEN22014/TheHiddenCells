#include <proj.win32/Factories.h>


Card* Level1Factory::createMonster(position pos) {
	gameData::money += 100;
	return new Card();
}





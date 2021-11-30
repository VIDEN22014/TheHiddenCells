#include "cocos2d.h"
#include <proj.win32/Game.h>
#include <proj.win32/Cards.h>
#include <proj.win32/Factories.h>

class CardGenerator {
public:
	CardGenerator(int lvl) {};
	AbstractFactory*  Frame;

	Card* GenerateRandomCard(position pos) {};
	Card* GenerateGoodCard(position pos) {};
	Card* GenerateBadCard(position pos) {};

};

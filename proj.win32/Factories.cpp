#include <proj.win32/Factories.h>


USING_NS_CC;

class AbstractFactory
{
public:
	virtual Card* createHero(position pos);
	virtual Card* createCoin(position pos);
	virtual Card* createMonster(position pos);
};

class Level1Factory : public AbstractFactory {
public:
	Card* createMonster(position pos) override;
};

Card* Level1Factory::createMonster(position pos) {
	gameData::money += 100;
}





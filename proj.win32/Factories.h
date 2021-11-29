#include "cocos2d.h"
#include <proj.win32/Cards.h>
#include <proj.win32/Game.h>



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

#pragma once

#ifndef __FACTORIES_H__
#define __FACTORIES_H__

#include <proj.win32/Cards.h>



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

#endif // __FACTORIES_H__

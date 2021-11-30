#pragma once

#ifndef __FACTORIES_H__
#define __FACTORIES_H__

#include <proj.win32/Cards.h>



class AbstractFactory
{
public:
	virtual Card* createHero(position pos,cocos2d::Scene*scene);
	virtual Card* createCoin(position pos, cocos2d::Scene* scene);
	virtual Card* createMonster(position pos, cocos2d::Scene* scene);
};

class Level1Factory : public AbstractFactory {
public:
	Card* createMonster(position pos, cocos2d::Scene* scene) override;
};

#endif // __FACTORIES_H__

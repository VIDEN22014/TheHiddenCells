#pragma once

#ifndef __FACTORIES_H__
#define __FACTORIES_H__

#include <proj.win32/Cards.h>
//#include <proj.win32/GameData.h>


class AbstractFactory
{
public:
	std::string spriteFramePath = "Assets/Cards/squareGoldenFrame.png";
	virtual Card* createHero(position pos, cocos2d::Scene* scene);
	virtual Card* createCoin(position pos, cocos2d::Scene* scene);
	virtual Card* createMonster(position pos, cocos2d::Scene* scene);
	virtual Card* createPotion(position pos, cocos2d::Scene* scene);
	virtual Card* createWeapon(position pos, cocos2d::Scene* scene);
	virtual Card* createGoodTreasure(position pos, cocos2d::Scene* scene);
	virtual Card* createBadTreasure(position pos, cocos2d::Scene* scene);
	virtual Card* createHeroWeapon(position pos, cocos2d::Scene* scene);
};

class Level1Factory : public AbstractFactory {
public:
	Card* createMonster(position pos, cocos2d::Scene* scene) override;
};
class Level2Factory : public AbstractFactory {
public:
	Card* createMonster(position pos, cocos2d::Scene* scene) override;
};
class Level3Factory : public AbstractFactory {
public:
	Card* createMonster(position pos, cocos2d::Scene* scene) override;
};
#endif // __FACTORIES_H__

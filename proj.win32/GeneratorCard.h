#pragma once
#ifndef __GENERTOR_GARD_H__
#define __GENERTOR_GARD_H__

#include "cocos2d.h"
#include <proj.win32/Factories.h>




class GeneratorCard{
	
public:
	AbstractFactory* factory;
	cocos2d::Scene* scene;
	GeneratorCard(int lvl, cocos2d::Scene* scene) {
		if (lvl == 1) { factory = new Level1Factory(); }
		else if (lvl == 2) { factory = new Level2Factory(); }
		else if (lvl == 3) { factory = new Level3Factory(); }
		this->scene = scene;
	};
	

	Card* GenerateHeroCard(position pos);
	Card* GenerateRandomCard(position pos);
	Card* GenerateBadCard(position pos);
	Card* GenerateHeroWeapon(position pos);

	
	
};
#endif // __CARDS_H__
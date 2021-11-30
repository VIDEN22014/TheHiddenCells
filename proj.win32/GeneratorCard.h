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
		if (lvl == 1) { AbstractFactory* factory = new Level1Factory(); }
		this->scene = scene;
	};

	Card* GenerateHeroCard(position pos);
	Card* GenerateRandomCard(position pos);
	Card* GenerateGoodCard(position pos);
	Card* GenerateBadCard(position pos);
	
	
};
#endif // __CARDS_H__
#pragma once

#ifndef __CARD_ITERATOR_H__
#define __CARD_ITERATOR_H__

#include "cocos2d.h"

#include <proj.win32/GameData.h>
#include <proj.win32/Cards.h>
#include <Math.h>

using namespace cocos2d;



class CardIterator {
private:
	int iterationsLinesCount;
	int iterationsCount;
public:
	position iteratorPreviousPosition;
	position iteratorPosition;
	position iterationVec;
	bool isLeftRight;
	CardIterator(position oldHeroPos, position destination) {
		this->iteratorPosition = *(new position(destination));
		this->iterationVec = *(new position(oldHeroPos - destination));
		this->isLeftRight=(abs((oldHeroPos - destination).y)==1);
		iterationsCount = 0;
		iterationsLinesCount = 0;
	};
	bool hasNext();
	position getNext();
};

#endif // __CARD_ITERATOR_H__
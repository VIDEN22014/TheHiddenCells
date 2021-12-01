#include "cocos2d.h"

#include <proj.win32/CardIterator.h>
#include <proj.win32/Game.h>
#include <proj.win32/GameData.h>


bool CardIterator::hasNext() {


	if ((iteratorPosition + iterationVec).x < 0 || (iteratorPosition + iterationVec).y < 0 || (iteratorPosition + iterationVec).x > 2 || (iteratorPosition + iterationVec).y > 2)
	{
		if (iterationsCount == 1 && isLeftRight)
		{
			if (iteratorPosition.x == 0)
			{
				iterationVec = position(1, 0);//DOWN
			}
			else
			{
				iterationVec = position(-1, 0);//UP
			}
			return true;
		}
		return false;
	}
	return true;
}

position CardIterator::getNext() {
	iterationsLinesCount++;
	iteratorPreviousPosition = iteratorPosition;
	iteratorPosition = iteratorPosition + iterationVec;
	iterationsCount++;
	return iteratorPosition;

}

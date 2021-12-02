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
		else if ((iterationsCount == 1 && !isLeftRight))
		{
			if (iteratorPosition.y == 0 || (iteratorPosition.x == 2 && iteratorPosition.y == 1))
			{
				iterationVec = position(0, 1);//RIGHT
			}
			else
			{
				iterationVec = position(0, -1);//LEFT
			}
			return true;
		}
		return false;
	}
	return true;
}

position CardIterator::getNext() {
	iteratorPosition = iteratorPosition + iterationVec;
	iterationsCount++;
	return iteratorPosition;

}

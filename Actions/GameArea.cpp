#include "..\ApplicationManager.h"
#include "GameArea.h"

#include <random>
#include <assert.h>
GameArea::GameArea(ApplicationManager* pApp, CFigure** figs, const int size, ActionType& actionAfterPlay)
	:
	GameAction(pApp, figs, size, actionAfterPlay)
{
	assert(size > 0);
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 1);//2 area types are allowed(largest , smallest)
	do
	{
		int randomNumber = dist(rng);
		switch (randomNumber)
		{
		case 0:
			areaType = TYPE_LARGEST;
			gameLable = "The Largest Area in the";
				break;
		case 1:
			areaType = TYPE_SMALLEST;
			gameLable = "The smallest Area in the";
		default:
			break;
		}
	} while (isGameOver());
}

bool GameArea::isRightChoise(CFigure* fig) const
{
	if (areaType == TYPE_LARGEST)
		return pManager->isLargestArea(fig);
	else
		return pManager->isSmallestArea(fig);
}

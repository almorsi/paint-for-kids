#include <assert.h>

#include "GameArea.h"

#include "..\ApplicationManager.h"


GameArea::GameArea(ApplicationManager* pApp, CFigure** figs, const int size, ActionType& actionAfterPlay)
	:
	GameAction(pApp, figs, size, actionAfterPlay)
{
	assert(size > 0);
	std::uniform_int_distribution<int> dist(0, 1);//2 area types are allowed(largest , smallest)

	//always there is a right choise, unless there is no figures drawn
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

}

bool GameArea::isRightChoise(CFigure* fig) const
{
	if (areaType == TYPE_LARGEST)
		return pManager->isLargestArea(fig);
	else//TYPE_SMALLEST
		return pManager->isSmallestArea(fig);
}

GameArea::~GameArea()
{
	pManager->GetOutput()->UnhighlightItem(ITM_AREA);
}

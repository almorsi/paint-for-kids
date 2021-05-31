#include "Move.h"
#include "..\ApplicationManager.h"
#include <assert.h>

Move::Move(ApplicationManager* pApp, CFigure** selectedFigures, CFigure* firstSelected)
	:
	Action(pApp),
	figuresToMove(selectedFigures),
	firstSelectedFig(firstSelected)
{
	newPointClicked = { 0,0 };//it will be updated in read action 
	increamentalVec = { 0.0f, 0.0f };//it will be updated in read action
}

void Move::ReadActionParameters()
{
	assert(firstSelectedFig != NULL);//to send and error if it is null accedantly
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on a Point to move to");//ask the user to click on the destaintation point

	pIn->GetPointClicked(newPointClicked);//getting the destatnation point

	//do some linear algebra to calculate the incremental vec
	Vec2 newPClic = { newPointClicked.x, newPointClicked.y };
	Vec2 criticPoint = { firstSelectedFig->getCriticalPoint().x,
						firstSelectedFig->getCriticalPoint().y };

	increamentalVec = (newPClic - criticPoint).GetNormalized() * (newPClic - criticPoint).GetLength();
	//

	pOut->drawCleanStatusBar();
}

void Move::Execute()
{
	ReadActionParameters();

	firstSelectedFig->Move(newPointClicked);//move the first figure to the newPoint

	//move each figure other than the first one by the incremental vec
	for (int i = 0; i < pManager->getFigCount(); i++)
	{
		if (figuresToMove[i] != firstSelectedFig && figuresToMove[i] != NULL)
		{
			figuresToMove[i]->moveBy(increamentalVec);
		}
	}
	//
}

Move::~Move()
{
	//no new no delete
}

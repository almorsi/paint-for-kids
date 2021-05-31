#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class Move : public Action
{
private:
	CFigure** figuresToMove; // pointer to the selected figures

	CFigure* firstSelectedFig;//pointer to the first selected figure

	Point newPointClicked;//the destination point

	Vec2 increamentalVec;//the relative incremental amount that each figure other than the first one should move by

	const int nToMove;// number of figures to move

public:
	Move(ApplicationManager* pApp, CFigure** selectedFigures, const int size, CFigure* firstSelected);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual ~Move();
};

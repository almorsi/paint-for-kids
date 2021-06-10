#pragma once
#include "..\Action.h"
#include "..\..\Figures\CFigure.h"

/**
* change draw color action,
* if this action is called after select some figures, the action will change the draw color,
* and will also change the default draw color of the upcoming figures.
* if this action is called without selecting figures, it will change the default draw color of the upcoming figures
*/
class ChngDrawClr : public Action
{
private:
	color newColor;//the color chosen by the user
	CFigure** figuresToChangeTheirColor;
	const int nOfFigures;
public:
	ChngDrawClr(ApplicationManager* pApp, CFigure** selectedFigures = NULL, const int size = 0);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};
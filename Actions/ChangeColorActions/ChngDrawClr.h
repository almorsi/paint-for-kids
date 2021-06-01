#pragma once
#include "..\Action.h"
#include "..\..\Figures\CFigure.h"
class ChngDrawClr : public Action
{
private:
	color clrToChng;
	CFigure** figuresToChangeTheirColor;
	const int nOfFigures;
public:
	ChngDrawClr(ApplicationManager* pApp, CFigure** selectedFigures = NULL, const int size = 0);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};
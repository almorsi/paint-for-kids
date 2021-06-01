#pragma once
#include "..\Action.h"
#include "..\..\Figures\CFigure.h"
class ChngFillClr : public Action
{
private:
	color clrToChng;
	CFigure** figuresToChangeTheirColor;
	const int nOfFigures;
public:
	ChngFillClr(ApplicationManager* pApp, CFigure** selectedFigures = NULL, const int size = 0);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};
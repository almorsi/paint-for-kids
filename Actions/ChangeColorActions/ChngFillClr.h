#pragma once
#include "..\Action.h"
#include "..\..\Figures\CFigure.h"

/**
* change fill color action,
* if this action is called after select some figures, the action will fill them with the color chosen,
* and will also change the default fill color of the upcoming figures.
* if this action is called without selecting figures, it will change the default fill color of the upcoming figures
*/
class ChngFillClr : public Action
{
private:
	color newColor;		//color that the figure will changed to
	CFigure** figuresToChangeTheirColor;
	const int nOfFigures;
public:
	ChngFillClr(ApplicationManager* pApp, CFigure** selectedFigures = NULL, const int size = 0);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	virtual ~ChngFillClr();
};
#pragma once
#include "..\Action.h"

class ChngFillClr : public Action
{
private:
	color clrToChng;
public:
	ChngFillClr(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};
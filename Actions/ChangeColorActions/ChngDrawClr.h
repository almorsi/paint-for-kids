#pragma once
#include "..\Action.h"

class ChngDrawClr : public Action
{
private:
	color clrToChng;
public:
	ChngDrawClr(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};
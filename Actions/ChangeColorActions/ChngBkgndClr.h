#pragma once
#include "..\Action.h"

class ChngBkgndClr : public Action
{
private:
	color newColor;
public:
	ChngBkgndClr(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};
#pragma once
#include "Action.h"

//Add Rectangle Action class
class AddLineAction : public Action
{
private:
	Point P1, P2; //Line start and end
	GfxInfo LineGfxInfo;
public:
	AddLineAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();

};
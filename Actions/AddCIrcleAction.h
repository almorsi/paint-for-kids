#pragma once
#include "Action.h"

//Add Rectangle Action class
class AddCircleAction : public Action
{
private:
	Point P1, P2; //Line start and end
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();

};
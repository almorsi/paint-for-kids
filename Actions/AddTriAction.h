#pragma once
#include "Action.h"

//Add Rectangle Action class
class AddTriAction : public Action
{
private:
	Point P1, P2,P3; //Triangle Corners
	GfxInfo RectGfxInfo;
public:
	AddTriAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};
#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class Select : public Action
{
private:
	ActionType actAfterSelect;
	CFigure* selectedFigures[ApplicationManager::MaxFigCount];
public:
	Select(ApplicationManager* mApp);
	
	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();


};

#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class Delete : public Action
{
private:
	CFigure** figsToDelete;
public:
	Delete(ApplicationManager* pApp, CFigure** selectedFigs);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual ~Delete() {}
};

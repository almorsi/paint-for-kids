#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class Delete : public Action
{
private:

	CFigure** figsToDelete;//the deleted figures

	const int nToDeleted;//number of figures that will be deleted

public:
	Delete(ApplicationManager* pApp, CFigure** selectedFigs, const int size);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual ~Delete();
};

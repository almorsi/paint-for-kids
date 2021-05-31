#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\Input.h"

class Resize : public Action
{
private:
	CFigure** figsToResize;//the deleted figures
	const int nToResize;//number of figures that will be deleted
	float rsize;//the ratio to resize taken from the user
public:
	Resize(ApplicationManager* pApp, CFigure** selectedFigs, const int size);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual ~Resize() {}
};
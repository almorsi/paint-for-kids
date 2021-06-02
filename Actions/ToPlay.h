#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class ToPlay : public Action
{
private:
	CFigure** figuresDrawn;
	const int nOfFiguresDrawn;
	ActionType playAction;
	ActionType actionAfterPlay;

private:
	bool isOperationalAction(ActionType act) const;
	void doPlayAction(ActionType act);
public:
	ToPlay(ApplicationManager* pApp, CFigure** figsDrawn = NULL, const int size = 0);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	
	virtual ~ToPlay();
};

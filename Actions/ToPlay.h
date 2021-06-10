#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class ToPlay : public Action
{
private:

	CFigure** figuresDrawn;//pointer to the figure currently drawn 

	const int nOfFiguresDrawn;//number of figure drawn

	ActionType playAction;//game mode choosen by the user

	ActionType actionAfterPlay;//action after completing the game

private:

	bool isOperationalAction(ActionType act) const;//to check if it is a valid operational action

	void doPlayAction(ActionType act);//execute the game according to the game mode chosen by the user

public:

	//constructor
	ToPlay(ApplicationManager* pApp, CFigure** figsDrawn = NULL, const int size = 0);

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual ~ToPlay();
};

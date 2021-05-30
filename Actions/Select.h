#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class Select : public Action
{
private:
	ActionType actAfterSelect;
	CFigure** selectedFigures; // array of selected figures that maps the figList in appManager 
	int selectedFigCount;	//count of figure selected

private:
	CFigure* getThatFigure() const; //getting the only figure that is selected "gauranteed that is one figure selected"

	void executeActionAfterSelect(ActionType);

public:
	Select(ApplicationManager* mApp);
	
	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();



	virtual ~Select();

};

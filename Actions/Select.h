#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class Select : public Action
{
private:

	CFigure** selectedFigures; // array of selected figures

	int selectedFigCount;	//count of the selected figure, updated after each select

	CFigure* firstSelectedFigure;//pointer to the first selected figure

	int* numberedClicked;//array to assign a number to the selected figure, this is used to get the first selected

	int countClicked;//to count the cllick on the figure

	bool* isSelectedArr;//array of boolean to that maps the figList (true if selected , false otherwise)

	const int nCurrentlyDrawn;//the number of currently drawn figures in the drawing area

	ActionType actAfterSelect;//action afer select

	ActionType actBeforePaste;//action before paste

private:

	CFigure* getThatFigure() const; //getting the only figure that is selected "gauranteed there is one figure selected"

	void executeActionAfterSelect(ActionType);//exectueing the action after select

	int getIndexOfFirstSelected() const;//get the first figure selected 

public:
	Select(ApplicationManager* mApp);
	
	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();


	virtual ~Select();
};

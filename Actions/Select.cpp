#include "Select.h"
#include "..\GUI\Output.h"

Select::Select(ApplicationManager* mApp)
	:
	Action(mApp)
{
	for (int i = 0; i < ApplicationManager::MaxFigCount; i++)
		selectedFigures[i] = NULL;
	actAfterSelect = EMPTY;
}

void Select::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Point pointClicked;
	//first make sure the action after select is a click in the drawing area to reduce the checks in GetFigure
	do
	{
		pOut->PrintMessage("Please select a figure");
		actAfterSelect = pManager->GetUserAction(pointClicked);
	} while (actAfterSelect != DRAWING_AREA);
	pOut->drawCleanStatusBar();

	do
	{
		CFigure* fig = pManager->GetFigure(pointClicked);
		if (fig != NULL) 
		{
			if (fig->IsSelected())
			{
				fig->SetSelected(false);
				pOut->drawCleanStatusBar();
			}
			else
			{
				fig->SetSelected(true);
				fig->PrintInfo(pOut);
			}
			pManager->UpdateInterface();
		}
		actAfterSelect = pManager->GetUserAction(pointClicked);
	} while (actAfterSelect == DRAWING_AREA);
	pOut->drawCleanStatusBar();
}

void Select::Execute()
{
	ReadActionParameters();
}

#include "Select.h"
#include "..\GUI\Output.h"
#include "Delete.h"

Select::Select(ApplicationManager* mApp)
	:
	Action(mApp)
{
	selectedFigures = new CFigure* [pManager->getFigCount()]();//initialize them to NULL
	actAfterSelect = EMPTY;
	selectedFigCount = 0;
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

	//getting the figures selected by the user and add them to array of figures
	do
	{
		//getting the figure clicked by the user from this and the above loop we gaurantee that click is on the drawing area
		CFigure* fig = pManager->GetFigure(pointClicked); 

		if (fig != NULL) 
		{
			if (fig->IsSelected())
			{
				//unselect because it is already selected and NULL it in the array
				selectedFigCount--;
				fig->SetSelected(false);
				selectedFigures[pManager->getIndexOf(fig)] = NULL;
			}
			else	//not selected
			{
				//select figure and add it to the selected array
				selectedFigCount++;
				fig->SetSelected(true);
				selectedFigures[pManager->getIndexOf(fig)] = fig;
			}
			pManager->UpdateInterface();
		}

		if (selectedFigCount > 1)
			pOut->PrintMessage("number of figures = " + std::to_string(selectedFigCount));
		else if(selectedFigCount == 1)//one figure selected
			getThatFigure()->PrintInfo(pOut);
		else //no figure selected
			pOut->PrintMessage("Please select a figure");

		//getting the action after selecting the figure if it is another click on the drawing area adding the figure the selected figure
		actAfterSelect = pManager->GetUserAction(pointClicked);
	} while (actAfterSelect == DRAWING_AREA);

	pOut->drawCleanStatusBar();
}

void Select::Execute()
{
	ReadActionParameters();
	executeActionAfterSelect(actAfterSelect);
}

CFigure* Select::getThatFigure() const
{
	//guaranteed that is only one figure selected
	//search for it
	for (int i = 0; i < pManager->getFigCount(); i++)
		if (selectedFigures[i] != NULL)
			return selectedFigures[i];

	return NULL;
}

void Select::executeActionAfterSelect(ActionType)
{
	Action* pAct = NULL;

	switch (actAfterSelect)
	{
	case DRAWING_AREA:
		break;
	case STATUS:
		break;
	case EMPTY:
		break;
	case TO_DRAW:
		break;
	case TO_PLAY:
		break;
	case DRAW_LINE:
		break;
	case DRAW_RECT:
		break;
	case DRAW_TRI:
		break;
	case DRAW_CIRC:
		break;
	case CHNG_DRAW_CLR:
		break;
	case CHNG_FILL_CLR:
		break;
	case CHNG_BK_CLR:
		break;
	case SELECT:
		break;
	case DEL:
		pAct = new Delete(pManager, selectedFigures);
		break;
	case MOVE:
		break;
	case RESIZE:
		break;
	case ROTATE:
		break;
	case SEND_BACK:
		break;
	case BRNG_FRNT:
		break;
	case SAVE:
		break;
	case LOAD:
		break;
	case REDO:
		break;
	case UNDO:
		break;
	case RE_PLAY:
		break;
	case SHAPE_ONLY:
		break;
	case CLR_ONLY:
		break;
	case SHAPE_N_CLR:
		break;
	case AREA:
		break;
	case EXIT:
		break;
	default:
		break;
	}
	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}

Select::~Select()
{
	//the action is done, unSelect the figures
	for (int i = 0; i <	selectedFigCount; i++)
		if (selectedFigures[i] != NULL)
			selectedFigures[i]->SetSelected(false);

	//freeing the pointers but not what it point to
	delete[] selectedFigures;
}

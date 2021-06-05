#include "Select.h"
#include "..\GUI\Output.h"
#include "Delete.h"
#include "Move.h"
#include "Copy.h"
#include "Paste.h"
#include "Delete.h"
#include "ChangeColorActions\ChngDrawClr.h"
#include "ChangeColorActions\ChngFillClr.h"
#include "Resize.h"
#include <assert.h>

Select::Select(ApplicationManager* mApp)
	:
	Action(mApp), 
	nCurrentlyDrawn(pManager->getFigCount())
{
	
	selectedFigures = new CFigure* [nCurrentlyDrawn]();//initialize them to NULL

	isSelectedArr = new bool[nCurrentlyDrawn]();//initally to false
	
	//this is neccarry to get the first selected figure
	numberedClicked = new int[nCurrentlyDrawn];
	for (int i = 0; i < nCurrentlyDrawn; i++)
	{
		numberedClicked[i] = -1;
	}

	countClicked = 0;//it will increament each time the user select an unselected figure

	selectedFigCount = 0;//it will increament or decreament each time the user select or unselect a figure

	actAfterSelect = EMPTY;
	actBeforePaste = EMPTY;

	firstSelectedFigure = NULL;
}

void Select::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();//pointer to output 
	Point pointClicked;//the clicked point by the user

	//first make sure the action after select is a click in the drawing area
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
			int indexOfFigureClickedOn = pManager->getIndexOf(fig);
			if (fig->IsSelected())
			{
				//unselect because it is already selected and NULL it in the array
				selectedFigCount--;
				fig->SetSelected(false);
				selectedFigures[indexOfFigureClickedOn] = NULL;
				isSelectedArr[indexOfFigureClickedOn] = false;
			}
			else	//not selected
			{
				//select figure and add it to the selected array
				selectedFigCount++;
				fig->SetSelected(true);
				selectedFigures[indexOfFigureClickedOn] = fig;
				isSelectedArr[indexOfFigureClickedOn] = true;
				numberedClicked[indexOfFigureClickedOn] = countClicked++;
			}
			pManager->UpdateInterface();//to highlight the selected figures
		}

		//print information about the selected figures
		if (selectedFigCount > 1)
			pOut->PrintMessage("number of figures = " + std::to_string(selectedFigCount));
		else if(selectedFigCount == 1)//one figure selected
			getThatFigure()->PrintInfo(pOut);
		else //no figure selected
			pOut->PrintMessage("Please select a figure");
		//

		//getting the action after selecting the figure if it is another click on the drawing area adding the figure to the selected figure
		actAfterSelect = pManager->GetUserAction(pointClicked);

	} while (actAfterSelect == DRAWING_AREA);
	//

	//getting the first selected fig
	if (selectedFigCount > 0)//to ensure that there are figures selected
	{
		firstSelectedFigure = selectedFigures[getIndexOfFirstSelected()];
	}
	//

	//make selectedFigures stored without null pointers between them, this should be the last section in this function
	delete[] selectedFigures;//the first use is to get the firstSelectedFigure, now it will used to store the selected figures
	selectedFigures = new CFigure * [selectedFigCount];
	for (int i = 0, j = 0; i < nCurrentlyDrawn && j < selectedFigCount; i++)
	{
		if (isSelectedArr[i])
		{
			selectedFigures[j] = pManager->GetFigure(i);//return the ith figure in figList
			j++;
		}
	}
	//

	pOut->drawCleanStatusBar();
}

void Select::Execute()
{
	ReadActionParameters();

	//this is required because copy can override cut and vise versa
	while (actAfterSelect == COPY || actAfterSelect == CUT)
	{
		actBeforePaste = actAfterSelect;
		actAfterSelect = pManager->GetUserAction();
	}
	//

	if (selectedFigCount > 0)//must be some selected figure to do action on them
	{
		executeActionAfterSelect(actAfterSelect);
	}
}

CFigure* Select::getThatFigure() const
{
	assert(selectedFigCount == 1);
	//guaranteed that is only one figure selected, return it
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
	case CHNG_DRAW_CLR:
		pAct = new ChngDrawClr(pManager, selectedFigures, selectedFigCount);
		break;
	case CHNG_FILL_CLR:
		pAct = new ChngFillClr(pManager, selectedFigures, selectedFigCount);
		break;
	case DEL:
		pAct = new Delete(pManager, selectedFigures, selectedFigCount);
		break;
	case MOVE:
		pAct = new Move(pManager, selectedFigures, selectedFigCount,  firstSelectedFigure);
		break;
	case PASTE:
	{
		if (actBeforePaste == COPY)//select -> copy -> paste -> move 
		{
			//create copy action, and execute it
			Copy* copyAction = new Copy(pManager, selectedFigures, selectedFigCount, firstSelectedFigure);
			copyAction->Execute();

			//create Paste Action, that take its parameters from copy action
			pAct = new Paste(pManager, copyAction->getCopiedFigures(), copyAction->getNOfFigsToCopy(), copyAction->getFirstSelectedCopy());

			//delete copy action
			delete copyAction;
			copyAction = NULL;
		}
		if (actBeforePaste == CUT)//select -> copy -> paste -> move -> delete, or just move them ****
		{
			//create copy action, and execute it
			Copy* copyAction = new Copy(pManager, selectedFigures, selectedFigCount, firstSelectedFigure);
			copyAction->Execute();

			//create Paste Action, that take its parameters from copy action
			pAct = new Paste(pManager, copyAction->getCopiedFigures(), copyAction->getNOfFigsToCopy(), copyAction->getFirstSelectedCopy());

			//delete copy action
			delete copyAction;
			copyAction = NULL;

			//create delete action, to delete the selected figures
			Delete* delAction = new Delete(pManager, selectedFigures, selectedFigCount);
			delAction->Execute();

			//delete delete action :D
			delete delAction;
			delAction = NULL;

			actAfterSelect = DEL;//this to avoide unselect null figures
		}
		break;
	}
	case RESIZE:
		pAct = new Resize(pManager, selectedFigures, selectedFigCount);
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

int Select::getIndexOfFirstSelected() const
{
	//how this is work?
	//each click on a figure will assign countClicked to array numberdClicked and then increment countClicked
	//now numberClicked will map the figures with countClilcked we now search for the minimum number in that maps a figure
	int min = countClicked; //because it is the largest number in the array
	int minIndex = -1;
	for (int i = 0; i < pManager->getFigCount(); i++)
	{
		//getting the index of the minimum number in the array and that is the first figure selected in selectedFigures
		if (numberedClicked[i] < min && selectedFigures[i] != NULL)
		{
			min = numberedClicked[i];
			minIndex = i;
		}
	}
	//

	return minIndex;
}

Select::~Select()
{
	//the action is done, unSelect the figures
	//if the figure is slected it will added to slectedFigures, then if it deleted it will be deleted in FigLists
	//and NULL in both selectedFigures and FigList so unselect it after deleting it makes no sence
	if (actAfterSelect != DEL)
	{
		for (int i = 0; i < selectedFigCount; i++)
				selectedFigures[i]->SetSelected(false);
	}
	//freeing the pointers 
	delete[] selectedFigures;
	delete[] numberedClicked;
	delete[] isSelectedArr;
}

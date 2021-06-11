#include <assert.h>

#include "..\GUI\Output.h"

#include "Select.h"
#include "Delete.h"
#include "Move.h"
#include "Copy.h"
#include "Paste.h"
#include "Delete.h"
#include "ChangeColorActions\ChngDrawClr.h"
#include "ChangeColorActions\ChngFillClr.h"
#include "Resize.h"


Select::Select(ApplicationManager* mApp)
	:
	Action(mApp), 
	nCurrentlyDrawn(pManager->getFigCount())
{
	
	selectedFigures = NULL; //initially to NULL

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

	pOut->PrintMessage("Please select a figure");
	actAfterSelect = pManager->GetUserAction(pointClicked);

	//getting the figures selected by the user and add them to array of figures
	while (actAfterSelect == DRAWING_AREA)
	{
		//getting the figure clicked by the user from this and the above loop we gaurantee that click is on the drawing area
		CFigure* fig = pManager->GetFigure(pointClicked); 

		if (fig != NULL) 
		{
			int indexOfFigureClickedOn = pManager->getIndexOf(fig);
			if (fig->IsSelected())
			{
				//unselect because it is already selected
				selectedFigCount--;
				fig->SetSelected(false);
				isSelectedArr[indexOfFigureClickedOn] = false;
			}
			else//not selected
			{
				//select figure
				selectedFigCount++;
				fig->SetSelected(true);
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


		//getting the action after selecting the figure
		//if it is another click on the drawing area then adding the figure to the selected figure
		actAfterSelect = pManager->GetUserAction(pointClicked);

	}


	//getting the first selected fig
	if (selectedFigCount > 0)//to ensure that there are figures selected
	{
		firstSelectedFigure = pManager->GetFigure(getIndexOfFirstSelected());
	}
	delete[] numberedClicked;//his job is done, after getting the first selected figure
	numberedClicked = NULL;

	//create selected figure array
	selectedFigures = new CFigure* [selectedFigCount]();
	for (int i = 0, j = 0; j < selectedFigCount && i < nCurrentlyDrawn; i++)
	{
		if (isSelectedArr[i])
		{
			selectedFigures[j] = pManager->GetFigure(i);//return the ith figure in figList
			j++;
		}
	}
	delete[] isSelectedArr;//his job is done after creating the selected figure array
	isSelectedArr = NULL;

	pOut->drawCleanStatusBar();
}

void Select::Execute()
{
	ReadActionParameters();
	
	//if the user choose to copy or cut, then enter this loop to get the action before paste
	//this is required because copy can override cut and vise versa
	while (actAfterSelect == COPY || actAfterSelect == CUT)
	{
		if (actAfterSelect == COPY)
		{
			pManager->GetOutput()->highlightItem(ITM_COPY);
			pManager->GetOutput()->UnhighlightItem(ITM_CUT);
			pManager->GetOutput()->drawToolBar();
		}
		else if (actAfterSelect == CUT)
		{
			pManager->GetOutput()->highlightItem(ITM_CUT);
			pManager->GetOutput()->UnhighlightItem(ITM_COPY);
			pManager->GetOutput()->drawToolBar();
		}

		actBeforePaste = actAfterSelect;
		actAfterSelect = pManager->GetUserAction();
	}

	//executing action after select
	if (selectedFigCount > 0)
	{
		executeActionAfterSelect(actAfterSelect);
	}
}

CFigure* Select::getThatFigure() const
{
	assert(selectedFigCount == 1);
	//guaranteed that is only one figure selected, return it
	for (int i = 0; i < nCurrentlyDrawn; i++)
		if (isSelectedArr[i])
			return pManager->GetFigure(i);

	return NULL;
}

void Select::executeActionAfterSelect(ActionType)
{
	Action* pAct = NULL;

	switch (actAfterSelect)
	{
	case CHNG_DRAW_CLR:
		pManager->GetOutput()->highlightItem(ITM_DRAW_CLR);
		pManager->GetOutput()->drawToolBar();
		pAct = new ChngDrawClr(pManager, selectedFigures, selectedFigCount);
		break;
	case CHNG_FILL_CLR:
		pManager->GetOutput()->highlightItem(ITM_FILL_CLR);
		pManager->GetOutput()->drawToolBar();
		pAct = new ChngFillClr(pManager, selectedFigures, selectedFigCount);
		break;
	case DEL:
		pManager->GetOutput()->highlightItem(ITM_DEL);
		pManager->GetOutput()->drawToolBar();
		pAct = new Delete(pManager, selectedFigures, selectedFigCount);
		break;
	case MOVE:
		pManager->GetOutput()->highlightItem(ITM_MOVE);
		pManager->GetOutput()->drawToolBar();
		pAct = new Move(pManager, selectedFigures, selectedFigCount,  firstSelectedFigure);
		break;
	case PASTE:
	{
		pManager->GetOutput()->highlightItem(ITM_PASTE);
		pManager->GetOutput()->drawToolBar();

		if (actBeforePaste == COPY)//select -> copy -> paste -> move 
		{
			//create copy action, and execute it
			Copy* copyAction = new Copy(pManager, selectedFigures, selectedFigCount, firstSelectedFigure);
			copyAction->Execute();
			pManager->GetOutput()->UnhighlightItem(ITM_COPY);
			pManager->GetOutput()->drawToolBar();

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

			//create delete action, to delete the cutted figures
			Delete* delAction = new Delete(pManager, selectedFigures, selectedFigCount);
			delAction->Execute();

			//delete delete action :D
			delete delAction;
			delAction = NULL;

			pManager->GetOutput()->UnhighlightItem(ITM_CUT);
			pManager->GetOutput()->drawToolBar();

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
	//searching for the min number in numberClicked and in the same time the figure must be selected
	int min = countClicked; //because it is the largest number in the array
	int minIndex = -1;
	for (int i = 0; i < nCurrentlyDrawn; i++)
	{
		//getting the index of the minimum number in the array and that is the first figure selected in selectedFigures
		if (isSelectedArr[i] && numberedClicked[i] < min)
		{
			min = numberedClicked[i];
			minIndex = i;
		}
	}

	//return the index of the first one selected, that is the first one is the one with min number in numberdClicked
	return minIndex;
}

Select::~Select()
{
	//the action is done, unSelect the figures

	//if the figure is slected it will added to slectedFigures, then if it is deleted it will be deleted in FigLists
	//and NULL in both selectedFigures and FigList so unselect it after deleting it makes no sence
	if (actAfterSelect != DEL)
	{
		for (int i = 0; i < selectedFigCount; i++)
				selectedFigures[i]->SetSelected(false);
	}

	//freeing the pointers 
	delete[] selectedFigures;
	selectedFigures = NULL;

	pManager->GetOutput()->UnhighlightItem(ITM_SELECT);
	pManager->GetOutput()->UnhighlightItem(ITM_COPY);//this because the user can cancel this operation without pasting
	pManager->GetOutput()->UnhighlightItem(ITM_CUT);//this because the user can cancel this operation without pasting
}

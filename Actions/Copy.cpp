#include "Copy.h"
#include "..\ApplicationManager.h"
#include <assert.h>
Copy::Copy(ApplicationManager* pApp, CFigure** selectedFigs, const int size, CFigure* firstFigure)
	:
	Action(pApp),
	selectedFigures(selectedFigs),
	firstSelectedFig(firstFigure), 
	nOfFigsToCopy(size)
{
	assert(nOfFigsToCopy > 0);//make sure there are figures to be copied
	copiedFigures = new CFigure * [nOfFigsToCopy]();//initially to NULL
	copyOfFirstSelectedFigure = NULL;//initially to NULL
}

void Copy::ReadActionParameters()
{
	
	copyOfFirstSelectedFigure = firstSelectedFig->getCopy();//getting a copy of the first selected figure

	for (int i = 0; i < nOfFigsToCopy; i++)
	{
		//assiging a copy to copiedFigures if it is not the first copied
		if (selectedFigures[i] != firstSelectedFig)
		{
			copiedFigures[i] = selectedFigures[i]->getCopy();
		}
		else //is firstSelectdFig
		{
			copiedFigures[i] = copyOfFirstSelectedFigure;
		}
	}
}

void Copy::Execute()
{
	ReadActionParameters();
	//now the copied figures are ready to be passed to paste action consturctor
}

CFigure** Copy::getCopiedFigures() const
{
	return copiedFigures;
}

CFigure* Copy::getFirstSelectedCopy() const
{
	return copyOfFirstSelectedFigure;
}

int Copy::getNOfFigsToCopy() const
{
	return nOfFigsToCopy;
}

Copy::~Copy()
{
	//must to not delete the copied figures becaue they will be passed to ApplicationManager::FigList
	//and appManager will take care of delteing them
}



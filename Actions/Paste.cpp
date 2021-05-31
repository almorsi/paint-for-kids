#include "Paste.h"
#include "..\ApplicationManager.h"
Paste::Paste(ApplicationManager* pApp, CFigure** copiedFigs, const int nCopied, CFigure* firstCopied)
	:
	Action(pApp),
	copiedFigures(copiedFigs),
	firstCopiedfig(firstCopied)
{
	//create move action 
	moveAction = new Move(pApp, copiedFigures, nCopied, firstCopiedfig);
	nOfCopiedFigs = nCopied;//inialize the size
}

void Paste::ReadActionParameters()
{
	//alredy done when moveAction execute it self
}

void Paste::Execute()
{
	//execute move action, getting the destination point from the user and move the copied figures to that destination
	moveAction->Execute();

	//the copied figure is copied when they are selected so the copied one needs to be unselected, then pushing them to figList
	for (int i = 0; i < nOfCopiedFigs; i++)
	{
		copiedFigures[i]->SetSelected(false);
		pManager->AddFigure(copiedFigures[i]);
	}
}
 
Paste::~Paste()
{
	//delete move action
	delete moveAction;
	moveAction = NULL;
}
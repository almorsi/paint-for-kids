#include "Paste.h"
#include "..\ApplicationManager.h"
Paste::Paste(ApplicationManager* pApp, CFigure** copiedFigs, const int nCopied, CFigure* firstCopied)
	:
	Action(pApp),
	copiedFigures(copiedFigs),
	firstCopiedfig(firstCopied),
	nOfCopiedFigs(nCopied)
{
	//create move action 
	moveAction = new Move(pApp, copiedFigures, nCopied, firstCopiedfig);
}

void Paste::ReadActionParameters()
{
	//execute move action, getting the destination point from the user and move the copied figures to that destination
	moveAction->Execute();
}

void Paste::Execute()
{

	ReadActionParameters();

	//the copied figure is copied when they are selected (selected state = true) so the copied one needs to be unselected, then pushing them to figList
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
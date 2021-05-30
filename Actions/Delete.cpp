#include "Delete.h"
#include "..\ApplicationManager.h"
Delete::Delete(ApplicationManager* pApp, CFigure** selectedFigs)
	:
	Action(pApp),
	figsToDelete(selectedFigs)
{
}

void Delete::ReadActionParameters()
{
	//already readed by select action
}

void Delete::Execute()
{
	pManager->deleteFigures(figsToDelete);
}

#include "ChngDrawClr.h"
#include "..\..\ApplicationManager.h"

ChngDrawClr::ChngDrawClr(ApplicationManager* pApp)
	:
	Action(pApp)
{
}

void ChngDrawClr::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	pOut->openClrWin(DRAW);
	pOut->PrintMessage("please choose a color from the window above");
	clrToChng = pOut->getChangedColor();
	pOut->closeClrWin();

	pOut->drawCleanStatusBar();
}

void ChngDrawClr::Execute()
{
	ReadActionParameters();

	UI.DrawColor = clrToChng;
}

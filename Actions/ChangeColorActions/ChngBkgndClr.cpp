#include "ChngBkgndClr.h"
#include "..\..\ApplicationManager.h"

ChngBkgndClr::ChngBkgndClr(ApplicationManager* pApp)
	:
	Action(pApp)
{
}

void ChngBkgndClr::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	pOut->openClrWin(BACKGROUND);
	pOut->PrintMessage("please choose a color from the window above");
	clrToChng = pOut->getChangedColor();
	pOut->closeClrWin();

	pOut->drawCleanStatusBar();
}

void ChngBkgndClr::Execute()
{
	ReadActionParameters();

	UI.BkGrndColor = clrToChng;
}

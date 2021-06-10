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
	newColor = pOut->getChangedColor();
	pOut->closeClrWin();

	pOut->drawCleanStatusBar();
}

void ChngBkgndClr::Execute()
{
	ReadActionParameters();

	UI.BkGrndColor = newColor;//setting the background color to the choosen color
}

ChngBkgndClr::~ChngBkgndClr()
{
	pManager->GetOutput()->UnhighlightItem(ITM_BK_CLR);
}

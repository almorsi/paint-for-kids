#include "ChngFillClr.h"
#include "..\..\ApplicationManager.h"

ChngFillClr::ChngFillClr(ApplicationManager* pApp, CFigure** selectedFigures, const int size)
	:
	Action(pApp),
	figuresToChangeTheirColor(selectedFigures),
	nOfFigures(size)
{
}

void ChngFillClr::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	pOut->openClrWin(FILL);
	pOut->PrintMessage("please choose a color from the window above");
	clrToChng = pOut->getChangedColor();
	pOut->closeClrWin();

	pOut->drawCleanStatusBar();
}

void ChngFillClr::Execute()
{
	ReadActionParameters();

	UI.FillColor = clrToChng;

	for (int i = 0; i < nOfFigures; i++)
	{
		figuresToChangeTheirColor[i]->ChngFillClr(clrToChng);
	}

}

#include "ChngDrawClr.h"
#include "..\..\ApplicationManager.h"

ChngDrawClr::ChngDrawClr(ApplicationManager* pApp, CFigure** selectedFigures, const int size)
	:
	Action(pApp), 
	figuresToChangeTheirColor(selectedFigures), 
	nOfFigures(size)
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

	UI.DrawColor = clrToChng;//request without selecting, for the upComming figures

	if(nOfFigures > 0)//request after select
	{
		for (int i = 0; i < nOfFigures; i++)
		{
			figuresToChangeTheirColor[i]->ChngDrawClr(clrToChng);
		}
	}
}

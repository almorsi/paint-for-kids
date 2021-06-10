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

	pOut->openClrWin(DRAW);//open color window
	pOut->PrintMessage("please choose a color from the window above");
	newColor = pOut->getChangedColor();//getting the color chosen by the user
	pOut->closeClrWin();//close color window

	pOut->drawCleanStatusBar();
}

void ChngDrawClr::Execute()
{
	ReadActionParameters();

	UI.DrawColor = newColor;//request without selecting, for the upComming figures

	//request after select
	for (int i = 0; i < nOfFigures; i++)
	{
		figuresToChangeTheirColor[i]->ChngDrawClr(newColor);
	}
}

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

	pOut->openClrWin(FILL);//open color window
	pOut->PrintMessage("please choose a color from the window above");
	newColor = pOut->getChangedColor();//getting the color chosen by the user
	pOut->closeClrWin();//close color window

	pOut->drawCleanStatusBar();
}

void ChngFillClr::Execute()
{
	ReadActionParameters();

	//change the default fill color
	UI.FillColor = newColor;

	//change fill color of selected figures if there is any
	for (int i = 0; i < nOfFigures; i++)
	{
		figuresToChangeTheirColor[i]->ChngFillClr(newColor);
	}

}

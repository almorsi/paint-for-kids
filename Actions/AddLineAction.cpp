#include "AddLineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at start of the line");

	//Read starting point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	//convert from screen coordinates to world coordinates
	screenToWorld(P1);

	pOut->PrintMessage("New Line: Click at end of the line");

	//Read endong point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	//convert from screen coordinates to world coordinates
	screenToWorld(P2);

	LineGfxInfo.isFilled = false;	//default is not filled
	LineGfxInfo.FillClr = WHITE;	//default to White, to make the colorType notFilled, this is a must
	//get drawing color and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->drawCleanStatusBar();

}

//Execute the action
void AddLineAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Line with the parameters read from the user
	CLine* R = new CLine(P1, P2, LineGfxInfo);

	//Add the Line to the list of figures
	pManager->AddFigure(R);
}

AddLineAction::~AddLineAction()
{
	pManager->GetOutput()->UnhighlightItem(ITM_LINE);
}

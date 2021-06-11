#include "Resize.h"
#include "..\ApplicationManager.h"

Resize::Resize(ApplicationManager* pApp, CFigure** selectedFigs, const int size)
	:
	Action(pApp),
	figsToResize(selectedFigs),
	nToResize(size)
{
	ReadActionParameters();
}

void Resize::ReadActionParameters()
{
	//intializing variables to interact with the toolbar
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//asks the user to input resize ratio
	pOut->PrintMessage(std::string("<< Input resize ratio as a decimal >>"));
	rsize=std::stof( pIn->GetSrting(pOut));
	pOut->drawCleanStatusBar();
}

void Resize::Execute()
{
	//Resize all figures
	for (int i = 0; i < nToResize; i++)
	{
		figsToResize[i]->Resize(rsize);
	}
}

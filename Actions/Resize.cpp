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
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage(std::string("<< Input resize ratio as a decimal >>"));
	rsize=std::stof( pIn->GetSrting(pOut));

}

void Resize::Execute()
{
	for (int i = 0; i < nToResize; i++)
	{
		figsToResize[i]->Resize(rsize);
	}
}

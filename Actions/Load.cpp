#include "Load.h"

Load::Load(ApplicationManager* pApp) :Action(pApp)
{
}
void Load::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage(std::string("<< Input file name here >>"));
	name = pIn->GetSrting(pOut);
	namecsv = (name + ".csv");
	InFile.open(namecsv);
	pOut->drawCleanStatusBar();
}

void Load::Execute()
{
	ReadActionParameters();
	pManager->loadData(InFile);
}

Load::~Load()
{
	InFile.close();
}
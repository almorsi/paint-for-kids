#include "Save.h"
Save::Save(ApplicationManager* pApp) :Action(pApp)
{
}
void Save::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage(std::string("<< Input file name here >>"));
	name = pIn->GetSrting(pOut);
	namecsv = (name + ".csv");
	OutFile.open(namecsv);
	pOut->drawCleanStatusBar();
}

void Save::Execute()
{
	ReadActionParameters();
	pManager->saveData(OutFile);
}

Save::~Save()
{
	OutFile.close();
}


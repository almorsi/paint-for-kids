#include "Save.h"
Save::Save(ApplicationManager* pApp) :Action(pApp)
{
}
void Save::ReadActionParameters()
{
	//intializes variables to interact with toolbar
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//asks user the name of the saved file
	pOut->PrintMessage(std::string("<< Input file name here >>"));
	name = pIn->GetSrting(pOut);
	namecsv = (name + ".csv");

	//opens the file to save data
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
	OutFile.close();//file must be closed excution
}


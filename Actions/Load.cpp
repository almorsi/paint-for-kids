#include "Load.h"

Load::Load(ApplicationManager* pApp) :Action(pApp)
{
}
void Load::ReadActionParameters()
{
	//intializes variables to interact with toolbar
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//asks user for file name to be loaded
	pOut->PrintMessage(std::string("<< Input file name here >>"));
	name = pIn->GetSrting(pOut);
	namecsv = (name + ".csv");

	//open file to be able to read data
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
	InFile.close();//file must be closed after excution
}
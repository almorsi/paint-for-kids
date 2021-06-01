#include "Save.h"
Save::Save(ApplicationManager* pApp) :Action(pApp)
{
}
void Save::ReadActionParameters()
{
	OutFile.open("Save.csv");
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


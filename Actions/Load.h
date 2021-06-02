#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class Load :public Action
{
private:
	ifstream InFile;
	string name; //name of file inputed by the user
	string namecsv; //name of file + .csv
public:
	Load(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~Load();

};

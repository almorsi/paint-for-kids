#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class Save :public Action
{
private:
	ofstream OutFile; //the file that the data will be saved to

	string name; //name of file inputed by the user
	
	string namecsv; //name of file + .csv

public:
	Save(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~Save();

};
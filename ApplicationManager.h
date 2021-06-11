#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> // std::stringstream

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "Figures\CLine.h"
#include "Figures\CRectangle.h"
#include "Figures\CTriangle.h"
#include "Figures\CCircle.h"
#include "GUI\input.h"
#include "GUI\output.h"


//Main class that manages everything in the application.
class ApplicationManager
{
	friend class Select;//to get Access of getFigure functions
public:
	static constexpr int MaxFigCount = 200 ;	//Max no of figures

private:
	static Point point; // this to make GetUserAction take defualt Point

	int FigCount;		//Actual number of figures

	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

private:
	// -- Figures Management Functions
	void reArrangeFigList(int);
	CFigure *GetFigure(int) const; //Search for a figure given an index 
	CFigure*& GetFigure(CFigure*) ; //Search for a figure return it 

public:	

	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction(Point& p = point) const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void saveData(ofstream&);
	void loadData(ifstream&);
	void loadDataFigs(vector<string>&);
	
	// -- Figures Management Functions
	CFigure *GetFigure(Point) const; //Search for a figure given a point inside the figure
	void AddFigure(CFigure*); //Adds a new figure to the FigList
	void deleteFigures(CFigure**,const int); //delete the figures passed
	int FromClrToInt(color);
	color FromIntToClr(int);

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window

	// -- play mode functions
	bool isSmallestArea(CFigure*) const;
	bool isLargestArea(CFigure*) const;

	// -- getters
	int getFigCount() const; //getting the current fig count
	int getIndexOf(CFigure*) const; //getting the index of the passed figure in figList;
};

#endif
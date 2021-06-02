#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"


//Main class that manages everything in the application.
class ApplicationManager
{
	friend class Select;//to get Access of getFigure functions
public:
	static constexpr int MaxFigCount = 200 ;	//Max no of figures
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	static Point point; // this to make GetUserAction take defualt Point

private:
	void reArrangeFigList(int deletedFigs);
	CFigure *GetFigure(Point p) const; //Search for a figure given a point inside the figure
	CFigure *GetFigure(int index) const; //Search for a figure given an index 
	CFigure*& GetFigure(CFigure* fig) ; //Search for a figure return it 
public:	

	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction(Point& p = point) const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	//the array passed must be gauranteed it has the same number of figCount
	void deleteFigures(CFigure** figsArray, const int size); //delete the figures passed
	int getFigCount() const; //getting the current fig count
	int getIndexOf(CFigure* fig) const; //getting the index of the passed figure in figList;
	int FromClrToInt(color c);
	void saveData(ofstream &OutFile);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif
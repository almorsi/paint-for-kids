#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"
#include "ToolBar.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;		//Pointer to the Graphics Window
	ToolBar* toolBar;	//Pointer to the play toolbar
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	Input* CreateInput()  const;		//creates a pointer to the Input object	

	void drawToolBar()  const;			//drawing the toolbar according to the UI.InterfaceMode
	void clearToolBar() const;			//clears the toolbar
	void drawCleanStatusBar() const;	//Clears the status bar
	void ClearDrawArea()  const;		//Clears the drawing area


	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	
	///Make similar functions for drawing all other figures.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;			//get current drwawing color
	color getCrntFillColor() const;			//get current filling color
	int getCrntPenWidth() const;			//get current pen width

	
	~Output();
};

#endif
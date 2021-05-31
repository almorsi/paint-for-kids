#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
static int newID = 0; //used to increments ID's

class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	float area;  
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected


	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual bool isInsideMe(Point p) const = 0;			//check if the point is inside the figure


	//this function should be reImplemented in each subclass to pring the proper information
	virtual void PrintInfo(Output* pOut) const = 0;	//print all figure info on the status bar
	virtual Point getCriticalPoint() const = 0;

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	virtual void Move(Point newPoint) = 0;		//Move the figure
	virtual void moveBy(Vec2 incr) = 0;

	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

};


#endif
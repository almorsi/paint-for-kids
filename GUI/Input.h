#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
	static Point point; //this is used to make getUserAction take a reference to Point
public:
	Input(window *pW);		//Consturctor
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	void GetPointClicked(Point& p = point);
	string GetSrting(Output* pO) const ;	 //Returns a string entered by the user

	ActionType GetUserAction(Point& p = point) const; //Read the user click and map to an action

	~Input();
};

#endif
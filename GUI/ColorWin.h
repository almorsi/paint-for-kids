#pragma once
#include "../CMUgraphicsLib/CMUgraphics.h"
#include "MenuItem.h"
#include "UI_Info.h"

class ColorWin
{
private:

	window* pWin; //pointer to the window

	int menuItemsFileName[CHNG_COLR_ITM_COUNT]; //array of color items , the user will choose from them

	ColorType colorToChange;	//the type of color that will be changed (background, fill, draw)

	struct colorWindInfo	//window information
	{
		int width, height, xBegin, yBegin;
		int menuItemWidth, menuItemHeight;
	} CWI;

private:

	window* createWind();	//return a pointer to the window

	void drawItems();		//draw items in the window

public:

	ColorWin(ColorType clrToChange = BACKGROUND); //non defualt constructor

	color getColorClicked() const;	//return the color that the user choose to change to. 

	~ColorWin();
};
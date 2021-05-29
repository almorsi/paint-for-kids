#include "ColorWin.h"

ColorWin::ColorWin(ColorType clrToChage)
{

	CWI.menuItemWidth = 48;
	CWI.menuItemHeight = 48;

	//these weird constants because the API is also weird 
	//the width and height below BEGINS from the window coordinate not the client coordinate
	CWI.width = CWI.menuItemWidth * (CHNG_COLR_ITM_COUNT/2)  + 15;
	CWI.height = CWI.menuItemHeight * 3 - 32;

	//to make the window below the change color items
	CWI.xBegin = UI.wx + int(UI.width*0.2f);
	CWI.yBegin = UI.wy + int(1.7f * UI.MenuItemHeight);

	colorToChange = clrToChage;

	//Initialize the file names according to their index in the window
	for (int i = 0; i < CHNG_COLR_ITM_COUNT; i++)
		menuItemsFileName[i] = i;

	//create the window
	pWin = createWind();
	pWin->ChangeTitle(std::string("Choose a color"));
	//drawing it
	drawItems();
}

window* ColorWin::createWind()
{
	return new window(CWI.width, CWI.height, CWI.xBegin, CWI.yBegin);
}

void ColorWin::drawItems()
{
	std::string basePath = "images\\MenuItems\\C\\";
	int nCol = CHNG_COLR_ITM_COUNT / 2;
	int nRow = 2;
	
	//initialize the file name by mapping from 2D coordinates to 1D array
	for (int j = 0; j < nRow; j++)
	{
		for (int i = 0; i < nCol; i++)
		{
			std::string currentPath = basePath + std::to_string(menuItemsFileName[i + nCol * j]) + ".jpg";
			pWin->DrawImage(currentPath, i * CWI.menuItemWidth, j * CWI.menuItemHeight, CWI.menuItemWidth, CWI.menuItemHeight);
		}
	}
}

color ColorWin::getColorClicked() const
{
	int x,y;
	pWin->WaitMouseClick(x, y);
	
	//mapping from 2D coordinated to 1D array
	int indexClicked = (x / CWI.menuItemWidth) + (y / CWI.menuItemHeight)*(CHNG_COLR_ITM_COUNT/2);

	switch (indexClicked)
	{
	case ITM_BLACK: return BLACK;
	case ITM_GRAY: return GRAY;
	case ITM_BLUE: return BLUE;
	case ITM_CYAN: return CYAN;
	case ITM_GREEN: return GREEN;
	case ITM_YELLOW: return YELLOW;
	case ITM_BROWN: return BROWN;
	case ITM_ORANGE: return ORANGE;
	case ITM_RED: return RED;
	default: //ITM_CANCEL
	{
		switch (colorToChange)
		{
		case BACKGROUND: return UI.BkGrndColor;
		case DRAW: return UI.DrawColor;
		default /*ITM_FILL*/: return UI.FillColor;
		}
	}
	}
}

ColorWin::~ColorWin()
{
	delete pWin;
}


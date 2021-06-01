#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	drawclr = static_cast <drawColorType>(FromClrToInt(FigGfxInfo.DrawClr));
	fillclr = static_cast<fillColorType>(FromClrToInt(FigGfxInfo.FillClr));

}


void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

int CFigure::FromClrToInt(color c)
{
	if (c.ucBlue == BLACK.ucBlue && c.ucGreen == BLACK.ucGreen && c.ucRed == BLACK.ucRed)
		return 0;
	else if (c.ucBlue == GRAY.ucBlue && c.ucGreen == GRAY.ucGreen && c.ucRed == GRAY.ucRed)
		return 1;
	else if (c.ucBlue == BLUE.ucBlue && c.ucGreen == BLUE.ucGreen && c.ucRed == BLUE.ucRed)
		return 2;
	else if (c.ucBlue == CYAN.ucBlue && c.ucGreen == CYAN.ucGreen && c.ucRed == CYAN.ucRed)
		return 3;
	else if (c.ucBlue == GREEN.ucBlue && c.ucGreen == GREEN.ucGreen && c.ucRed == GREEN.ucRed)
		return 4;
	else if (c.ucBlue == YELLOW.ucBlue && c.ucGreen == YELLOW.ucGreen && c.ucRed == YELLOW.ucRed)
		return 5;
	else if (c.ucBlue == BROWN.ucBlue && c.ucGreen == BROWN.ucGreen && c.ucRed == BROWN.ucRed)
		return 6;
	else if (c.ucBlue == ORANGE.ucBlue && c.ucGreen == ORANGE.ucGreen && c.ucRed == ORANGE.ucRed)
		return 7;
	else if (c.ucBlue == RED.ucBlue && c.ucGreen == RED.ucGreen && c.ucRed == RED.ucRed)
		return 8;
	else
		return 9;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
	drawclr = static_cast <drawColorType>( FromClrToInt(Dclr));
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
	fillclr=static_cast<fillColorType>(FromClrToInt(Fclr));
}


#include "CFigure.h"


CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	ID = 0;
	area = 0.0f;
	center = { 0, 0 };
	Selected = false;
	hidden = false;
	colortype = TYPE_NO_FILL;
	figType = NON;
}


void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::setHidden(bool h)
{
	hidden = h;
}

bool CFigure::isHidden() const
{
	return hidden;
}

bool CFigure::isMyType(FigureType type) const
{
	return type == figType;
}

bool CFigure::isMyFigColorType(FigureColorType figClrType) const
{
	return figClrType == colortype;
}

float CFigure::getArea() const
{
	return area;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr; 
}

void CFigure::ChngFillClr(color Fclr)
{	
	changeColorType(Fclr);
	if (colortype == TYPE_NO_FILL)
	{
		//this check is because that if the user decide to change the fill color and then press cancel putten
		//the issue will be in the first time the user does so, this check will keep the figure unFilled
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = Fclr;
	}
}


void CFigure::changeColorType(color clr)
{
	//see DEFS.h and color.h
	if (clr.operator==(BLACK))
	{
		colortype = TYPE_BLACK;
	}
	else if (clr.operator==(GRAY))
	{
		colortype = TYPE_GRAY;
	}
	else if (clr.operator==(BLUE))
	{
		colortype = TYPE_BLUE;
	}
	else if (clr.operator==(CYAN))
	{
		colortype = TYPE_CYAN;
	}
	else if (clr.operator==(GREEN))
	{
		colortype = TYPE_GREEN;
	}
	else if (clr.operator==(YELLOW))
	{
		colortype = TYPE_YELLOW;
	}
	else if (clr.operator==(BROWN))
	{
		colortype = TYPE_BROWN;
	}
	else if (clr.operator==(ORANGE))
	{
		colortype = TYPE_ORANGE;
	}
	else if (clr.operator==(RED))
	{
		colortype = TYPE_RED;
	}
	else
	{
		colortype = TYPE_NO_FILL;
	}
}
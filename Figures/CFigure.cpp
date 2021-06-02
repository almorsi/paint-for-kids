#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	ID = 0;
	area = 0.0f;
	center = { 0, 0 };
	Selected = false;
	hidden = false;
	figType = NONE;
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

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}


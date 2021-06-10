#include "CFigure.h"


CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	ID = 0;
	area = 0.0f;
	center = { 0, 0 };
	Selected = false;

	//ammar, play mode
	hidden = false;//the figure is not hidden by default
	changeColorType(FigGfxInfo.FillClr);//setting the color type according to fill color, play mode need this

	//mohammed needs
	drawclr = static_cast <drawColorType>(FromClrToInt(FigGfxInfo.DrawClr));
	fillclr = static_cast<fillColorType>(FromClrToInt(FigGfxInfo.FillClr));


}


void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }


void CFigure::moveBy(Vec2 incr)
{
	//moving the critical point by the incremantal vector and then move the whole figure to that new point
	Vec2 newP = Vec2(this->getCriticalPoint().x, this->getCriticalPoint().y) + incr;
	Point newPoint = { int(newP.x), int(newP.y) };
	this->Move(newPoint);
}

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
	drawclr = static_cast <drawColorType>( FromClrToInt(Dclr));
}

void CFigure::ChngFillClr(color Fclr)
{	
	changeColorType(Fclr);
	if (colortype != TYPE_NO_FILL)
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = Fclr;
		fillclr=static_cast<fillColorType>(FromClrToInt(Fclr));
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
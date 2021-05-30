#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	if (P1.x < P2.x)
	{
		Corner1 = P1;
		Corner2 = P2;
	}
	else
	{
		Corner1 = P2;
		Corner2 = P1;
	}
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::isInsideMe(Point p) const
{
	return p.x >= Corner1.x && p.x <= Corner2.x
		&& p.y >= Corner1.y && p.y <= Corner2.y;
}


//this function should be reImplemented to print the proper information
void CRectangle::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage("I'm Selceted");
}

void CRectangle::Move(Point newPoint)
{
	Vec2 cor1 = Vec2(Corner1.x, Corner1.y);
	Vec2 cor2 = Vec2(Corner2.x, Corner2.y);
	Vec2 newP = Vec2(newPoint.x, newPoint.y);
	cor2 += (newP - cor1).GetNormalized() * (newP - cor1).GetLength();
	Corner1 = newPoint;
	Corner2.x = int(cor2.x);
	Corner2.y = int(cor2.y);
}

void CRectangle::moveBy(Vec2 incr)
{
	Vec2 newP = Vec2(Corner1.x, Corner1.y) + incr;
	Point newPoint = { int(newP.x), int(newP.y) };
	Move(newPoint);
}

Point CRectangle::getCriticalPoint() const
{
	return Corner1;
}

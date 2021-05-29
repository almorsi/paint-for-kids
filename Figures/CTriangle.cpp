#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	point1 = P1;
	point2 = P2;
	point3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(point1, point2,point3, FigGfxInfo, Selected);
}
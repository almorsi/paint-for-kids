#include "CLine.h"

CLine::CLine(Point p1, Point p2, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	start = p1;
	finish = p2;
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pOut->DrawLine(start,finish, FigGfxInfo, Selected);
}
bool CLine::isInsideMe(Point p) const { return false; }

 void CLine::PrintInfo(Output* pOut) const
 {
 }
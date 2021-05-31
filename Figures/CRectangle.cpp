#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID = 4400 + newID++;
	area = abs((Corner1.x - Corner2.x) * (Corner1.y - Corner2.y));
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
	pOut->PrintMessage(std::string("<<ID: ")+std::to_string(ID)+" <<Width: "+ std::to_string(std::abs(Corner1.x - Corner2.x))+" <<Height: "+ std::to_string(std::abs(Corner1.y - Corner2.y))+" <<Area: "+ std::to_string(int(area)));
}

#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	point1 = P1;
	point2 = P2;
	point3 = P3;
	area = getArea(point1, point2, point3);
	ID=3300+newID++;
}


float CTriangle::getArea(Point p1, Point p2, Point p3) const
{
	return std::abs(0.5f * (float((p1.x - p2.x) * (p1.y - p3.y)) - float((p1.x - p3.x) * (p1.y - p2.y))));
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a Triangle on the screen	
	pOut->DrawTri(point1, point2,point3, FigGfxInfo, Selected);
}


bool CTriangle::isInsideMe(Point p) const 
{
	float Area1 = getArea(point1,point2,p);
	float Area2 = getArea(point1,point3,p);
	float Area3 = getArea(point2,point3,p);
	float sumArea = Area1 + Area2 + Area3;
	return std::abs(sumArea - area) >= 0.0f && std::abs(sumArea - area) <= 0.1f;
}

void CTriangle::PrintInfo(Output* pOut) const 
{
	pOut->PrintMessage(std::string("<<ID: ")+std::to_string(ID)+" <<Vertices: ( " + std::to_string(point1.x)+", "+ std::to_string(point1.y)+ " ), ( " + std::to_string(point2.x)+ ", " + std::to_string(point2.y)+ " ), ( " + std::to_string(point3.x)+ ", " + std::to_string(point3.y)+" ) <<Area: "+std::to_string(int(area)));
}
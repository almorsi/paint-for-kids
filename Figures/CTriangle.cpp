#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	if (P1.y > P3.y)
	{
		std::swap(P1.y, P3.y);
		std::swap(P1.x, P3.x);
	}
	if (P1.y > P2.y)
	{
		std::swap(P1.y, P2.y);
		std::swap(P1.x, P2.x);
	}
	//Now the smallest element is the 1st one. Just check the 2nd and 3rd
	if (P2.y > P3.y)
	{
		std::swap(P2.y, P3.y);
		std::swap(P2.x, P3.x);
	}
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
	if (FigGfxInfo.isFilled)
	{
		float sumArea = Area1 + Area2 + Area3;
		return std::abs(sumArea - area) >= 0.0f && std::abs(sumArea - area) <= 0.1f;
	}
	else //not filled
	{
		//the point is on triangle if one of the areas approaches zero
		float minArea = min(Area1, min(Area2, Area3));
		//after getting the minArea calculating the ratio of minArea with respect to the other areas
		float areaRatio = (minArea / Area1) + (minArea / Area2) + (minArea / Area3);
		//this ratio must approach one for the point to be on the triangle
		return areaRatio >= 0.9f && areaRatio <= 1.1f;
	}
}


void CTriangle::Move(Point newPoint)
{
	Vec2 v1 = Vec2(point1.x, point1.y);
	Vec2 v2 = Vec2(point2.x, point2.y);
	Vec2 v3 = Vec2(point3.x, point3.y);
	Vec2 newP = Vec2(newPoint.x, newPoint.y);

	Vec2 moveBy = (newP - v1).GetNormalized() * (newP - v1).GetLength();
	v2 += moveBy;
	v3 += moveBy;
	point1 = newPoint;
	point2 = {int(v2.x), int(v2.y)};
	point3 = { int(v3.x), int(v3.y) };
}

void CTriangle::moveBy(Vec2 incr)
{
	Vec2 newP = Vec2(point1.x, point1.y) + incr;
	Point newPoint = { int(newP.x), int(newP.y) };
	Move(newPoint);
}

Point CTriangle::getCriticalPoint() const
{
	return point1;
}

CFigure* CTriangle::getCopy() const
{
	return new CTriangle(point1, point2, point3, FigGfxInfo);
}

void CTriangle::PrintInfo(Output* pOut) const 
{
	pOut->PrintMessage(std::string("<<ID: ")+std::to_string(ID)+" <<Vertices: ( " + std::to_string(point1.x)+", "+ std::to_string(point1.y)+ " ), ( " + std::to_string(point2.x)+ ", " + std::to_string(point2.y)+ " ), ( " + std::to_string(point3.x)+ ", " + std::to_string(point3.y)+" ) <<Area: "+std::to_string(int(area)));
}


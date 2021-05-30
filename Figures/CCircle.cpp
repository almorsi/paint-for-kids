#include "CCircle.h"
#include"..\utilities\Vec2.h"

CCircle::CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	point1 = p1;
	point2 = p2;
	setInfo();

}
void CCircle::setInfo()
{
	Vec2 v1 = Vec2(point1.x, point1.y);
	Vec2 v2 = Vec2(point2.x, point2.y);
	radius = int((v1 - v2).GetLength())/2;
	Vec2 cent = ((v1 - v2) * 0.5f)+v2;
	center.x = int(cent.x);
	center.y = int(cent.y);
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a Circle on the screen	
	pOut->DrawCirc(center, radius, FigGfxInfo, Selected);
}

bool CCircle:: isInsideMe(Point p) const
{
	Vec2 v1 = Vec2(p.x, p.y);
	Vec2 v2 = Vec2(center.x, center.y);
	return (int((v2 - v1).GetLength())) <= radius;
}

void CCircle::PrintInfo(Output* pOut) const{}
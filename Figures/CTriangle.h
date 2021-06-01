#pragma once
#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point point1; //first corner
	Point point2; //second corner
	Point point3; //third corner
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	float getArea(Point p1, Point p2, Point p3)const;
	virtual void Resize(float r);
	virtual void Draw(Output* pOut) const;
	virtual bool isInsideMe(Point p) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void Move(Point newPoint);
	virtual void moveBy(Vec2 incr);
	virtual Point getCriticalPoint() const;
	virtual CFigure* getCopy() const;
};

#pragma once

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point point1; //first of the circle
	Point point2; //last edge of the circle
	Point center;
	int radius;
	void setInfo();
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool isInsideMe(Point p) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void Move(Point newPoint);
	virtual void moveBy(Vec2 incr);
	virtual Point getCriticalPoint() const;
};

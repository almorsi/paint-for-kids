#pragma once


#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point start;
	Point finish;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool isInsideMe(Point p) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void Move(Point newPoint);
	virtual void moveBy(Vec2 incr);
};


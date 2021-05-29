#pragma once

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point point1; //center of the circle
	Point point2; //edge of the circle
	Point center;
	int radius;
	void setInfo();
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

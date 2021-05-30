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
	virtual void Draw(Output* pOut) const;
};

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
};


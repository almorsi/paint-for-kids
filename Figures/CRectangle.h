#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool isInsideMe(Point p) const;
	virtual void PrintInfo(Output* pOut)const;
	virtual void Move(Point newPoint);
	virtual void moveBy(Vec2 incr);
};

#endif
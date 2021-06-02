#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
private:
	bool isOnRect(Point p) const;//check if the point on the border of the rectangle
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle(int ,Point, Point, GfxInfo FigureGfxInfo);
	virtual void Resize(float r);
	virtual void Draw(Output* pOut) const;
	virtual bool isInsideMe(Point p) const;
	virtual void PrintInfo(Output* pOut)const;
	virtual void Move(Point newPoint);
	virtual void moveBy(Vec2 incr);
	virtual Point getCriticalPoint() const;
	virtual CFigure* getCopy() const;
	virtual void Save(ofstream& OutFile);
};

#endif
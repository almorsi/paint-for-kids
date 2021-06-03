#pragma once

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point point1; //first edge of the circle
	Point point2; //last edge of the circle
	int radius;

private:
	void setCenterRadius();//setting the center and the radius of circle

public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;

	//ammmar functions
	virtual bool isInsideMe(Point p) const;
	virtual void Move(Point newPoint);
	virtual Point getCriticalPoint() const;//center is the critical point for Circle
	virtual CFigure* getCopy() const;//return a copy of the current object

	//mohammed functions
	CCircle::CCircle(int ,Point , int , GfxInfo FigureGfxInfo);
	virtual void Save(ofstream& OutFile);
	virtual void PrintInfo(Output* pOut) const;
	virtual void Resize(float r);
};

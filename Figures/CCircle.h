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
	CCircle(Point, Point, GfxInfo);
	virtual void Draw(Output*) const;

	//ammmar functions
	virtual bool isInsideMe(Point) const;
	virtual void Move(Point);
	virtual Point getCriticalPoint() const;//center is the critical point for Circle
	virtual CFigure* getCopy() const;//return a copy of the current object

	
	CCircle(int ,Point , int , GfxInfo);
	virtual void Save(ofstream&);
	virtual void PrintInfo(Output*) const;
	virtual void Resize(float);
};

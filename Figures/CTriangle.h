#pragma once
#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point point1; //first corner
	Point point2; //second corner
	Point point3; //third corner
public:
	CTriangle(Point, Point, Point, GfxInfo);
	virtual void Draw(Output*) const;

	//ammmar functions
	virtual bool isInsideMe(Point) const;
	virtual void Move(Point);
	virtual Point getCriticalPoint() const;//center is the critical point for Circle
	virtual CFigure* getCopy() const;//return a copy of the current object
private:
	float getTriArea(Point p1, Point p2, Point p3)const;//return area of triangle

public:
	//mohammed functions
	CTriangle(int, Point, Point, Point, GfxInfo);
	virtual void Save(ofstream&);
	virtual void PrintInfo(Output*) const;
	virtual void Resize(float);
};

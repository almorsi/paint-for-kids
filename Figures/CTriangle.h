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

	
	virtual bool isInsideMe(Point) const;
	virtual void Move(Point);
	virtual Point getCriticalPoint() const;//center is the critical point for Circle
	virtual CFigure* getCopy() const;//return a copy of the current object
private:
	float getTriArea(Point p1, Point p2, Point p3)const;//return area of triangle

public:
	
	CTriangle(int, Point, Point, Point, GfxInfo);//overloaded constructor used when loading data
	virtual void Save(ofstream&);
	virtual void PrintInfo(Output*) const;
	virtual void Resize(float);
};

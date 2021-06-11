#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point, Point, GfxInfo);
	virtual void Draw(Output*) const;

	
	virtual bool isInsideMe(Point) const;
	virtual void Move(Point);
	virtual Point getCriticalPoint() const;//center is the critical point for Circle
	virtual CFigure* getCopy() const;//return a copy of the current object
private:
	bool isOnRect(Point p) const;//check if the point on the border of the rectangle

public:
	
	CRectangle(int, Point, Point, GfxInfo);//overloaded constructor used when loading data
	virtual void Save(ofstream&);
	virtual void PrintInfo(Output*) const;
	virtual void Resize(float);
};

#endif
#pragma once


#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point start;
	Point finish;
	int length;
public:
	CLine(Point, Point, GfxInfo);
	virtual void Draw(Output*) const;

	//ammmar functions
	virtual bool isInsideMe(Point) const;
	virtual void Move(Point);
	virtual Point getCriticalPoint() const;//center is the critical point for Circle
	virtual CFigure* getCopy() const;//return a copy of the current object
	virtual void ChngFillClr(color Fclr);//changing the fill color of a line means changing its draw color

	
	CLine(int, Point, Point, GfxInfo);//overloaded constructor used when loading data
	virtual void Save(ofstream&);
	virtual void PrintInfo(Output*) const;
	virtual void Resize(float);
};


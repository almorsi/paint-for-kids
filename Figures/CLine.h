#pragma once


#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point start;
	Point finish;
	int length;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void ChngFillClr(color Fclr);	//override this function in Cline only to make the use change the drawing color when he/she change the line fill color
	virtual void Resize(float r);
	virtual void Draw(Output* pOut) const;
	virtual bool isInsideMe(Point p) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void Move(Point newPoint);
	virtual void moveBy(Vec2 incr);
	virtual Point getCriticalPoint() const;
	virtual CFigure* getCopy() const;
	virtual void Save(ofstream& OutFile);
};


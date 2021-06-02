#include "CCircle.h"
#include"..\utilities\Vec2.h"

CCircle::CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{

	figType = TYPE_CIRCLE;

	figtype = CIRCLE;

	point1 = p1;
	point2 = p2;
	setInfo();
	ID = 1100 + newID++;
	area = 3.1415f * radius * radius;
}
CCircle::CCircle(int id,Point p1, int r, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	figType = TYPE_CIRCLE;

	figtype = CIRCLE;

	center = p1;
	radius = r;
	ID = id;
	area = 3.1415f * radius * radius;
}
void CCircle::Resize(float r)
{
	radius = int(float(radius) * r);
}
void CCircle::setInfo()
{
	Vec2 v1 = Vec2(point1.x, point1.y);
	Vec2 v2 = Vec2(point2.x, point2.y);
	radius = int((v1 - v2).GetLength())/2;
	Vec2 cent = ((v1 - v2) * 0.5f)+v2;
	center.x = int(cent.x);
	center.y = int(cent.y);
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a Circle on the screen
	if (!isHidden())
		pOut->DrawCirc(center, radius, FigGfxInfo, Selected);
}

void CCircle::Move(Point newPoint)
{
	//bug fix
	Vec2 incr = Vec2(newPoint.x, newPoint.y) - Vec2(center.x, center.y);
	Vec2 p1 = Vec2(point1.x, point1.y) + incr.GetNormalized() * incr.GetLength();
	Vec2 p2 = Vec2(point2.x, point2.y) + incr.GetNormalized() * incr.GetLength();
	//
	center.x = newPoint.x;
	center.y = newPoint.y;
	point1 = { int(p1.x), int(p1.y) };
	point2 = { int(p2.x), int(p2.y) };
}

void CCircle::moveBy(Vec2 incr)
{
	Vec2 newP = Vec2(center.x, center.y) + incr;
	Point newPoint = {int(newP.x), int(newP.y)};
	Move(newPoint);
}

Point CCircle::getCriticalPoint() const
{
	return center;
}

CFigure* CCircle::getCopy() const
{
	return new CCircle(point1, point2, FigGfxInfo);
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << figtype << "," << ID << "," << center.x << "," << center.y << "," << radius << "," << drawclr << "," << fillclr<<std::endl;
}


bool CCircle::isInsideMe(Point p) const
{
	if (isHidden())
		return false;

	Vec2 v1 = Vec2(p.x, p.y);
	Vec2 v2 = Vec2(center.x, center.y);
	int length = (int((v2 - v1).GetLength()));
	if (FigGfxInfo.isFilled)
	{
		 return float(length)/radius <= 1.0f;
	}
	else //not filled
	{
		//ration of length over radius must approach one
		return float(length)/ radius >= 0.95f && float(length)/radius <= 1.05f;
	}
}

void CCircle::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage(std::string("<<ID: ") + std::to_string(ID) + ">>Center: (" + std::to_string(center.x) + "," + std::to_string(center.y)+") " + ">>Radius: " + std::to_string(radius) + ">>Area: " + std::to_string(int(area)));
}
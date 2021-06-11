#include "CCircle.h"
#include"..\utilities\Vec2.h"

CCircle::CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	
	figType = TYPE_CIRCLE;//ammar, figure type

	point1 = p1;
	point2 = p2;

	setCenterRadius();//setting center and radius using point1, and point2

	ID = 1100 + newID++;

	area = 3.1415f * radius * radius;

	figtype = CIRCLE;//mohammed fig type
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a Circle on the screen
	if (!isHidden())
		pOut->DrawCirc(center, radius, FigGfxInfo, Selected);
}

void CCircle::setCenterRadius()
{
	//using math in Vec2 to get the center between point1, point2
	Vec2 vPoint1 = Vec2(point1.x, point1.y);
	Vec2 vPoint2 = Vec2(point2.x, point2.y);
	Vec2 cent = ((vPoint1 - vPoint2) * 0.5f)+vPoint2;
	//setting radius and center
	radius = int((vPoint1 - cent).GetLength());
	center.x = int(cent.x);
	center.y = int(cent.y);
}

void CCircle::Move(Point newPoint)
{
	//bug
	Vec2 incr = Vec2(newPoint.x, newPoint.y) - Vec2(center.x, center.y);
	Vec2 p1 = Vec2(point1.x, point1.y) + incr.GetNormalized() * incr.GetLength();
	Vec2 p2 = Vec2(point2.x, point2.y) + incr.GetNormalized() * incr.GetLength();
	//
	center.x = newPoint.x;
	center.y = newPoint.y;
	//bug fix
	//must update point1, and point2 to avoid coping bugs
	point1 = { int(p1.x), int(p1.y) };
	point2 = { int(p2.x), int(p2.y) };
	//
}

Point CCircle::getCriticalPoint() const
{
	return center;
}

CFigure* CCircle::getCopy() const
{
	return new CCircle(point1, point2, FigGfxInfo);
}

bool CCircle::isInsideMe(Point clickedPoint) const
{
	if (isHidden())
		return false;

	Vec2 vClickedPoint = Vec2(clickedPoint.x, clickedPoint.y);
	Vec2 vCenter = Vec2(center.x, center.y);
	float distance = (vClickedPoint - vCenter).GetLength();//distance between the clicked point and center

	if (FigGfxInfo.isFilled)
	{
		 return distance/radius <= 1.0f;
	}
	else //not filled
	{
		//ratio of distance over radius must approach one
		return distance/ radius >= 0.9f && distance/radius <= 1.1f;
	}

}

//note: bug in all overloaded constructors in figures
//bug here in the overloaded constructor must initialize point1, and point2, bug when coping loaded figures
//must set point1, and point2 using center and radius passed 
CCircle::CCircle(int id,Point cent, int r, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	figType = TYPE_CIRCLE;

	figtype = CIRCLE;

	center = cent;
	radius = r;
	ID = id;
	area = 3.1415f * radius * radius;
}
//

void CCircle::Save(ofstream& OutFile)
{
	//saves data
	OutFile << figtype << "," << ID << "," << center.x << "," << center.y << "," << radius << "," << drawclr << "," << fillclr<<std::endl;
}

void CCircle::Resize(float r)
{
	
	radius = int(float(radius) * r); //multiply the ratio to radius to get resized radius
	area = 3.1415f * radius * radius; //get new resized area

	//redfine points as vectors to calculate new postion of resized figure
	Vec2 v1 = Vec2(point1.x, point1.y);
	Vec2 v2 = Vec2(point2.x, point2.y);
	Vec2 cent = Vec2(center.x,center.y);


	if (r >= 0.0f && r < 1.0f)
	{
		//if the ratio is smaller then one the function calculates the vector from point to center and multiply by ratio
		v1 = ((cent - v1) * (1.0f - r)) + v1;
		v2 = ((cent - v2) * (1.0f - r)) + v2;
	}
	else
	{
		//if the ratio is bigger than one the function calulates the vector from center to point and multiply by ratio
		v1 = cent - ((cent - v1) * r);
		v2 = cent - ((cent - v2) * r);
	}
	point1 = {int(v1.x),int(v1.y)};
	point2 = {int(v2.x),int(v2.y)};
}

void CCircle::PrintInfo(Output* pOut) const
{
	pOut->PrintMessage(std::string("<<ID: ") + std::to_string(ID) + ">>Center: (" + std::to_string(center.x) + "," + std::to_string(center.y)+") " + ">>Radius: " + std::to_string(radius) + ">>Area: " + std::to_string(int(area)));
}
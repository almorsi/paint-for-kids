#include "CTriangle.h"
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	//making sure point1 is upper point of the triangle
	if (P1.y > P3.y)
	{
		std::swap(P1.y, P3.y);
		std::swap(P1.x, P3.x);
	}
	if (P1.y > P2.y)
	{
		std::swap(P1.y, P2.y);
		std::swap(P1.x, P2.x);
	}
	//Now the smallest element is the 1st one. Just check the 2nd and 3rd
	if (P2.y > P3.y)
	{
		std::swap(P2.y, P3.y);
		std::swap(P2.x, P3.x);
	}
	point1 = P1;
	point2 = P2;
	point3 = P3;
	//

	figType = TYPE_TRIANGLE;

	figtype = TRIANGLE;

	ID=3300+newID++;
	
	//setting area and center of triangle
	area = getTriArea(point1, point2, point3);

	center.x = int(float(point1.x + point2.x + point3.x) / 3);
	center.y = int(float(point1.y + point2.y + point3.y) / 3);
}


float CTriangle::getTriArea(Point p1, Point p2, Point p3) const
{
	//math :(
	return std::abs(0.5f * (float((p1.x - p2.x) * (p1.y - p3.y)) - float((p1.x - p3.x) * (p1.y - p2.y))));
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a Triangle on the screen	
	if(!isHidden())
		pOut->DrawTri(point1, point2,point3, FigGfxInfo, Selected);
}


bool CTriangle::isInsideMe(Point p) const 
{
	if (isHidden())
		return false;

	float Area1 = getTriArea(point1,point2,p);
	float Area2 = getTriArea(point1,point3,p);
	float Area3 = getTriArea(point2,point3,p);
	float sumArea = Area1 + Area2 + Area3;

	bool equalAreaCond = sumArea/area >= 0.95f && sumArea/area <= 1.05f;

	if (FigGfxInfo.isFilled)
	{
		return equalAreaCond;
	}
	else //not filled
	{
		//the point is on triangle if one or two of the areas approaches zero,
		//There are two cases
		/*
		* Case 1:
		* If the user click on one of the corners then there are two areas approach zero with
		* respect to the theird area(the greater one), so by getting the greater are and calculate
		* the ratio of the other two(the smaller ones), so it is easy to prove that the sum of these ratios
		* must be approach one for the point to be on one of corners.
		*/
		float maxArea = max(Area1, max(Area2, Area3));
		float maxAreaRatio = (Area1 / maxArea) + (Area2 / maxArea) + (Area3 / maxArea);
		bool isOnCorner = maxAreaRatio >= 0.9f && maxAreaRatio <= 1.1f;
		/*
		* Case 2:
		* If the user dosn't click on one of the corners, that is click on the boundry of the triangle,
		* then one of the areas must be very small comparing to the other two, from this we calculate
		* the ratio of the smallest on to the three areas, the sum of these ratios must approach one 
		* for the point to be on one of the edgs
		*/
		float minArea = min(Area1, min(Area2, Area3));
		float minAreaRatio = (minArea / Area1) + (minArea / Area2) + (minArea / Area3);
		bool isOnEdge = minAreaRatio >= 0.9f && minAreaRatio <= 1.1f;

		return equalAreaCond && (isOnCorner || isOnEdge);
	}
}


void CTriangle::Move(Point newPoint)
{
	//some linear algebra
	Vec2 v1 = Vec2(point1.x, point1.y);
	Vec2 v2 = Vec2(point2.x, point2.y);
	Vec2 v3 = Vec2(point3.x, point3.y);
	Vec2 newP = Vec2(newPoint.x, newPoint.y);

	Vec2 moveBy = (newP - v1).GetNormalized() * (newP - v1).GetLength();
	v2 += moveBy;
	v3 += moveBy;
	point1 = newPoint;
	point2 = { int(v2.x), int(v2.y) };
	point3 = { int(v3.x), int(v3.y) };

	center.x = int(float(point1.x + point2.x + point3.x) / 3);
	center.y = int(float(point1.y + point2.y + point3.y) / 3);
}

Point CTriangle::getCriticalPoint() const
{
	return point1;
}

CFigure* CTriangle::getCopy() const
{
	return new CTriangle(point1, point2, point3, FigGfxInfo);
}

void CTriangle::Resize(float r)
{
	//redfine points as vectors to calculate new postion of resized figure
	Vec2 v1 = Vec2(point1.x, point1.y);
	Vec2 v2 = Vec2(point2.x, point2.y);
	Vec2 v3 = Vec2(point3.x, point3.y);
	Vec2 cent = Vec2(center.x, center.y);

	if (r >= 0.0f && r < 1.0f)
	{
		//if the ratio is smaller then one the function calculates the vector from point to center and multiply by ratio
		v1 = ((cent - v1) * (1.0f - r)) + v1;
		v1 = ((cent - v1) * (1.0f - r)) + v1;
		v2 = ((cent - v2) * (1.0f - r)) + v2;
		v3 = ((cent - v3) * (1.0f - r)) + v3;
	}
	else
	{
		//if the ratio is bigger than one the function calulates the vector from center to point and multiply by ratio
		v1 = cent - ((cent - v1) * r);
		v2 = cent - ((cent - v2) * r);
		v3 = cent - ((cent - v3) * r);
	}

	//
	point1 = { int(v1.x), int(v1.y) };
	point2 = { int(v2.x), int(v2.y) };
	point3 = { int(v3.x), int(v3.y) };

	area = getTriArea(point1, point2, point3);//recalculate resized figure area
	
}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << figtype << "," << (ID) << "," << point1.x<<","<<point1.y<<","  << point2.x << "," << point2.y << ","  << point3.x << "," << point3.y << "," << drawclr << "," << fillclr << std::endl;
}

void CTriangle::PrintInfo(Output* pOut) const 
{
	pOut->PrintMessage(std::string("<<ID: ")+std::to_string(ID)+" <<Vertices: ( " + std::to_string(point1.x)+", "+ std::to_string(point1.y)+ " ), ( " + std::to_string(point2.x)+ ", " + std::to_string(point2.y)+ " ), ( " + std::to_string(point3.x)+ ", " + std::to_string(point3.y)+" ) <<Area: "+std::to_string(int(area)) + " <<center: ( " + std::to_string(center.x) + ", " + std::to_string(center.y) + " )");
}


CTriangle::CTriangle(int id, Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	if (P1.y > P3.y)
	{
		std::swap(P1.y, P3.y);
		std::swap(P1.x, P3.x);
	}
	if (P1.y > P2.y)
	{
		std::swap(P1.y, P2.y);
		std::swap(P1.x, P2.x);
	}
	//Now the smallest element is the 1st one. Just check the 2nd and 3rd
	if (P2.y > P3.y)
	{
		std::swap(P2.y, P3.y);
		std::swap(P2.x, P3.x);
	}
	point1 = P1;
	point2 = P2;
	point3 = P3;
	figType = TYPE_TRIANGLE;
	area = getTriArea(point1, point2, point3);
	ID = id;
	center.x = int(float(point1.x + point2.x + point3.x) / 3.0f);
	center.y = int(float(point1.y + point2.y + point3.y) / 3.0f);
	figtype = TRIANGLE;
}

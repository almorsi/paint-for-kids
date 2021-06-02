#include "CLine.h"

CLine::CLine(Point p1, Point p2, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
    
	if (p1.x < p2.x)
	{
		start = p1;
		finish = p2;
	}
	else
	{
		start = p2;
		finish = p1;
	}
    
	figType = TYPE_LINE;
	ID = 2200 + newID++;
	length = int( sqrt(float( (start.x-finish.x)*(start.x - finish.x) )-float( (start.y - finish.y)*(start.y - finish.y) ) ) );
	Vec2 v1 = Vec2(start.x, start.y);
	Vec2 v2 = Vec2(finish.x, finish.y);
	Vec2 cent = ((v1 - v2) * 0.5f) + v2;
	center.x = int(cent.x);
	center.y = int(cent.y);

	area = 0.0f;//always zero

	figtype = LINE;

}
CLine::CLine(int id,Point p1, Point p2, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{

	if (p1.x < p2.x)
	{
		start = p1;
		finish = p2;
	}
	else
	{
		start = p2;
		finish = p1;
	}

	figType = TYPE_LINE;
	ID = id;
	length = int(sqrt(float((start.x - finish.x) * (start.x - finish.x)) - float((start.y - finish.y) * (start.y - finish.y))));
	Vec2 v1 = Vec2(start.x, start.y);
	Vec2 v2 = Vec2(finish.x, finish.y);
	Vec2 cent = ((v1 - v2) * 0.5f) + v2;
	center.x = int(cent.x);
	center.y = int(cent.y);

	area = 0.0f;//always zero

	figtype = LINE;

}

void CLine::Resize(float r)
{
	Vec2 v1 = Vec2(start.x, start.y);
	Vec2 v2 = Vec2(finish.x, finish.y);
	Vec2 cent = Vec2(center.x, center.y);
	if (r >= 0 && r < 1)
	{
		v1 = ((cent - v1) * (1 - r)) + v1;
		v2 = ((cent - v2) * (1 - r)) + v2;
	}
	else
	{
		v1 = cent - ((cent - v1) * r);
		v2 = cent - ((cent - v2) * r);
	}
	start.x = int(v1.x);
	start.y = int(v1.y);
	finish.x = int(v2.x);
	finish.y = int(v2.y);
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	if(!isHidden())
		pOut->DrawLine(start,finish, FigGfxInfo, Selected);
}

bool CLine::isInsideMe(Point p) const 
{ 
	if (isHidden())
		return false;
	
	Vec2 v1 = Vec2(start.x, start.y);
	Vec2 v2 = Vec2(finish.x, finish.y);
	Vec2 v3 = Vec2(p.x, p.y);
	float r = (v1 - v2).GetLength(); //Calculate distance between start and finish point
	float r1 = (v1 - v3).GetLength();//Calculate distance between start and point
	float r2 = (v2 - v3).GetLength();//Calculate distance between finish and point
	float rt = r1 + r2;
	//The point is selected if the sum of distances equal total distance
	return (std::abs(r - rt) >= 0.0f && std::abs(r - rt) <= 0.1f);
}

 void CLine::PrintInfo(Output* pOut) const
 {
	 pOut->PrintMessage(std::string("<<ID: ") + std::to_string(ID) + " <<Start Point & End Point: " + "( " + std::to_string(start.x) + ", " + std::to_string(start.y) + " ), ( " + std::to_string(finish.x) + ", " + std::to_string(finish.y) + " )  <<Line Length: " + std::to_string(int(length))+ " <<center: ( "+std::to_string(center.x)+ ", "+ std::to_string(center.y)+ " )");
 }

 void CLine::Move(Point newPoint)
 {
	 Vec2 strt = Vec2(start.x, start.y);
	 Vec2 end = Vec2(finish.x, finish.y);
	 Vec2 newP = Vec2(newPoint.x, newPoint.y);

	 end += (newP - strt).GetNormalized() * (newP - strt).GetLength();

	 start = newPoint;
	 finish = { int(end.x), int(end.y) };
 }

 void CLine::moveBy(Vec2 incr)
 {
	 Vec2 strt = Vec2(start.x, start.y);
	 Point newPoint = { int((strt + incr).x), int((strt + incr).y) };
	 Move(newPoint);
 }

 Point CLine::getCriticalPoint() const
 {
	 return start;
 }

 CFigure* CLine::getCopy() const
 {
	 return new CLine(start,finish, FigGfxInfo);
 }

 void CLine::Save(ofstream& OutFile)
 {
	 OutFile << figtype << "," << (ID) << "," << start.x << "," << start.y << "," << finish.x << "," << finish.y << "," << drawclr <<std::endl;
 }

 void CLine::ChngFillClr(color Fclr)
 {
	 FigGfxInfo.DrawClr = Fclr;
	 fillclr = static_cast<fillColorType>(FromClrToInt(Fclr));
 }
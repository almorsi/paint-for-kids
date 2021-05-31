#include "CLine.h"

CLine::CLine(Point p1, Point p2, GfxInfo FigureGfxInfo)
	:
	CFigure(FigureGfxInfo)
{
	start = p1;
	finish = p2;
	ID = 2200 + newID++;
	length = sqrt(float((start.x-finish.x)*(start.x - finish.x))-float((start.y - finish.y)*(start.y - finish.y)));
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pOut->DrawLine(start,finish, FigGfxInfo, Selected);
}

bool CLine::isInsideMe(Point p) const 
{ 
	if (p.x <= finish.x && p.x >= start.x)
	{
		float grad1 = (float(finish.y - start.y) / (finish.x - start.x));
		float grad2 = (float(p.y - start.y) / (p.x - start.x));
		return std::abs(grad1 - grad2) >= 0.0f && std::abs(grad1 - grad2) <= 0.1f;
	}
	return false;
	
}

 void CLine::PrintInfo(Output* pOut) const
 {
	 pOut->PrintMessage(std::string("<<ID: ") + std::to_string(ID) + " <<Start Point & End Point: " + "( " + std::to_string(start.x) + ", " + std::to_string(start.y) + " ), ( " + std::to_string(finish.x) + ", " + std::to_string(finish.y) + " )  <<Line Length: " + std::to_string(int(length)));
 }

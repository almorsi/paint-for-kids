#pragma once
#include "GameColorOnly.h"
#include "GameShapeOnly.h"

class GameColorShape : public GameColorOnly, public GameShapeOnly
{
private:
	std::string shapeColorLabel;
public:
	GameColorShape(ApplicationManager* pApp, CFigure** figs, const int size, ActionType& actionAfterPlay);
	virtual bool isRightChoise(CFigure* fig) const;
	virtual ~GameColorShape();
};
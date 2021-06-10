#pragma once
#include "GameAction.h"
class GameShapeOnly : public virtual GameAction 
{
private:
	FigureType figType;
protected:
	void setFigType();
public:
	GameShapeOnly(ApplicationManager* pApp, CFigure** figs, const int size, ActionType& actionAfterPlay);
	virtual bool isRightChoise(CFigure* fig) const;
	virtual ~GameShapeOnly();
};
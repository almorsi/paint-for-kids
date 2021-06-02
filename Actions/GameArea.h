#pragma once
#include "GameAction.h"
class GameArea : public GameAction
{
private:
	AreaType areaType;
public:
	GameArea(ApplicationManager* pApp, CFigure** figs, const int size, ActionType& actionAfterPlay);
	virtual bool isRightChoise(CFigure* fig) const;
};
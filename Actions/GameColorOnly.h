#pragma once
#include "GameAction.h"
class GameColorOnly : public virtual GameAction
{
private:
	FigureColorType figClrType;
protected:
	void setFigClrType();
public:
	GameColorOnly(ApplicationManager* pApp, CFigure** figs, const int size, ActionType& actionAfterPlay);
	virtual bool isRightChoise(CFigure* fig) const;
	virtual ~GameColorOnly();
};
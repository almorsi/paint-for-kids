#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include <string>
//base class for all game actions
class GameAction : public Action
{
protected:

	CFigure** FiguresDrawn;

	const int nOfFiguresDrawn;

	Output* pOut;
	Input* pIn;

	ActionType& playAction;

	std::string gameLable;//each class should has its game label

	Point pointClicked;

	int nOfRightAns;
	int nOfWrongAns;

private:

	bool isControlActoin(ActionType act) const;
	void printGameState() const;
	void printGrade()const;

protected:

	bool isGameOver() const;
	virtual bool isRightChoise(CFigure* fig) const = 0;//each subclass should implement itself
	void setGameLabel(std::string str);

public:

	GameAction(ApplicationManager* pApp, CFigure** figs, const int size, ActionType& actionAfterPlay); //constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual ~GameAction();
};
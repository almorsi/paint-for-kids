#pragma once
#include "Action.h"
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
	std::string gameLable;//each class should implement has itself
	Point pointClicked;
	int nOfRightAns;
	int nOfWrongAns;

protected:

	bool isControlActoin(ActionType act) const;
	bool isGameOver() const;
	void printGameState() const;
	void printGrade()const;
	virtual bool isRightChoise(CFigure* fig) const = 0;//each class should has itself
	void setGameLabel(std::string str);

public:
	GameAction(ApplicationManager* pApp, CFigure** figs, const int size, ActionType& actionAfterPlay); //constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	//virtual void Undo()=0;

	//To redo this action (code depends on action type)
	//virtual void Redo()=0;

	virtual ~GameAction();
};
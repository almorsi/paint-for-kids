#pragma once
#include "Action.h"
#include "Move.h"
class Paste : public Action
{
private:

	CFigure** copiedFigures;//pointer to the copied Figures returned by Copy

	CFigure* firstCopiedfig;//pointer to the first one copied figure returned by Copy

	Move* moveAction;//paste needs move action to do the job

	const int nOfCopiedFigs;//size of the copied figures

public:
	Paste(ApplicationManager* pApp, CFigure** copiedFigs, const int nCopied, CFigure* firstCopied); //constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute() ;

	virtual ~Paste();
};
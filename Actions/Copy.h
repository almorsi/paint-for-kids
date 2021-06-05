#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class Copy : public Action
{
private:

	CFigure** selectedFigures;//pointer to the selected figure that will be copied

	CFigure* firstSelectedFig;//pointer to the first selected figure to copy

	CFigure** copiedFigures;//pointer to the copied figures

	CFigure* copyOfFirstSelectedFigure;//pointer to the COPY OF first selected figure

	const int nOfFigsToCopy;//number of figures to copy

public:
	//constructor
	Copy(ApplicationManager* pApp, CFigure** selectedFigures, const int size, CFigure* firstFigure);

	virtual void ReadActionParameters();

	virtual void Execute();

	//return the copied figures, this function is neccessary to be passed to the Paste Action constructor
	virtual CFigure** getCopiedFigures() const;
	//return the first copied figure, this function is neccessary to be passed to the Paste Action constructor
	virtual CFigure* getFirstSelectedCopy() const;
	//return the size of the copied array
	virtual int getNOfFigsToCopy()const;

	virtual ~Copy();
};
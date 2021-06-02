#include "GameColorShape.h"
#include <assert.h>
GameColorShape::GameColorShape(ApplicationManager* pApp, CFigure** figs, const int size, ActionType& actionAfterPlay)
	:
	GameAction(pApp, figs, size, actionAfterPlay),
	GameColorOnly(pApp, figs, size, actionAfterPlay),
	GameShapeOnly(pApp, figs, size, actionAfterPlay)
{
	assert(size > 0);
	do
	{
		shapeColorLabel = "";

		setFigClrType();
		shapeColorLabel += gameLable;

		shapeColorLabel += " ";

		setFigType();
		shapeColorLabel += gameLable;

	} while (isGameOver());
	setGameLabel(shapeColorLabel);
}

bool GameColorShape::isRightChoise(CFigure* fig) const
{
	return GameColorOnly::isRightChoise(fig) && GameShapeOnly::isRightChoise(fig);
}

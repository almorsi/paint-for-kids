#include "GameColorShape.h"
#include <assert.h>
GameColorShape::GameColorShape(ApplicationManager* pApp, CFigure** figs, const int size, ActionType& actionAfterPlay)
	:
	GameAction(pApp, figs, size, actionAfterPlay),
	GameColorOnly(pApp, figs, size, actionAfterPlay),//THE CALL TO GAMEACTION CONSTRUCTOR IS SKIPPED BY THE COMPILER
	GameShapeOnly(pApp, figs, size, actionAfterPlay) //THE CALL TO GAMEACTION CONSTRUCTOR IS SKIPPED BY THE COMPILER
{
	assert(size > 0);
	do
	{
		shapeColorLabel = "";

		GameColorOnly::setFigClrType();
		shapeColorLabel += gameLable;

		shapeColorLabel += " ";

		GameShapeOnly::setFigType();
		shapeColorLabel += gameLable;

	} while (isGameOver());
	setGameLabel(shapeColorLabel);
}

bool GameColorShape::isRightChoise(CFigure* fig) const
{
	return GameColorOnly::isRightChoise(fig) && GameShapeOnly::isRightChoise(fig);
}

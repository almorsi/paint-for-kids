#include "GameColorOnly.h"
#include <random>
#include <assert.h>
GameColorOnly::GameColorOnly(ApplicationManager* pApp, CFigure** figs, const int size, ActionType& actionAfterPlay)
	:
	GameAction(pApp, figs, size, actionAfterPlay)
{
	assert(size > 0);
	setFigClrType();
}

bool GameColorOnly::isRightChoise(CFigure* fig) const
{
	return fig->isMyFigColorType(figClrType);
}

void GameColorOnly::setFigClrType()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 9);//10 color types are allowed

	do
	{
		int randomNumber = dist(rng);
		switch (randomNumber)
		{
		case 0:
			figClrType = TYPE_BLACK;
			gameLable = "Black";
			break;
		case 1:
			figClrType = TYPE_GRAY;
			gameLable = "Gray";
			break;
		case 2:
			figClrType = TYPE_BLUE;
			gameLable = "Blue";
			break;
		case 3:
			figClrType = TYPE_CYAN;
			gameLable = "Cyan";
			break;
		case 4:
			figClrType = TYPE_GREEN;
			gameLable = "Green";
			break;
		case 5:
			figClrType = TYPE_YELLOW;
			gameLable = "Yellow";
			break;
		case 6:
			figClrType = TYPE_BROWN;
			gameLable = "Brown";
			break;
		case 7:
			figClrType = TYPE_ORANGE;
			gameLable = "Orange";
			break;
		case 8:
			figClrType = TYPE_RED;
			gameLable = "Red";
			break;
		case 9:
			figClrType = TYPE_NO_FILL;
			gameLable = "Not Filled";
			break;
		default:
			break;
		}
	} while (isGameOver());
}

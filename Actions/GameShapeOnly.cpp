#include "GameShapeOnly.h"
#include <random>
#include <assert.h>
GameShapeOnly::GameShapeOnly(ApplicationManager* pApp, CFigure** figs, const int size, ActionType& actionAfterPlay)
    :
    GameAction(pApp, figs, size, actionAfterPlay)
{
    assert(size > 0);
    setFigType();
}



bool GameShapeOnly::isRightChoise(CFigure* fig) const
{
    assert(!fig->isHidden());
    return fig->isMyType(figType);
}


void GameShapeOnly::setFigType()
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(0, 3);//3 figures only

    do
    {
        int randomNumber = dist(rng);
        switch (randomNumber)
        {
        case 0:
            figType = TYPE_LINE;
            gameLable = "Lines";
            break;
        case 1:
            figType = TYPE_TRIANGLE;
            gameLable = "Triangles";
            break;
        case 2:
            figType = TYPE_CIRCLE;
            gameLable = "Circles";
            break;
        case 3:
            figType = TYPE_RECTANGLE;
            gameLable = "Rectangles";
            break;
        default:
            break;
        }
    } while (isGameOver());

}
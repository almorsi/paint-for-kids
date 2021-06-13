#include <assert.h>

#include "GameShapeOnly.h"

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

GameShapeOnly::~GameShapeOnly()
{
    pManager->GetOutput()->UnhighlightItem(ITM_SHAPE_ONLY);
}


void GameShapeOnly::setFigType()
{

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
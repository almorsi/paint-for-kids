#include "ToPlay.h"
#include "..\ApplicationManager.h"
#include "GameShapeOnly.h"
#include "GameColorOnly.h"
#include "GameArea.h"
#include "GameColorShape.h"
ToPlay::ToPlay(ApplicationManager* pApp, CFigure** figsDrawn, const int size)
	:
	Action(pApp),
	figuresDrawn(figsDrawn),
	nOfFiguresDrawn(size)
{

	playAction = EMPTY;

	actionAfterPlay = EMPTY;

}

void ToPlay::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please choose an operational game mode(figures only, shape only, shape and color only, area only");

	//make sure the user choose an operational action to exectue
	do
	{
		playAction = pIn->GetUserAction();
	} while (!isOperationalAction(playAction));
	//

	pOut->drawCleanStatusBar();
}

void ToPlay::Execute()
{
	ReadActionParameters();

	do
	{
		//check to see if the user change to the draw mode
		if (playAction == TO_DRAW)
		{
			doPlayAction(playAction);
			break;//break play mode and go back to draw mode
		}

		do
		{
			doPlayAction(playAction);//actionAfterPlay will update it self throw this function, i.e. passed by refrence
			pManager->UpdateInterface();

		} while (actionAfterPlay == RE_PLAY);

		playAction = actionAfterPlay;

	} while (isOperationalAction(playAction));

}

bool ToPlay::isOperationalAction(ActionType act) const
{
	return act == SHAPE_ONLY || act == SHAPE_N_CLR
		|| act == AREA || act == CLR_ONLY || act == TO_DRAW;
}

void ToPlay::doPlayAction(ActionType act) 
{
	Action* pAct = NULL;
	switch (act)
	{
	case TO_DRAW:
		std::cout << "ToPlay Action : change to Draw Mode" << std::endl;
		UI.InterfaceMode = MODE_DRAW;
		break;
	case RE_PLAY:
		//replay the choosen game, never be the case
		std::cout << "ToPlay Action : re play action" << std::endl;
		break;
	case SHAPE_ONLY:
		std::cout << "ToPlay Action : shpae only game mode" << std::endl;
		pAct = new GameShapeOnly(pManager, figuresDrawn, nOfFiguresDrawn, actionAfterPlay);
		break;
	case CLR_ONLY:
		std::cout << "ToPlay Action : color only game mode" << std::endl;
		pAct = new GameColorOnly(pManager, figuresDrawn, nOfFiguresDrawn, actionAfterPlay);
		break;
	case SHAPE_N_CLR:
		std::cout << "ToPlay Action : shape and color only game mode" << std::endl;
		pAct = new GameColorShape(pManager, figuresDrawn, nOfFiguresDrawn, actionAfterPlay);
		break;
	case AREA:
		pAct = new GameArea(pManager, figuresDrawn, nOfFiguresDrawn, actionAfterPlay);
		std::cout << "ToPlay Action : Area only game mode" << std::endl;
		break;
	default:
		break;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}


ToPlay::~ToPlay()
{
	for (int i = 0; i < nOfFiguresDrawn; i++)
		figuresDrawn[i]->setHidden(false);
}
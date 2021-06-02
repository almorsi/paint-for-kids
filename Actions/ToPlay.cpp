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

	do
	{
		playAction = pIn->GetUserAction();
	} while (!isOperationalAction(playAction));

	pOut->drawCleanStatusBar();
}

void ToPlay::Execute()
{
	ReadActionParameters();

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	do
	{
		do
		{
			doPlayAction(playAction);
			if (playAction == TO_DRAW)
			{
				break;
			}

			pManager->UpdateInterface();
		} while (actionAfterPlay == RE_PLAY);

		playAction = actionAfterPlay;

		if (playAction == TO_DRAW)
		{
			doPlayAction(playAction);
			break;
		}

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
	case DRAWING_AREA:
		break;
	case STATUS:
		break;
	case EMPTY:
		break;
	case TO_DRAW:
		std::cout << "ToPlay Action : change to Draw Mode" << std::endl;
		UI.InterfaceMode = MODE_DRAW;
		actionAfterPlay = TO_DRAW;
		break;
	case TO_PLAY:
		break;
	case DRAW_LINE:
		break;
	case DRAW_RECT:
		break;
	case DRAW_TRI:
		break;
	case DRAW_CIRC:
		break;
	case CHNG_DRAW_CLR:
		break;
	case CHNG_FILL_CLR:
		break;
	case CHNG_BK_CLR:
		break;
	case SELECT:
		break;
	case DEL:
		break;
	case MOVE:
		break;
	case COPY:
		break;
	case CUT:
		break;
	case PASTE:
		break;
	case RESIZE:
		break;
	case ROTATE:
		break;
	case SEND_BACK:
		break;
	case BRNG_FRNT:
		break;
	case SAVE:
		break;
	case LOAD:
		break;
	case REDO:
		break;
	case UNDO:
		break;
	case RE_PLAY:
		//never get here
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
	case EXIT:
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
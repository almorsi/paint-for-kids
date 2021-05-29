#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\ChangeColorActions\ChngBkgndClr.h"
#include "Actions\ChangeColorActions\ChngDrawClr.h"
#include "Actions\ChangeColorActions\ChngFillClr.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAWING_AREA:
		std::cout << "Action: DRAWING_AREA" << std::endl;
		break;
	case STATUS:		//a click on the status bar ==> no action
		std::cout << "Action: STATUS" << std::endl;
		break;
	case EMPTY:
		std::cout << "Action: EMPTY" << std::endl;
		break;
	case TO_DRAW:
		UI.InterfaceMode = MODE_DRAW;
		pOut->drawToolBar();
		std::cout << "Action: TO_DRAW" << std::endl;
		break;
	case TO_PLAY:
		UI.InterfaceMode = MODE_PLAY;
		pOut->drawToolBar();
		std::cout << "Action: TO_PLAY" << std::endl;
		break;
	case DRAW_LINE:
		std::cout << "Action: DRAW_LINE" << std::endl;
		break;
	case DRAW_RECT:
		std::cout << "Action: DRAW_RECT" << std::endl;
		pAct = new AddRectAction(this);
		break;
	case DRAW_TRI:
		std::cout << "Action: DRAW_TRI" << std::endl;
		break;
	case DRAW_CIRC:
		std::cout << "Action: DRAW_CIRC" << std::endl;
		break;
	case CHNG_DRAW_CLR:
		std::cout << "Action: CHNG_DRAW_CLR" << std::endl;
		pAct = new ChngDrawClr(this);
		break;
	case CHNG_FILL_CLR:
		std::cout << "Action: CHNG_FILL_CLR" << std::endl;
		pAct = new ChngFillClr(this);
		break;
	case CHNG_BK_CLR:
		std::cout << "Action: CHNG_BK_CLR" << std::endl;
		pAct = new ChngBkgndClr(this);
		break;
	case SELECT:
		std::cout << "Action: SELECT" << std::endl;
		break;
	case DEL:
		std::cout << "Action: DEL" << std::endl;
		break;
	case MOVE:
		std::cout << "Action: MOVE" << std::endl;
		break;
	case RESIZE:
		std::cout << "Action: RESIZE" << std::endl;
		break;
	case ROTATE:
		std::cout << "Action: ROTATE" << std::endl;
		break;
	case SEND_BACK:
		std::cout << "Action: SEND_BACK" << std::endl;
		break;
	case BRNG_FRNT:
		std::cout << "Action: BRNG_FRNT" << std::endl;
		break;
	case SAVE:
		std::cout << "Action: SAVE" << std::endl;
		break;
	case LOAD:
		std::cout << "Action: LOAD" << std::endl;
		break;
	case REDO:
		std::cout << "Action: REDO" << std::endl;
		break;
	case UNDO:
		std::cout << "Action: UNDO" << std::endl;
		break;
	case RE_PLAY:
		std::cout << "Action: RE_PLAY" << std::endl;
		break;
	case SHAPE_ONLY:
		std::cout << "Action: SHAPE_ONLY" << std::endl;
		break;
	case CLR_ONLY:
		std::cout << "Action: CLR_ONLY" << std::endl;
		break;
	case SHAPE_N_CLR:
		std::cout << "Action: SHAPE_N_CLR" << std::endl;
		break;
	case AREA:
		std::cout << "Action: AREA" << std::endl;
		break;
	case EXIT:
		std::cout << "Action: EXIT" << std::endl;
		break;
	default:
		break;
	}
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(Point p) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->isInsideMe(p))
			return FigList[i];
	}

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}

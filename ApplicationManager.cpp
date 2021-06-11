#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\ChangeColorActions\ChngBkgndClr.h"
#include "Actions\ChangeColorActions\ChngDrawClr.h"
#include "Actions\ChangeColorActions\ChngFillClr.h"
#include "Actions\Select.h"
#include "Actions\Load.h"
#include "Actions\ToPlay.h"
#include "Actions\Save.h"
#include "Actions\Delete.h"
#include <assert.h>

Point ApplicationManager::point = { 0, 0 };

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
ActionType ApplicationManager::GetUserAction(Point& p) const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction(p);		
}

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
		pAct = new ToPlay(this, FigList, FigCount);
		std::cout << "Action: TO_PLAY" << std::endl;
		break;
	case DRAW_LINE:
		std::cout << "Action: DRAW_LINE" << std::endl;
		pOut->highlightItem(ITM_LINE);
		pOut->drawToolBar();
		pAct = new AddLineAction(this);
		break;
	case DRAW_RECT:
		pOut->highlightItem(ITM_RECT);
		pOut->drawToolBar();
		std::cout << "Action: DRAW_RECT" << std::endl;
		pAct = new AddRectAction(this);
		break;
	case DRAW_TRI:
		pOut->highlightItem(ITM_TRI);
		pOut->drawToolBar();
		std::cout << "Action: DRAW_TRI" << std::endl;
		pAct = new AddTriAction(this);
		break;
	case DRAW_CIRC:
		pOut->highlightItem(ITM_CIRC);
		pOut->drawToolBar();
		std::cout << "Action: DRAW_CIRC" << std::endl;
		pAct = new AddCircleAction(this);
		break;
	case CHNG_DRAW_CLR:
		pOut->highlightItem(ITM_DRAW_CLR);
		pOut->drawToolBar();
		std::cout << "Action: CHNG_DRAW_CLR" << std::endl;
		pAct = new ChngDrawClr(this);
		break;
	case CHNG_FILL_CLR:
		pOut->highlightItem(ITM_FILL_CLR);
		pOut->drawToolBar();
		std::cout << "Action: CHNG_FILL_CLR" << std::endl;
		pAct = new ChngFillClr(this);
		break;
	case CHNG_BK_CLR:
		pOut->highlightItem(ITM_BK_CLR);
		pOut->drawToolBar();
		std::cout << "Action: CHNG_BK_CLR" << std::endl;
		pAct = new ChngBkgndClr(this);
		break;
	case SELECT:
		pOut->highlightItem(ITM_SELECT);
		pOut->drawToolBar();
		std::cout << "Action: SELECT" << std::endl;
		pAct = new Select(this);
		break;
	case ZOOM_IN:
		std::cout << "Action: Zoom IN" << std::endl;
		pOut->zoomIn();
		break;
	case ZOOM_OUT:
		pOut->zoomOut();
		std::cout << "Action: Zoom Out" << std::endl;
		break;
	case SAVE:
		std::cout << "Action: SAVE" << std::endl;
		pAct = new Save(this);
		break;
	case LOAD:
	{
		std::cout << "Action: LOAD" << std::endl;
		pOut->PrintMessage(std::string("<< choose 1 if you want to save before loading files and choose 0 if you want to load without saving >>"));//checks if user will save or close
		bool choice = bool(std::stoi(pIn->GetSrting(pOut)));
		pOut->drawCleanStatusBar();
		if (choice == true)
		{
			pAct = new Save(this);
			pAct->Execute();
			delete pAct;
			pAct = NULL;
			pAct = new Delete(this, FigList, FigCount);
			pAct->Execute();
			delete pAct;
			pAct = NULL;
			pAct = new Load(this);
			break;
		}
		else
		{
			pAct = new Delete(this, FigList, FigCount);
			pAct->Execute();
			delete pAct;
			pAct = NULL;
			pAct = new Load(this);
			std::cout << "Action: EXIT" << std::endl;
			break;
		}
	}
	case EXIT:
	{
		pOut->PrintMessage(std::string("<< choose 1 if you want to save and choose 0 if you want to close >>"));//checks if user will save or close
		bool choice = bool (std::stoi(pIn->GetSrting(pOut)));
		pOut->drawCleanStatusBar();
		if (choice == true)
		{
			pAct = new Save(this);
			pAct->Execute();//Execute
			delete pAct;	//Action is not needed any more ==> delete it
			pAct = NULL;
			break;
		}
		else
		{
			std::cout << "Action: EXIT" << std::endl;
			break;
		}
	}
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

void ApplicationManager::saveData(ofstream& OutFile)
{
	OutFile << FromClrToInt(UI.DrawColor) << "," << FromClrToInt(UI.FillColor) << "," << FromClrToInt(UI.BkGrndColor) << std::endl;
	OutFile << FigCount << std::endl;
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
	}
}

void ApplicationManager::loadData(ifstream& Infile)
{
	std::string line;
	int rownum = 0; //row number counter
	while (std::getline(Infile, line)) //takes file data row by row 
	{
		vector<string> Data;
		std::istringstream s(line);
		std::string field;
		while (getline(s, field, ','))
		{
			Data.push_back(field); //put each string indivually in a vector
			std::cout << field << endl;
		}
		if (rownum == 0)
		{
			UI.DrawColor = FromIntToClr(std::stoi(Data[0]));
			UI.FillColor = FromIntToClr(std::stoi(Data[1]));
			UI.BkGrndColor = FromIntToClr(std::stoi(Data[2]));
		}
		else if (rownum == 1)
		{
			//The number of figures is not important due to the nature of this code as the figures are redrawn
			//FigCount = std::stoi(Data[0]);
		}
		else
		{
			loadDataFigs(Data);
		}
		rownum++;
	}
}
//The following function rearrange data from the saved file to match figure constructor according to type then creates a figure
void ApplicationManager::loadDataFigs(vector<string>& data)
{
	if (std::stoi(data[0]) == 0)
	{
		Point start, finish;
		GfxInfo FigGfxInfo;
		int ID;
		ID = std::stoi(data[1]);
		start.x = std::stoi(data[2]);
		start.y = std::stoi(data[3]);
		finish.x = std::stoi(data[4]);
		finish.y = std::stoi(data[5]);
		FigGfxInfo.DrawClr = FromIntToClr(std::stoi(data[6]));
		FigGfxInfo.BorderWdth = pOut->getCrntPenWidth();
		FigGfxInfo.FillClr = WHITE;
		FigGfxInfo.isFilled = false;
		CFigure* fig = new CLine(ID, start, finish, FigGfxInfo);
		AddFigure(fig);
	}
	else if (std::stoi(data[0]) == 1)
	{
		Point Corner1, Corner2;
		GfxInfo FigGfxInfo;
		int ID;
		ID = std::stoi(data[1]);
		Corner1.x = std::stoi(data[2]);
		Corner1.y = std::stoi(data[3]);
		Corner2.x = std::stoi(data[4]);
		Corner2.y = std::stoi(data[5]);
		FigGfxInfo.DrawClr = FromIntToClr(std::stoi(data[6]));
		if (std::stoi(data[7]) == 9)
		{
			FigGfxInfo.isFilled = false;
			FigGfxInfo.FillClr = WHITE;
		}
		else
		{
			FigGfxInfo.FillClr = FromIntToClr(std::stoi(data[7]));
			FigGfxInfo.isFilled = true;
		}
		FigGfxInfo.BorderWdth = pOut->getCrntPenWidth();
		CFigure* fig = new CRectangle(ID, Corner1, Corner2, FigGfxInfo);
		AddFigure(fig);
	}
	else if (std::stoi(data[0]) == 2)
	{
		Point point1, point2, point3;
		GfxInfo FigGfxInfo;
		int ID;
		ID = std::stoi(data[1]);
		point1.x = std::stoi(data[2]);
		point1.y = std::stoi(data[3]);
		point2.x = std::stoi(data[4]);
		point2.y = std::stoi(data[5]);
		point3.x = std::stoi(data[6]);
		point3.y = std::stoi(data[7]);
		FigGfxInfo.DrawClr = FromIntToClr(std::stoi(data[8]));
		if (std::stoi(data[9]) == 9)
		{
			FigGfxInfo.isFilled = false;
			FigGfxInfo.FillClr = WHITE;
		}
		else
		{
			FigGfxInfo.FillClr = FromIntToClr(std::stoi(data[9]));
			FigGfxInfo.isFilled = true;
		}

		FigGfxInfo.BorderWdth = pOut->getCrntPenWidth();
		CFigure* fig = new CTriangle(ID, point1, point2, point3, FigGfxInfo);
		AddFigure(fig);
	}
	else
	{
		Point center;
		int radius, ID;
		GfxInfo FigGfxInfo;
		ID = std::stoi(data[1]);
		center.x = std::stoi(data[2]);
		center.y = std::stoi(data[3]);
		radius = std::stoi(data[4]);
		FigGfxInfo.DrawClr = FromIntToClr(std::stoi(data[5]));
		if (std::stoi(data[6]) == 9)
		{
			FigGfxInfo.isFilled = false;
			FigGfxInfo.FillClr = WHITE;
		}
		else
		{
			FigGfxInfo.FillClr = FromIntToClr(std::stoi(data[6]));
			FigGfxInfo.isFilled = true;
		}
		FigGfxInfo.BorderWdth = pOut->getCrntPenWidth();
		CFigure* fig = new CCircle(ID, center, radius, FigGfxInfo);
		AddFigure(fig);
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
//delete figures from figList
void ApplicationManager::deleteFigures(CFigure** figsToDelete, const int size)
{
	for (int i = 0; i < size; i++)
	{
		assert(figsToDelete[i] != NULL);

		delete GetFigure(figsToDelete[i]); //free figure's memory
		GetFigure(figsToDelete[i]) = NULL; //null it in figList
		figsToDelete[i] = NULL;//must be nulled here also, to avoid unselect deleted figure 
	}
	//rearrange FigList
	reArrangeFigList(size);
	//update figCount
	FigCount -= size;
}
void ApplicationManager::reArrangeFigList(int deletedFigsCount)
{
	int nOfUnDeletedFigs = FigCount - deletedFigsCount;

	//figList is called by deleteFigures and there are some figures need to be reArranged
	//first getting the notNulled figures from figList
	CFigure** notNulledFigures = new CFigure * [nOfUnDeletedFigs]();//initialize them to NULL
	for (int i = 0, j = 0; i < FigCount && j < nOfUnDeletedFigs; i++)
	{
		if (FigList[i] != NULL)//store it in notNulledFigures
		{
			notNulledFigures[j] = FigList[i];
			FigList[i] = NULL;
			j++;
		}
	}
	//reArrange figList to only contain the notNUlledfigures
	for (int i = 0; i < nOfUnDeletedFigs; i++)
	{
		FigList[i] = notNulledFigures[i];
	}
	delete[] notNulledFigures;
}
CFigure* ApplicationManager::GetFigure(Point p) const
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
CFigure* ApplicationManager::GetFigure(int index) const
{
	if (index < FigCount)
		return FigList[index];

	assert(false);
	return NULL;
}
CFigure*& ApplicationManager::GetFigure(CFigure* fig)
{

	for (int i = 0; i < FigCount; i++)
		if (FigList[i] == fig)
			return FigList[i];

	assert(false);
	return fig;
}
int ApplicationManager::FromClrToInt(color c)
{
	if (c.ucBlue == BLACK.ucBlue && c.ucGreen == BLACK.ucGreen && c.ucRed == BLACK.ucRed)
		return 0;
	else if (c.ucBlue == GRAY.ucBlue && c.ucGreen == GRAY.ucGreen && c.ucRed == GRAY.ucRed)
		return 1;
	else if (c.ucBlue == BLUE.ucBlue && c.ucGreen == BLUE.ucGreen && c.ucRed == BLUE.ucRed)
		return 2;
	else if (c.ucBlue == CYAN.ucBlue && c.ucGreen == CYAN.ucGreen && c.ucRed == CYAN.ucRed)
		return 3;
	else if (c.ucBlue == GREEN.ucBlue && c.ucGreen == GREEN.ucGreen && c.ucRed == GREEN.ucRed)
		return 4;
	else if (c.ucBlue == YELLOW.ucBlue && c.ucGreen == YELLOW.ucGreen && c.ucRed == YELLOW.ucRed)
		return 5;
	else if (c.ucBlue == BROWN.ucBlue && c.ucGreen == BROWN.ucGreen && c.ucRed == BROWN.ucRed)
		return 6;
	else if (c.ucBlue == ORANGE.ucBlue && c.ucGreen == ORANGE.ucGreen && c.ucRed == ORANGE.ucRed)
		return 7;
	else if (c.ucBlue == RED.ucBlue && c.ucGreen == RED.ucGreen && c.ucRed == RED.ucRed)
		return 8;
	else //if called by color then 9 means white if it is called by fill the it is nofill
		return 9;
}
color ApplicationManager::FromIntToClr(int n)
{
	if (n == 0)
		return BLACK;
	else if (n == 1)
		return GRAY;
	else if (n == 2)
		return BLUE;
	else if (n == 3)
		return CYAN;
	else if (n == 4)
		return GREEN;
	else if (n == 5)
		return YELLOW;
	else if (n == 6)
		return BROWN;
	else if (n == 7)
		return ORANGE;
	else if (n == 8)
		return RED;
	else
		return WHITE;
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
	pOut->drawToolBar();
	pOut->drawCleanStatusBar();
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//							Play Mode functions          							//
//==================================================================================//
bool ApplicationManager::isSmallestArea(CFigure* fig) const
{
	for (int i = 0; i < FigCount; i++)
		if (!FigList[i]->isHidden() && fig->getArea() > FigList[i]->getArea())
			return false;
	return true;
}
bool ApplicationManager::isLargestArea(CFigure* fig) const
{
	for (int i = 0; i < FigCount; i++)
		if (!FigList[i]->isHidden() && fig->getArea() < FigList[i]->getArea())
			return false;
	return true;
}
////////////////////////////////////////////////////////////////////////////////////
 
int ApplicationManager::getFigCount() const
{
	return FigCount;
}
int ApplicationManager::getIndexOf(CFigure* fig) const
{
	if (fig != NULL)
	{
		for (int i = 0; i < FigCount; i++)
			if (fig == FigList[i])
				return i;
	}
	return -1;
}
///////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}

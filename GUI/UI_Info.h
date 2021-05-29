#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW = 'D',	//Drawing mode (startup mode) 
	MODE_PLAY = 'P'  //Playing mode
};

enum MENU_ITEM_STATE
{
	HIGHLIGHTED = 'H', //menu item is hilighted
	NORMAL = 'N' //menu item is not hilighted
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_TO_PLAY,	//swithch to play mode
	ITM_LINE,		//Line item in menu
	ITM_RECT,		//Recangle item in menu
	ITM_TRI,        //Trinagle item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_DRAW_CLR,   //Change draw color
	ITM_FILL_CLR,   //Change fill color
	ITM_BK_CLR,     //Change background color
	ITM_SELECT,     //Select shape
	ITM_DEL,        //Delete selcted item
	ITM_MOVE,       //Move selected item
	ITM_RESIZE,     //Resize selected item
	ITM_ROTATE,     //Rotate seleted item
	ITM_SEND_BACK,  //Send back selected item
	ITM_BRNG_FRNT,  //Send front selected item
	ITM_SAVE,       //Save data
	ITM_LOAD,       //Load data
	ITM_UNDO,       //Undo action
	ITM_REDO,       //redo action
	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_TO_DRAW,		//switch to draw mode
	ITM_RePLAY,			//choose to replay the game
	ITM_SHAPE_ONLY,     //Choose shape only mode
	ITM_CLR_ONLY,       //Choose color only mode
	ITM_SHAPE_N_CLR,    //Choose shape and color mode
	ITM_AREA,           //choose area mode

	ITM_EXT,			//Exit item
	//choosing a different name other than ITM::EXIT in DrawMenuItem
	//is necessary because it is not an enum class

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum ChngColorWindItem
{
	ITM_BLACK,	// color black
	ITM_GRAY,	// color gray
	ITM_BLUE,   // color blue
	ITM_CYAN,	// color cyan
	ITM_GREEN,	// color green
	ITM_YELLOW,	// color yellow
	ITM_BROWN,	// color brown
	ITM_ORANGE,	// color orange
	ITM_RED,	// color red
	ITM_CANCEL,	// color cancel

	CHNG_COLR_ITM_COUNT	//must be the last one, and prefered to be even number
};

enum ColorType
{
	BACKGROUND, //Background color
	DRAW,		//drawing color
	FILL		//filling color
};

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,		//Window width and height
		wx, wy,				//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth,		//Width of each item in toolbar menu
		MaxNItems,			//maximium number of items in the two tool bars
		MenuItemHeight,		//menu items height in toolbars
		FreeSpaceInToolBar,	//realated to the item widht
		BarPadding;			//padding in the (tool/status)bar between the items and the drawing area

	
	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color ToolBarColor;     //Tool bar color
	int PenWidth;			//width of the pen that draws shapes

}UI;	//create a global object UI

#endif
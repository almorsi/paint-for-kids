#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	//Actions related to the GUI
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	//Switch actions
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode

	//Draw mode actions
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	SELECT,         //Selects figure(s)
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	COPY,			//COPY FIGURES
	CUT,			//Cut figures
	PASTE,			//paste figures
	RESIZE,			//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	REDO,           //Undo action
	UNDO,           //Redo action

	//Play mode actions
	RE_PLAY,		//RePlay the game
	SHAPE_ONLY,     //Choose shape only in the play mode
	CLR_ONLY,       //Choose color only in the play mode
	SHAPE_N_CLR,    //Choose shape and color in the play mode
	AREA,           //Choose area in the play mode

	//Common action in draw and play 
	EXIT,			//Exit the application

};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

enum FigureType
{
	TYPE_LINE,
	TYPE_TRIANGLE,
	TYPE_CIRCLE,
	TYPE_RECTANGLE,
	NONE
};

#endif
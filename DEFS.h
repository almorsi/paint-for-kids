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
	ZOOM_IN,		//Zoom In
	ZOOM_OUT,		//Zoom Out
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file

	//Play mode actions
	RE_PLAY,		//RePlay the game
	SHAPE_ONLY,     //Choose shape only in the play mode
	CLR_ONLY,       //Choose color only in the play mode
	SHAPE_N_CLR,    //Choose shape and color in the play mode
	AREA,           //Choose area in the play mode

	//Common action in draw and play 
	EXIT,			//Exit the application

};

enum drawColorType //To determine drawing color type of figures
{
	D_BLACK,	// color black
	D_GRAY,	    // color gray
	D_BLUE,     // color blue
	D_CYAN,	    // color cyan
	D_GREEN,	// color green
	D_YELLOW,	// color yellow
	D_BROWN,	// color brown
	D_ORANGE,	// color orange
	D_RED,	    // color red
};

enum fillColorType //To determine fill color type of figures
{
	F_BLACK,    // color black
	F_GRAY,	    // color gray
	F_BLUE,     // color blue
	F_CYAN,	    // color cyan
	F_GREEN,	// color green
	F_YELLOW,   // color yellow
	F_BROWN,	// color brown
	F_ORANGE,	// color orange
	F_RED,	    // color red
	NOFILL,
};

enum figureType //to determine figure types of figures
{
	LINE,
	RECTANGLE,
	TRIANGLE,
	CIRCLE,
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
	NON
};

enum FigureColorType
{
	TYPE_BLACK,	// color black
	TYPE_GRAY,	// color gray
	TYPE_BLUE,   // color blue
	TYPE_CYAN,	// color cyan
	TYPE_GREEN,	// color green
	TYPE_YELLOW,	// color yellow
	TYPE_BROWN,	// color brown
	TYPE_ORANGE,	// color orange
	TYPE_RED,	// color red
	TYPE_NO_FILL
};

enum AreaType
{
	TYPE_LARGEST,
	TYPE_SMALLEST
};
#endif
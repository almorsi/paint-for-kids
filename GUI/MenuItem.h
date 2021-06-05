#ifndef MENUITEM_H
#define MENUITEM_H
#include <iostream>
#include <string>
#include "UI_Info.h"
class MenuItem
{
private:

	static int counter;//for std::cout debugging

	static const std::string BasePath;//base path for all tool bar items

	const int fileName; //is a number to represent the file index in the toolbar, also it is the file name without extention

	MENU_ITEM_STATE state; //highlighted or normal

public:
	MenuItem() = delete;

	MenuItem(int fName = -1);

	void setState(MENU_ITEM_STATE state_val);

	//this function will return the path to the image according to the state and index of it in the array in ToolBar
	std::string getPath();
	~MenuItem();
};
#endif
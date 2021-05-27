#ifndef MENUITEM_H
#define MENUITEM_H
#include <iostream>
#include <string>
#include "UI_Info.h"
class MenuItem
{
private:
	static const std::string BasePath;
	const int fileName; //is a number to represent the file index in the toolbar
	MENU_ITEM_STATE state; //highlighted or normal
public:
	MenuItem() = delete;
	MenuItem(int fName = -1);
	std::string getPath();
	void setState(MENU_ITEM_STATE state_val);
	~MenuItem();
};
#endif
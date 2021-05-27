#include "MenuItem.h"

MenuItem::MenuItem(int fName)
	:
	fileName(fName),
	state(MENU_ITEM_STATE::NORMAL)
{
	std::cout << "LOG: MenuItem Inialized succesfully" << std::endl;
}

const std::string MenuItem::BasePath = "images\\MenuItems\\";

std::string MenuItem::getPath()
{
	int mode = UI.InterfaceMode;
	int stat = state;
	return std::string( BasePath + char(mode) + "\\" +
						char(stat) + "\\" + std::to_string(fileName) + ".jpg");
}

void MenuItem::setState(MENU_ITEM_STATE state_val)
{
	state = state_val;
}

MenuItem::~MenuItem()
{
	std::cout << "LOG: MenuItem destructor called" << std::endl;
}

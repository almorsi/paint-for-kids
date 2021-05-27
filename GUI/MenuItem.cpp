#include "MenuItem.h"

int MenuItem::counter = 0;

MenuItem::MenuItem(int fName)
	:
	fileName(fName),
	state(MENU_ITEM_STATE::NORMAL)
{
	std::cout << "LOG" << counter++<< ": MenuItem Inialized succesfully" << std::endl;
}

const std::string MenuItem::BasePath = "images\\MenuItems\\";

std::string MenuItem::getPath()
{
	return std::string( BasePath + char(UI.InterfaceMode) + "\\" +
						char(state) + "\\" + std::to_string(fileName) + ".jpg");
}

void MenuItem::setState(MENU_ITEM_STATE state_val)
{
	state = state_val;
}

MenuItem::~MenuItem()
{
	std::cout << "LOG"<<--counter<<": MenuItem destructor called" << std::endl;
}

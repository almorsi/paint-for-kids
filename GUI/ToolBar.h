#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "MenuItem.h"

class ToolBar
{
private:

	const int nOfItems;//number of items in tool bar

	MenuItem** Items;//pointer to the items

public:
	ToolBar() = delete;

	ToolBar(int);

	MenuItem* getItem(int) const;//return the item with the given index

	~ToolBar();
};

#endif // !TOOLBAR_H


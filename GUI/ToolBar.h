#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "MenuItem.h"

class ToolBar
{
private:
	const int nOfItems;
	MenuItem** Items;
public:
	ToolBar() = delete;
	ToolBar(int);
	MenuItem* getItem(int) const;
	~ToolBar();
};

#endif // !TOOLBAR_H


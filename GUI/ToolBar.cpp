#include "ToolBar.h"
#include <assert.h>
ToolBar::ToolBar(int nItms)
	:
	nOfItems(nItms)
{

	Items = new MenuItem*[nOfItems]();//init. to null

	for (int i = 0; i < nOfItems; i++)
		Items[i] = new MenuItem(i);//initialize each item with its file name, i.e. it position

	std::cout << "LOG: Tool bar initialized" << std::endl;
}

MenuItem* ToolBar::getItem(int index) const
{
	assert(index < nOfItems && index > -1);
	return Items[index];
}

void ToolBar::hightlightItem(int index)
{
	getItem(index)->setState(HIGHLIGHTED);
}

void ToolBar::UnhightlightItem(int index)
{
	getItem(index)->setState(NORMAL);
}

ToolBar::~ToolBar()
{

	for (int i = 0; i < nOfItems; i++)
		delete Items[i];

	delete[] Items;
	std::cout << "LOG: items freed" << std::endl;
}

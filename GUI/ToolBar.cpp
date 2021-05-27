#include "ToolBar.h"
#include <assert.h>
ToolBar::ToolBar(int nItms)
	:
	nOfItems(nItms)
{
	Items = new MenuItem*[nOfItems];
	for (int i = 0; i < nOfItems; i++)
		Items[i] = new MenuItem(i);
	std::cout << "LOG: Tool bar initialized" << std::endl;
}

MenuItem* ToolBar::getItem(int index) const
{
	assert(index < nOfItems&& index > -1);
	return Items[index];
}

ToolBar::~ToolBar()
{
	for (int i = 0; i < nOfItems; i++)
		delete Items[i];
	delete[] Items;
	std::cout << "LOG: items freed" << std::endl;
}

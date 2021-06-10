#include "UI_Info.h"

/*
*	NO OFFSET WHEN CHANGING FROM SCREEN TO WORLD OR FROM WORLD TO SCREEN
*/
void worldToScreen(Point& point)
{
	point.x = int(point.x * UI.scalingFactor);
	point.y = int(point.y * UI.scalingFactor);
}

void screenToWorld(Point& point)
{
	point.x = int(point.x / UI.scalingFactor);
	point.y = int(point.y / UI.scalingFactor);
}
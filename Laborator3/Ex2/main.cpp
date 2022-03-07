#include "Canvas.h"
void main()
{
	Canvas c(80, 80);
	c.Print();
	c.DrawRect(4, 5, 8, 10, '*');
	c.FillRect(4, 5, 8, 10, '3');
	c.SetPoint(10, 49, '7');
	c.DrawCircle(15, 10, 5, '5');
	c.FillCircle(15, 10, 5, '1');
	c.DrawLine(1, 1, 4, 10, '0');
	c.Print();

}
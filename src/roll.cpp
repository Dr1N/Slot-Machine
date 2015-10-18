#include "roll.h"
#include <cstdlib>

Roll::Roll(short p)
{
	setPoint(p);
}

void Roll::setPoint(short p)
{
	p >= 0 && p <= 9 ? point = p : point = 0;
}

short Roll::rotate()
{	
	point = rand() % 10;
	return point;
}
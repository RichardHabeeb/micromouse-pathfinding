#include "cell.h"


cell::cell(void)
{
	visited = false;

	for(int i = 0; i < NUM_HEADINGS; i++)
	{
		adjacent_passages[i] = nullptr;
	}
		
}

cell::cell(int r, int c)
{
	row = r;
	col = c;
	cell();
}


cell::~cell(void)
{
}


bool cell::is_wall( heading h )
{
	return ( adjacent_passages[h] == nullptr );
}


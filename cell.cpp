#include "cell.h"


cell::cell(void)
{
	visited = false;

	for(int i = 0; i < NUM_HEADINGS; i++)
	{
		adjacent_cells[i] = nullptr;
	}
}


cell::~cell(void)
{
	for (heading h = north; h < NUM_HEADINGS; h++)
	{
		if (adjacent_cells[h] != nullptr)
			delete[] adjacent_cells;
	}		
}


bool cell::IsWall(heading h)
{
	return ( adjacent_cells[ h ] == nullptr );
}


void cell::set_wall( heading h )
{
	if (!IsWall(h))
	{
		adjacent_cells[ h ]->adjacent_cells[ get_reverse_heading( h ) ] = nullptr;
		adjacent_cells[ h ] = nullptr;
	}	
}


cell* cell::get_adjacent_cell( heading h )
{
	return adjacent_cells[ h ];
}


void cell::set_adjacent_cell( heading h, cell* c )
{
	if(c != nullptr)
		c->adjacent_cells[get_reverse_heading(h)] = this;
	adjacent_cells[ h ] = c;
}
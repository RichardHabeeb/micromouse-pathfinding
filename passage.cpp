#include "passage.h"


passage::passage(void)
{
	time = 1;
	end_cells[0] = nullptr;
	end_cells[1] = nullptr;
}

passage::passage(cell* a, cell* b)
{
	time = 1;
	end_cells[0] = a;
	end_cells[1] = b;
}

passage::~passage(void)
{
}


cell* passage::next_cell(cell* origin, cell* destination)
{
	if( end_cells[0] == origin )
		return end_cells[1];

	return end_cells[0];
}
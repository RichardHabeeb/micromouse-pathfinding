#include "maze.h"


maze::maze(int num_rows, int num_cols)
{
	cell_index = new cell**[num_cols];
	for( int r; r < num_rows; r++ )
	{
		cell_index[r]= new cell*[num_cols];
		for( int c; c < num_cols; c++)
		{
			cell_index[r][c] = new cell();
		}
	}
}


maze::~maze(void)
{
}
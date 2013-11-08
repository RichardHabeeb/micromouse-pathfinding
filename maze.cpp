#include "maze.h"


maze::maze(int _num_rows, int _num_cols)
{
	num_rows = _num_rows;
	num_cols = _num_cols;
	
	cell_index = new cell**[num_rows];
	for (int r = 0; r < num_rows; r++)
	{
		cell_index[r]= new cell*[num_cols];
		for (int c = 0; c < num_cols; c++)
		{
			cell_index[r][c] = new cell();

			if (c > 0)
			{
				cell_index[r][c]->set_adjacent_cell(west, cell_index[r][c - 1]);
			}

			if (r > 0) 
			{
				cell_index[r][c]->set_adjacent_cell(north, cell_index[r - 1][c]);
			}
		}
	}
}


maze::~maze(void)
{
}


bool maze::is_valid_cell(int r, int c)
{
	return (r < num_rows && r >= 0 && c < num_cols && c >= 0);
}

cell* maze::get_cell(int r, int c)
{
	if (is_valid_cell(r,c))
		return cell_index[r][c];
	else
		return nullptr;
}

cell* maze::get_starting_cell(void)
{
	return starting_cell;
}

void maze::set_starting_cell(cell* c)
{
	starting_cell = c;
}

void maze::set_starting_cell(int r, int c)
{
	starting_cell = cell_index[r][c];
}

cell* maze::get_goal_cell(void)
{
	return goal_cell;
}

void maze::set_goal_cell(cell* c)
{
	goal_cell = c;
}

void maze::set_goal_cell(int r, int c)
{
	goal_cell = cell_index[r][c];
}

bool maze::is_goal_cell(int r, int c)
{
	return cell_index[r][c] == goal_cell;
}

bool maze::is_goal_cell(cell* c)
{
	return c == goal_cell;
}

void maze::swap_starting_and_goal(void)
{
	cell* t = starting_cell;
	starting_cell = goal_cell;
	goal_cell = t;
}


char* maze::to_string(void)
{
	char* s = new char[num_rows*(num_cols*(NUM_HEADINGS + 1) + 1)];
	int write_index = 0;
	char heading_names[] = "NESW";

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			for (heading h = north; h < NUM_HEADINGS; h++) 
			{
				s[write_index++] = (cell_index[r][c]->is_wall(h)) ? heading_names[h] : ' ';
			}
			s[write_index++] = is_goal_cell(r,c) ? '#' : '|';
		}
		s[write_index++] = '\n';
	}
	s[write_index] = '\0';
	return s;
}
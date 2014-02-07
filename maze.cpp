#include "maze.h"


maze::maze
	(
		int					num_rows, 
		int					num_cols
	) :
	num_rows(num_rows),
	num_cols(num_cols)
{
	
	cell_index				= new cell**[num_rows];

	for (int r = 0; r < num_rows; r++)
	{
		cell_index[r]= new cell*[num_cols];
		for (int c = 0; c < num_cols; c++)
		{
			cell_index[r][c] = new cell();
			cell_index[r][c]->set_value(0);
			cell_index[r][c]->set_visited(false);

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
	Map(ResetCellValue);
}



maze::~maze
	(
		void
	)
{
	delete cell_index;
}



bool maze::is_valid_cell
	(
		int		r, 
		int		c
	)
{
	return (r < num_rows && r >= 0 && c < num_cols && c >= 0);
}



cell* maze::get_cell
	(
		int r,
		int c
	)
{
	if (is_valid_cell(r,c))
		return cell_index[r][c];
	else
		return nullptr;
}



bool maze::IsGoalCell
	(
		int r,
		int c
	)
{
	return cell_index[r][c] == goal_cell;
}



bool maze::IsGoalCell
	(
		cell* c
	)
{
	return c == goal_cell;
}



void maze::SwapStartingAndGoal
(
	void
)
{
	cell* t = starting_cell;
	starting_cell = goal_cell;
	goal_cell = t;
}



char* maze::ToString
	(
		void
	)
{
	char* s = new char[num_rows*(num_cols*(NUM_HEADINGS + 4) + 1)];
	int write_index = 0;
	char heading_names[] = "NESW";

	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			for (heading h = north; h < NUM_HEADINGS; h++) 
			{
				s[write_index++] = (cell_index[r][c]->IsWall(h)) ? heading_names[h] : ' ';
			}
			s[write_index++] = (cell_index[r][c]->get_visited()) ? '!' : ' ';
			s[write_index++] = '0' + cell_index[r][c]->get_value() / 10;
			s[write_index++] = '0' + cell_index[r][c]->get_value() % 10;
			s[write_index++] = IsGoalCell(r,c) ? '#' : '|';
		}
		s[write_index++] = '\n';
	}
	s[write_index] = '\0';
	return s;
}



void maze::ResetCellValue
	(
		cell* c
	)
{
	c->set_value(0);
}


void maze::ResetCellData
(
cell* c
)
{
	c->set_value(0);
}


void maze::Map
	(
		void (*func)(cell*)
	)
{
	for (int r = 0; r < num_rows; r++)
	{
		for (int c = 0; c < num_cols; c++)
		{
			(*func)(cell_index[r][c]);
		}
	}
}
#include "SimpleFloodFill.h"


SimpleFloodFill::SimpleFloodFill
	(
		maze* m
	)
{
	this->m = m;
}


SimpleFloodFill::~SimpleFloodFill
	(
		void
	)
{

}


unsigned int SimpleFloodFill::CalculateBestRoute
	(
		heading*				path,
		unsigned int			path_len,
		unsigned int			robot_current_row,
		unsigned int			robot_current_col,
		heading					robot_current_heading
	)
{
	cell* start_cell			= m->get_cell(robot_current_row, robot_current_col);
	cell* goal_cell				= m->get_goal_cell();
	max_flood_depth				= path_len;
	unsigned int path_index		= 0;
	unsigned int depth			= FloodFill();


	if (depth == max_flood_depth)
		return max_flood_depth;

	do
	{
		for (unsigned char i = 0; i < NUM_HEADINGS; i++)
		{
			heading h = (robot_current_heading + i)%NUM_HEADINGS;
			cell* adjacent_cell = start_cell->get_adjacent_cell(h);

			if (adjacent_cell != nullptr && adjacent_cell->get_value() == depth - 1)
			{
				path[path_index++] = h;
				robot_current_heading = h;
				start_cell = adjacent_cell;
				break;
			}
		}
	} while (start_cell != goal_cell && --depth > 0);

	return path_index;

}


unsigned int SimpleFloodFill::FloodFill
	(
		void
	)
{
	cell* start_cell			= m->get_starting_cell();
	cell* goal_cell				= m->get_goal_cell();
	int num_rows				= m->get_num_rows();
	int num_cols				= m->get_num_cols();
	unsigned int depth			= 1;

	m->Map(maze::ResetCellValue);

	goal_cell->set_value(1);

	while (++depth < max_flood_depth)
	{
		for (int r = 0; r < num_rows ; r++)
		{
			for (int c = 0; c < num_cols; c++)
			{
				cell* search_cell = m->get_cell(r, c);
				if (search_cell->get_value() == 0)
				{
					for (heading h = north; h < NUM_HEADINGS; h++)
					{
						cell* adjacent_cell = search_cell->get_adjacent_cell(h);

						if (adjacent_cell != nullptr && adjacent_cell->get_value() == depth - 1)
						{
							search_cell->set_value(depth);
							if (search_cell == start_cell)
								return depth;
						}
					}
				}
			}
		}
	} 

	return max_flood_depth;
}
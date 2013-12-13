#include "WeightedPathfinding.h"


WeightedPathfinding::WeightedPathfinding(maze* m)
{
	this->m = m;
}


WeightedPathfinding::~WeightedPathfinding()
{
}

unsigned int WeightedPathfinding::CalculateBestRoute
	(
		heading*			path,
		unsigned int		path_len,
		unsigned int		robot_current_row,
		unsigned int		robot_current_col,
		heading				robot_current_heading
	)
{
	cell* start_cell = m->get_cell(robot_current_row, robot_current_col);
	cell* goal_cell = m->get_goal_cell();


	cell_q.Reset()->Enqueue(start_cell);


	while (cell_q.get_count() > 0)
	{
		cell* current_cell = cell_q.Dequeue();
		for (heading h = north; h < NUM_HEADINGS; h++)
		{
			cell* adjacent_cell = current_cell->get_adjacent_cell(h);

			int time_to_adjacent_cell = current_cell->get_value(); //+ unknown hueristic

			if (adjacent_cell != nullptr && 
				adjacent_cell->get_value() > time_to_adjacent_cell)
			{
				adjacent_cell->set_value(time_to_adjacent_cell);
				cell_q.Enqueue(adjacent_cell);
			}
		}
	}

	return 0;
}
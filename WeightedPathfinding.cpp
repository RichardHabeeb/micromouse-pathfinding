#include "WeightedPathfinding.h"


WeightedPathfinding::WeightedPathfinding
	(
		maze* m
	)
{
	this->m = m;
	maze_max_dim = Maximum(m->get_num_cols(), m->get_num_rows());

}


WeightedPathfinding::~WeightedPathfinding
	()
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
		cell*				current_cell			= cell_q.Dequeue();
		cell_data_t*		current_cell_data		= (cell_data_t*)current_cell->get_data();
		
		for (heading h = north; h < NUM_HEADINGS; h++)
		{
			cell*			adjacent_cell			= current_cell->get_adjacent_cell(h);
			cell_data_t*	adjacent_cell_data		= (cell_data_t*)adjacent_cell->get_data();

			unsigned int new_weight = current_cell_data->weight
				+ (h != current_cell_data->robot_heading_sim)*TURN_WEIGHT
				+ (adjacent_cell->get_visited()) ? VISITED_STEP_WEIGHT : STEP_WEIGHT;

			if (adjacent_cell != nullptr 
				&& adjacent_cell_data->weight < new_weight)
			{
				adjacent_cell_data->weight				= new_weight;
				adjacent_cell_data->robot_heading_sim	= h;
				adjacent_cell_data->prev_cell			= current_cell;
				cell_q.Enqueue(adjacent_cell);
			}
		}
	}

	return 0;
}



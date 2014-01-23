#include "WeightedPathfinding.h"


WeightedPathfinding::WeightedPathfinding
	(
		maze* m
	)
{
	this->m = m;
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
		
		for (heading h = north; h < NUM_HEADINGS; h++)
		{
			cell*			adjacent_cell			= current_cell->get_adjacent_cell(h);
			cell_data_t*	adjacent_cell_data		= (cell_data_t*)adjacent_cell->get_data();
			cell_data_t		new_adjacent_cell_data	= CalculateStepWeight(current_cell, h);

			if (adjacent_cell != nullptr && 
				adjacent_cell_data->weight > new_adjacent_cell_data.weight)
			{
				adjacent_cell_data->weight			= new_adjacent_cell_data.weight;
				adjacent_cell_data->cells_traveled	= new_adjacent_cell_data.cells_traveled;
				adjacent_cell_data->curr_head		= new_adjacent_cell_data.curr_head;
				cell_q.Enqueue(adjacent_cell);
			}
		}
	}

	return 0;
}


cell_data_t WeightedPathfinding::CalculateStepWeight
	(
		cell*				step_origin,
		heading				step_heading
	)
{
	cell_data_t ret;
	cell_data_t* origin_cell_data = (cell_data_t*)step_origin->get_data();
	//d = v*t;
	//d = at ^ 2 + v0t
	// 0 = a*t^2 + v_0*t - d
	// t = -v_0/2/a +/- sqrt(v_0^2 - 4*a*d)/2/a

	//int acceleration = (1/MIN_CELL_TIME - 1/MAX_CELL_TIME) / ACCELERATION_TIME; //this is always zero... because ints
	//int time_to_this_cell = -1 / (2* MAX_CELL_TIME )
	//int	current_velocity = acceleration * time_to_this_cell;



	//origin_cell_data->cells_traveled*

	//(origin_cell_data->curr_head - step_heading)*TURN_TIME;

	ret.cells_traveled = (step_heading == origin_cell_data->curr_head) ? origin_cell_data->cells_traveled + 1 : 0;
	ret.curr_head = step_heading;
	ret.weight = origin_cell_data->weight + 100; //this is where the magic needs to happen

	return ret;
}
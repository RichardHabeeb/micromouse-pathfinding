#include "WeightedPathfinding.h"


WeightedPathfinding::WeightedPathfinding
	(
		maze* m
	)
{
	m->Map(WeightedPathfinding::InitializeCellData);
	maze_max_dim = Maximum(m->get_num_cols(), m->get_num_rows());
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
	cell* start_cell	= m->get_cell(robot_current_row, robot_current_col);
	cell* goal_cell		= m->get_goal_cell();

	m->Map(WeightedPathfinding::ResetCellData);
	((cell_data_t*)start_cell->get_data())->robot_heading_sim = robot_current_heading;
	((cell_data_t*)start_cell->get_data())->weight = 0;

	cell_q.Reset()->Enqueue(start_cell);

	while (cell_q.get_count() > 0)
	{
		cell*				current_cell			= cell_q.Dequeue();
		cell_data_t*		current_cell_data		= (cell_data_t*)current_cell->get_data();
		
		for (heading h = north; h < NUM_HEADINGS; h++)
		{
			cell*			adjacent_cell			= current_cell->get_adjacent_cell(h);
			if (adjacent_cell != nullptr)
			{

				cell_data_t*	adjacent_cell_data = (cell_data_t*)adjacent_cell->get_data();

				int new_weight = current_cell_data->weight
					+ (HeadingDistance(h, current_cell_data->robot_heading_sim)*TURN_WEIGHT)
					+ ((adjacent_cell->get_visited()) ? VISITED_STEP_WEIGHT : STEP_WEIGHT);

				if (adjacent_cell != nullptr
					&& (adjacent_cell_data->weight > new_weight
						|| adjacent_cell_data->weight == INITIAL_WEIGHT))
				{
					adjacent_cell_data->weight				= new_weight;
					adjacent_cell_data->robot_heading_sim	= h;
					adjacent_cell_data->prev_cell			= current_cell;
					cell_q.Enqueue(adjacent_cell);
				}
			}
		}
	}


	cell* current_cell	= goal_cell;
	unsigned int j, i	= 0;

	while (current_cell != nullptr && current_cell != start_cell)
	{
		path[i++]		= ((cell_data_t*)current_cell->get_data())->robot_heading_sim;
		current_cell	= ((cell_data_t*)current_cell->get_data())->prev_cell;
	}
	i--;

	for (j = 0; j <= (i/2); j++)
	{
		heading temp	= path[j];
		path[j]			= path[i - j];
		path[i - j]		= temp;
	}
	
	return i+1;
}


char* WeightedPathfinding::ToString
	(void)
{
	char* s = new char[m->get_num_rows()*(m->get_num_cols()*(NUM_HEADINGS + 4) + 1)];
	int write_index = 0;
	char heading_names[] = "NESW";

	for (int r = 0; r < m->get_num_rows(); r++)
	{
		for (int c = 0; c < m->get_num_cols(); c++)
		{
			for (heading h = north; h < NUM_HEADINGS; h++)
			{
				s[write_index++] = (m->get_cell(r,c)->IsWall(h)) ? heading_names[h] : ' ';
			}
			s[write_index++] = (m->get_cell(r, c)->get_visited()) ? '!' : ' ';
			s[write_index++] = '0' + ((cell_data_t*)m->get_cell(r, c)->get_data())->weight / 10;
			s[write_index++] = '0' + ((cell_data_t*)m->get_cell(r, c)->get_data())->weight % 10;
			s[write_index++] = m->IsGoalCell(r, c) ? '#' : '|';
		}
		s[write_index++] = '\n';
	}
	s[write_index] = '\0';
	return s;
}


void WeightedPathfinding::InitializeCellData
	(
		cell* c
	)
{
	cell_data_t* d			= new cell_data_t();
	d->prev_cell			= nullptr;
	d->robot_heading_sim	= north;
	d->weight				= INITIAL_WEIGHT;
	c->set_data(d);
}

void WeightedPathfinding::ResetCellData
	(
	cell* c
	)
{
	cell_data_t* d			= (cell_data_t*) c->get_data();
	d->prev_cell			= nullptr;
	d->robot_heading_sim	= north;
	d->weight				= INITIAL_WEIGHT;
}
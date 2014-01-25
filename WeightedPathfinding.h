#pragma once
#include "IPathFinding.h"
#include "util_math.h"
#include "Queue.h"


/***********************************************
 * Algorithm Constants 
 * (used for speedup estimates)
 ***********************************************/
#define			STEP_WEIGHT			100
#define			VISITED_STEP_WEIGHT	50
#define			TURN_WEIGHT			200		//ms (time to turn the robot 90 degrees)


typedef struct 
{
	int					weight;
	heading				robot_heading_sim;
	cell*				prev_cell;
} cell_data_t;


class WeightedPathfinding :
	public IPathFinding
{
public:
	WeightedPathfinding
		(
		maze* m
		);

	~WeightedPathfinding();

	unsigned int CalculateBestRoute
		(
		heading*			path,
		unsigned int		path_len,
		unsigned int		robot_current_row,
		unsigned int		robot_current_col,
		heading				robot_current_heading
		);


private:
	cell_data_t CalculateStepWeight
		(
		cell*				step_origin,
		heading				step_heading
		);


public:
private:
	Queue<cell>		cell_q;
	unsigned int	max_flood_depth;
	maze*			m;
	unsigned int	maze_max_dim;
};


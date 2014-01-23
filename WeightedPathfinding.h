#pragma once
#include "IPathFinding.h"
#include "Queue.h"


/***********************************************
 * Algorithm Constants 
 * (used for speedup estimates)
 ***********************************************/
#define			TURN_TIME			500		//ms (time to turn the robot 90 degrees)
#define			MAX_CELL_TIME		100		//ms (fastest possible cell-to-cell travel time
#define			MIN_CELL_TIME		1000	//ms (slowest possible cell-to-cell travel time
#define			ACCELERATION_TIME	1500	//ms (time to get to full speed


typedef struct 
{
	int					weight;
	heading				curr_head;
	unsigned int		cells_traveled;
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
	Queue<cell>	cell_q;
	unsigned int max_flood_depth;
	maze* m;
};


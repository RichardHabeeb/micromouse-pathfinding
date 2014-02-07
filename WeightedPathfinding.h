#pragma once
#include "IPathFinding.h"
#include "util_math.h"
#include "Queue.h"


/***********************************************
 * Algorithm Constants 
 * (used for speedup estimates)
 ***********************************************/
#define			STEP_WEIGHT			2
#define			VISITED_STEP_WEIGHT	1
#define			TURN_WEIGHT			4
#define			INITIAL_WEIGHT		-1


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

	char* ToString
		(void);


private:
	static void InitializeCellData
		(
		cell *
		);

	static void WeightedPathfinding::ResetCellData
		(
		cell *
		);

public:
private:
	Queue<cell>		cell_q;
	unsigned int	max_flood_depth;
	maze*			m;
	unsigned int	maze_max_dim;
};


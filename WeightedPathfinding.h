#pragma once
#include "IPathFinding.h"
#include "Queue.h"

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
	unsigned int			FloodFill();


public:
private:
	Queue<cell>	cell_q;
	unsigned int max_flood_depth;
	maze* m;
};


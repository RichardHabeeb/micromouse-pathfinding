#pragma once
#include "IPathFinding.h"


class SimpleFloodFill :
	public IPathFinding
{

public:
	SimpleFloodFill
	(
		maze* m
	);

	~SimpleFloodFill
	(
		void
	);

	unsigned int			CalculateBestRoute
	(
		heading*			path,
		unsigned int		path_len,
		unsigned int		robot_current_row,
		unsigned int		robot_current_col,
		heading				robot_current_heading
	);


private:
	unsigned int			FloodFill
	(
		void
	);


public:


private:
	unsigned int			max_flood_depth;
	maze*					m;


};


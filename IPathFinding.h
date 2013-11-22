#pragma once
#include "maze.h"

class IPathFinding
{
public:
	virtual ~IPathFinding
		(
		void
		)
	{};


	virtual unsigned int CalculateBestRoute
	(
		heading*			path,
		unsigned int		path_len, 
		unsigned int		robot_current_row,
		unsigned int		robot_current_col, 
		heading				robot_current_heading
	) = 0;

};


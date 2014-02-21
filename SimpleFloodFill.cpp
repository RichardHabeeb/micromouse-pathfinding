/****************************************************************************************
* File: Maze.cpp
*
* Description: Implementation of the maze class methods
*
* Created: 2/20/2014, by Richard Habeeb
****************************************************************************************/

/*---------------------------------------------------------------------------------------
*                                       INCLUDES
*--------------------------------------------------------------------------------------*/
#include "simplefloodfill.h"

/*---------------------------------------------------------------------------------------
*                                   LITERAL CONSTANTS
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                        TYPES
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                   MEMORY CONSTANTS
---------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                      VARIABLES
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                    CLASS METHODS
*--------------------------------------------------------------------------------------*/


SimpleFloodFill::SimpleFloodFill
	(
		Maze* m
	)
{
	this->m = m;
}


SimpleFloodFill::~SimpleFloodFill
	(
		void
	)
{

}


void SimpleFloodFill::FindNextPathSegment
	(
		unsigned int		robot_current_row, // the current row of the robot
		unsigned int		robot_current_col,  // the current col of the robot
		heading_t			robot_current_heading, // the current heading of the robot
		heading_t*			next_heading, //out param of the next heading to travel
		unsigned int*		cells_to_travel // out param of the number of cells to travel in the given direction
	)
{
	Cell* start_cell			= m->get_cell(robot_current_row, robot_current_col);
	Cell* goal_cell				= m->get_goal_cell();
	max_flood_depth				= path_size;
	unsigned int path_index		= 0;
	unsigned int depth			= FloodFill();


	if (depth == max_flood_depth)
		return max_flood_depth;

	do
	{
		for (unsigned char i = 0; i < NUM_HEADINGS; i++)
		{
			heading_t h = (robot_current_heading + i)%NUM_HEADINGS;
			Cell* adjacent_cell = start_cell->get_adjacent_cell(h);

			if (adjacent_cell != nullptr && adjacent_cell->get_value() == depth - 1)
			{
				path[path_index++] = h;
				robot_current_heading = h;
				start_cell = adjacent_cell;
				break;
			}
		}
	} while (start_cell != goal_cell && --depth > 0);

	return path_index;

}


unsigned int SimpleFloodFill::FloodFill
	(
		void
	)
{
	Cell* start_cell			= m->get_starting_cell();
	Cell* goal_cell				= m->get_goal_cell();
	unsigned int depth			= 1;

	m->Map(SimpleFloodFill::ResetCellData);

	*((int*)goal_cell->get_data()) = 1;

	while (++depth < max_flood_depth)
	{
		for (int r = 0; r < MAZE_NUM_ROWS ; r++)
		{
			for (int c = 0; c < MAZE_NUM_COLS; c++)
			{
				Cell* search_cell = m->get_cell(r, c);
				if (*((int*)search_cell->get_data()) == 0)
				{
					for (heading_t h = north; h < NUM_HEADINGS; h++)
					{
						Cell* adjacent_cell = search_cell->get_adjacent_cell(h);

						if (adjacent_cell != nullptr && *((int*)adjacent_cell->get_data()) == depth - 1)
						{
							search_cell->set_value(depth);
							if (search_cell == start_cell)
								return depth;
						}
					}
				}
			}
		}
	} 

	return max_flood_depth;
}


void SimpleFloodFill::InitializeCellData
	(
		Cell* c
	)
{
	c->set_data( new int );
}

void SimpleFloodFill::ResetCellData
	(
		Cell* c
	)
{
	*((int*)c->get_data()) = INITIAL_VALUE;
}
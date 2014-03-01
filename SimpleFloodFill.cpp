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

/*****************************************************************************
* Function: SimpleFloodFill - Constructor
*
* Description: Allocates and initializes the cell data
*****************************************************************************/
SimpleFloodFill::SimpleFloodFill
	(
		Maze* m
	)
{
	m->Map(InitializeCellData);
	this->m = m;
} // SimpleFloodFill()


/*****************************************************************************
* Function: WeightedPathfinding - Destructor
*
* Description:
*****************************************************************************/
SimpleFloodFill::~SimpleFloodFill
	(
		void
	)
{

}


/*****************************************************************************
* Function: FindNextPathSegment
*
* Description:	Compute the fastest route throught the maze. Simulate maze
*				solutions and ouput the next heading and the number of cells
*				to travel forward to get to that turn.
*****************************************************************************/
void SimpleFloodFill::FindNextPathSegment
	(
		unsigned int		robot_current_row, // the current row of the robot
		unsigned int		robot_current_col,  // the current col of the robot
		heading_t			robot_current_heading, // the current heading of the robot
		heading_t*			next_heading, //out param of the next heading to travel
		unsigned int*		cells_to_travel // out param of the number of cells to travel in the given direction
	)
{
	Cell* start_cell								= m->get_cell(robot_current_row, robot_current_col);
	Cell* goal_cell									= m->get_goal_cell();
	unsigned int path_index							= 0;
	unsigned int cells_traveled_in_current_heading	= 0;
	unsigned int depth								= FloodFill();

	if (depth == MAX_FLOOD_DEPTH) return;

	do
	{
		for (unsigned char i = 0; i < NUM_HEADINGS; i++)
		{
			heading_t h				= (robot_current_heading + i) % NUM_HEADINGS;
			Cell* adjacent_cell		= start_cell->get_adjacent_cell(h);

			if (adjacent_cell != nullptr && *((int*)adjacent_cell->get_data()) == depth - 1)
			{
				cells_traveled_in_current_heading	= (robot_current_heading == h) ? cells_traveled_in_current_heading + 1 : 0;
				robot_current_heading				= h;
				start_cell							= adjacent_cell;
				break;

			}
		}
	} while (start_cell != goal_cell && --depth > 0);

} // FindNextPathSegment()


/*****************************************************************************
* Function: FloodFill
*
* Description:	Run a simplistic flooding algorithm.
*****************************************************************************/
unsigned int SimpleFloodFill::FloodFill(void)
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
							*((int*)search_cell->get_data()) = depth;
							if (search_cell == start_cell)
								return depth;
						}
					}
				}
			}
		}
	} 

	return max_flood_depth;
} // FloodFill()


/*****************************************************************************
* Function: ToString
*
* Description:	For debugging. Print the maze walls with cell data, will
*				allocate memory on the heap
*****************************************************************************/
char* SimpleFloodFill::ToString(void)
{
	char* s = new char[MAZE_NUM_ROWS*(MAZE_NUM_COLS*(NUM_HEADINGS + 4) + 1)];
	int write_index = 0;
	char heading_names[] = "NESW";

	for (int r = 0; r < MAZE_NUM_ROWS; r++)
	{
		for (int c = 0; c < MAZE_NUM_COLS; c++)
		{
			for (heading_t h = north; h < NUM_HEADINGS; h++)
			{
				s[write_index++] = (m->get_cell(r, c)->IsWall(h)) ? heading_names[h] : ' ';
			}
			s[write_index++] = (m->get_cell(r, c)->get_visited()) ? '!' : ' ';
			s[write_index++] = '0' + *((int*)m->get_cell(r, c)->get_data()) / 10;
			s[write_index++] = '0' + *((int*)m->get_cell(r, c)->get_data()) % 10;
			s[write_index++] = m->IsGoalCell(r, c) ? '#' : '|';
		}
		s[write_index++] = '\n';
	}
	s[write_index] = '\0';
	return s;
} // ToString()


/*****************************************************************************
* Function: InitializeCellData
*
* Description:	allocate and assign cell data structs into all the cells
*				of the maze
*****************************************************************************/
void SimpleFloodFill::InitializeCellData
	(
		Cell* c
	)
{
	c->set_data( new int );
}


/*****************************************************************************
* Function: InitializeCellData
*
* Description:	reset all cell data to the default weight
*****************************************************************************/
void SimpleFloodFill::ResetCellData
	(
		Cell* c
	)
{
	*((int*)c->get_data()) = INITIAL_VALUE;
}
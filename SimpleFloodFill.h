/****************************************************************************************
* File: simplefloodfill.h
*
* Description: Interface definition for pathfindign algos
*
* Created: 2/20/2014, by Richard Habeeb
****************************************************************************************/

#ifndef SIMPLEFLOODFILL_INCLUDED_H
#define SIMPLEFLOODFILL_INCLUDED_H

/*---------------------------------------------------------------------------------------
*                                       INCLUDES
*--------------------------------------------------------------------------------------*/
#include "ipathfinding.h"
#include "maze.h"

/*---------------------------------------------------------------------------------------
*                                      CONSTANTS
*--------------------------------------------------------------------------------------*/
#define INITIAL_VALUE 0;
/*---------------------------------------------------------------------------------------
*                                        TYPES
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                       CLASSES
*--------------------------------------------------------------------------------------*/

/******************************************************************************
* Class: SimpleFloodFill
*
* Description:	
******************************************************************************/
class SimpleFloodFill :
	public IPathFinding
{
public: //methods

	SimpleFloodFill
	(
		Maze* m
	);

	~SimpleFloodFill(void);
	
	// Compute the fastest route throught the maze
	void FindNextPathSegment
	(
		unsigned int		robot_current_row, // the current row of the robot
		unsigned int		robot_current_col,  // the current col of the robot
		heading_t			robot_current_heading, // the current heading of the robot
		heading_t*			next_heading, //out param of the next heading to travel
		unsigned int*		cells_to_travel // out param of the number of cells to travel in the given direction
	);

public: // fields


private: // methods

	// Run a classic flooding algorithm to fill in the maze
	unsigned int FloodFill(void);

	// create an instance of the cell data in each cell
	static void InitializeCellData
	(
		Cell*
	);

	// reset the value within the cell data
	static void ResetCellData
	(
		Cell*
	);


private: // fields
	unsigned int			max_flood_depth;
	Maze*					m;


};

#endif // SIMPLEFLOODFILL_INCLUDED_H
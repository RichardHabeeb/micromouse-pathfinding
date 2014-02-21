/****************************************************************************************
* File: ipathfinding.h
*
* Description: Interface definition for pathfindign algos
*
* Created: 2/20/2014, by Richard Habeeb
****************************************************************************************/

#ifndef IPATHFINDING_INCLUDED_H
#define IPATHFINDING_INCLUDED_H

/*---------------------------------------------------------------------------------------
*                                       INCLUDES
*--------------------------------------------------------------------------------------*/
#include "maze.h"

/*---------------------------------------------------------------------------------------
*                                      CONSTANTS
*--------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------------
*                                        TYPES
*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------
*                                       CLASSES
*--------------------------------------------------------------------------------------*/

/******************************************************************************
* Class: IPathFinding
*
* Description:	An interface for creating pathfinding algorithms
******************************************************************************/
class IPathFinding
{
public:

	virtual ~IPathFinding(void) {};

	// Compute the fastest route throught the maze
	virtual void FindNextPathSegment
	(
		unsigned int		robot_current_row, // the current row of the robot
		unsigned int		robot_current_col,  // the current col of the robot
		heading_t			robot_current_heading, // the current heading of the robot
		heading_t*			next_heading, //out param of the next heading to travel
		unsigned int*		cells_to_travel // out param of the number of cells to travel in the given direction
	) = 0;

};

#endif // IPATHFINDING_INCLUDED_H
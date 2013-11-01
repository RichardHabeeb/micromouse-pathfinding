#pragma once
#include "cell.h"

class maze
{
public:
	maze(int, int);
	~maze(void);

	cell*	get_cell(int, int);
	cell*	get_starting_cell( void );
	void	set_starting_cell( cell* );
	cell*	get_goal_cell( void );
	void	set_goal_cell( cell* );
	void	swap_starting_and_goal( void );

private:
	cell*** cell_index;
};


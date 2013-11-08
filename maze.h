#pragma once
#include "cell.h"

class maze
{
public:
	maze(int, int);
	~maze(void);

	bool	is_valid_cell(int, int);
	cell*	get_cell(int, int);
	cell*	get_starting_cell( void );
	void	set_starting_cell(int, int);
	void	set_starting_cell(cell*);
	cell*	get_goal_cell( void );
	void	set_goal_cell(int, int);
	void	set_goal_cell(cell*);
	bool	is_goal_cell(cell*);
	bool	is_goal_cell(int, int);
	void	swap_starting_and_goal( void );
	char*	to_string( void );

private:
	int		num_rows;
	int		num_cols;
	cell*	starting_cell;
	cell*	goal_cell;
	cell*** cell_index;
};


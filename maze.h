#pragma once
#include "cell.h"

class maze
{
public:
	maze(int, int);
	~maze(void);

	bool	is_valid_cell(int, int);
	cell*	get_cell(int, int);
	int		get_num_rows(void) { return num_rows; }
	void	set_num_rows(int r) { num_rows = r;  }
	int		get_num_cols(void) { return num_cols; }
	void	set_num_cols(int c) { num_cols = c; }
	cell*	get_starting_cell( void );
	void	set_starting_cell(int, int);
	void	set_starting_cell(cell*);
	cell*	get_goal_cell( void );
	void	set_goal_cell(int, int);
	void	set_goal_cell(cell*);
	bool	is_goal_cell(cell*);
	bool	is_goal_cell(int, int);
	void	swap_starting_and_goal( void );
	void	map(void(*func)(cell*));
	char*	to_string( void );


	static void		reset_cell_value(cell*);

private:
	int		num_rows;
	int		num_cols;
	cell*	starting_cell;
	cell*	goal_cell;
	cell*** cell_index;
};


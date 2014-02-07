#pragma once
#include "cell.h"

class maze
{
public:
	maze
	(
		int _num_rows,
		int _num_cols
	);


	~maze
	(
		void
	);


	bool is_valid_cell
	(
		int		r,
		int		c
	);


	cell* get_cell
	(
		int r,
		int c
	);


	int	get_num_rows
	(
		void
	) const
	{ 
		return num_rows; 
	}


	void set_num_rows
	(
		int r
	)
	{
		num_rows = r;  
	}


	int get_num_cols
	(
		void
	) const
	{ 
		return num_cols; 
	}


	void set_num_cols
	(
		int c
	) 
	{
		num_cols = c;
	}


	cell* get_starting_cell
	(
		void
	) const
	{
		return starting_cell;
	};


	void set_starting_cell
	(
		int r,
		int c
	)
	{
		starting_cell = cell_index[r][c];
	}


	cell* get_goal_cell
	(
		void
	) const
	{
		return goal_cell;
	}


	void set_goal_cell
	(
		int r,
		int c
	)
	{
		goal_cell = cell_index[r][c];
	}

	
	bool IsGoalCell
	(
		cell*
	);


	bool IsGoalCell
	(
		int r,
		int c
	);


	void SwapStartingAndGoal
	(
		void
	);


	void Map
	(
		void (*func)(cell*)
	);


	char* ToString
	(
		void
	);


	static void	ResetCellValue
	(
		cell*
	);

	static void	ResetCellData
	(
		cell*
	);


private:

	int		num_rows;
	int		num_cols;
	cell*	starting_cell;
	cell*	goal_cell;
	cell*** cell_index;


};


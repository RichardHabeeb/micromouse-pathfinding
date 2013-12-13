#pragma once
typedef unsigned char heading;
enum
{
	north,
	east,
	south, 
	west,
	NUM_HEADINGS,
};

#define get_reverse_heading( h )	( h+2 ) % NUM_HEADINGS


class cell
{
public:
	cell
	(
		void
	);


	~cell
	(
		void
	);
	

	void set_wall
	(
		heading h
	);


	cell* get_adjacent_cell
	(
		heading
	);


	void set_adjacent_cell
	(
		heading h,
		cell* c
	);


	bool get_visited
	(
		void
	) const
	{
		return visited;
	}


	void set_visited
	(
		bool v
	)
	{
		visited = v;
	}


	int	 get_value
	(
		void
	) const
	{
		return value;
	}


	void set_value
	(
		short int v
	)
	{
		value = v;
	}

	bool IsWall
	(
		heading h
	);


private:
	cell*			adjacent_cells[4];
	unsigned int	value;
	void*			data;
	bool			visited;
};

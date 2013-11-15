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
				cell(void);
				~cell(void);
	bool		is_wall(heading);
	void		set_wall(heading);
	cell*		get_adjacent_cell(heading);
	void		set_adjacent_cell(heading, cell*);
	bool		get_visited(void)		{ return visited; }
	void		set_visited(bool v)		{ visited = v; }
	int			get_value(void)			{ return value; }
	void		set_value(short int v)	{ value = v; }

	

private:
	cell*			adjacent_cells[4];
	unsigned int	value;
	bool			visited;
};

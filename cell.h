#pragma once

typedef enum
{
	north,
	east,
	south, 
	west,
	NUM_HEADINGS,
} heading;

inline heading operator++(heading &h, int)
{
	const heading _h = h;
	const int i = static_cast<int>(h);
	h = static_cast<heading>(i + 1);
	return _h;
}

#define get_reverse_heading( h )	( h+2 ) % NUM_HEADINGS


class cell
{
public:
	cell(void);
	~cell(void);
	bool	is_wall(heading);
	void	set_wall(heading);
	cell*	get_adjacent_cell(heading);
	void	set_adjacent_cell(heading, cell*);

	bool	visited;

private:
	cell* adjacent_cells[4];
};

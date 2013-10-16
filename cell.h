#pragma once

typedef enum
{
	north,
	east,
	south, 
	west,
} heading;
#define NUM_HEADINGS 4

class passage;

class cell
{
public:
	cell(void);
	cell(int, int);
	~cell(void);

	bool	is_wall(heading);
	void	set_wall(heading);
	void	set_passage(heading, passage*);
	float	get_time(heading);
	cell	adjacent_cell(heading);
	float	adjacent_cell_time(heading);
	friend bool operator== (cell &c1, cell &c2);

	bool visited;

private:
	passage* adjacent_passages[4];
	int row;
	int col;
	
};


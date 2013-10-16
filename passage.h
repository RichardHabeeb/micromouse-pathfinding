#pragma once

class cell;

class passage
{
public:
	passage(void);
	passage(cell*, cell*);
	~passage(void);
	cell* next_cell(cell*, cell*);
	float time;

private:
	cell* end_cells[2];
};

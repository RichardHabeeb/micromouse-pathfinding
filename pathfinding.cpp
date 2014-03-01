#include <iostream>
#include "SimpleFloodFill.h"
#include "WeightedPathfinding.h"
#include "maze.h"
using namespace std;

static const unsigned int longest_path = 16 * 16;

void TestPathFinding(IPathFinding* ai, Maze* m);




int main()
{
	Maze* m = new Maze();

	m->set_starting_cell(0, 0);
	m->set_goal_cell(8, 8);

	m->get_cell(0, 1)->set_wall(west);
	m->get_cell(1, 1)->set_wall(west);
	m->get_cell(2, 1)->set_wall(west);

	m->get_cell(3, 0)->set_wall(south);
	m->get_cell(3, 1)->set_wall(south);
	m->get_cell(3, 2)->set_wall(south);

	TestPathFinding(new WeightedPathfinding(m), m);
	

	return 0;
}



void TestPathFinding
	(
		IPathFinding* ai,
		Maze* m
	)
{
	heading_t next_heading;
	unsigned int num_steps_to_next_heading;

	ai->FindNextPathSegment(3, 0, south, &next_heading, &num_steps_to_next_heading);

	cout << ai->ToString() << "\n";

	cout << "next_heading: " << next_heading << "\n";
	cout << "num_steps_to_next_heading: " << num_steps_to_next_heading << "\n";


	char a[256];
	cin >> a;
}
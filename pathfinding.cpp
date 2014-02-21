#include <iostream>
#include "SimpleFloodFill.h"
#include "WeightedPathfinding.h"
#include "maze.h"
using namespace std;

static const unsigned int longest_path = 16 * 16;

void TestSimpleFloodFill();
void TestWeightedPathFinding();




int main()
{

	TestSimpleFloodFill();
	TestWeightedPathFinding();
	

	char a[256];
	cin >> a;
	return 0;
}




void TestSimpleFloodFill()
{
	maze* m = new maze(16, 16);
	IPathFinding* ai = new SimpleFloodFill(m);
	heading	paths[longest_path];


	m->set_starting_cell(0, 0);
	m->set_goal_cell(8, 8);
	cout << m->ToString() << "\n";

	unsigned int num_steps = ai->CalculateBestRoute(paths, (unsigned int)longest_path, 0, 0, north);

	cout << m->ToString() << "\n";


	for (unsigned int i = 0; i < num_steps; i++)
	{
		cout << ((paths[i] == north) ? "north" : ((paths[i] == east) ? "east" : ((paths[i] == south) ? "south" : "west")));
		cout << endl;
	}

}



void TestWeightedPathFinding()
{
	heading	paths[longest_path];
	unsigned int num_steps;
	maze* m						= new maze(16, 16);
	IPathFinding* ai			= new WeightedPathfinding(m);



	m->set_starting_cell(0, 0);
	m->set_goal_cell(8, 8);

	m->get_cell(0, 1)->set_wall(west);
	m->get_cell(1, 1)->set_wall(west);
	m->get_cell(2, 1)->set_wall(west);

	m->get_cell(3, 0)->set_wall(south);
	m->get_cell(3, 1)->set_wall(south);
	m->get_cell(3, 2)->set_wall(south);

	cout << m->ToString() << "\n";


	num_steps = ai->CalculateBestRoute(paths, (unsigned int)longest_path, 0, 0, north);

	cout << ((WeightedPathfinding*)ai)->ToString() << "\n";

	for (unsigned int i = 0; i < num_steps; i++)
	{
		cout << ((paths[i] == north) ? "north" : ((paths[i] == east) ? "east" : ((paths[i] == south) ? "south" : "west")));
		cout << endl;
	}

}
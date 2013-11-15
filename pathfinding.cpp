#include <iostream>
#include "SimpleFloodFill.h"
#include "maze.h"
using namespace std;



int main()
{
	const unsigned int longest_path = 16 * 16;

	maze* m					= new maze(16, 16);
	IPathFinding* ai		= new SimpleFloodFill(m);
	heading	paths[longest_path];


	m->set_starting_cell(0, 0);
	m->set_goal_cell(8, 8);
	cout << m->to_string() << "\n";
	
	unsigned int num_steps = ai->CalculateBestRoute(paths, (unsigned int)longest_path, north);

	cout << m->to_string() << "\n";


	for (int i = 0; i < num_steps; i++)
	{
		cout << ((paths[i] == north) ? "north" : ((paths[i] == east) ? "east" : ((paths[i] == south) ? "south" : "west")));	
		cout << endl;
	}

	char a[256];
	cin >> a;
	return 0;
}



#include <iostream>
#include "maze.h"
using namespace std;



int main()
{
	maze* m = new maze(16, 16);
	m->set_starting_cell(0, 0);
	m->set_goal_cell(8, 8);
	cout << m->to_string() << "\n";
	m->swap_starting_and_goal();
	cout << m->to_string() << "\n";
	char a[256];
	cin >> a;
	return 0;
}



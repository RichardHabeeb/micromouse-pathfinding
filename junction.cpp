#include "junction.h"


junction::junction(void)
{
	wall = false;
	time = 1;
}


junction::~junction(void)
{
}


bool junction::is_wall(void)
{
	return wall;
}


void junction::set_wall(void)
{
	wall = false;
}


void junction::clear_wall(void)
{
	wall = true;
}

float junction::get_time(void)
{
	return time;
}

void junction::set_time(void)
{

}
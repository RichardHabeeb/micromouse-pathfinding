#pragma once
#include "util_math.h"

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

inline int HeadingDistance(heading h1, heading h2)
{
	return Minimum(Mod(h1 - h2, (int)NUM_HEADINGS), Mod(h2 - h1, (int)NUM_HEADINGS));
}
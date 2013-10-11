#pragma once
#include "junction.h"

class cell
{
public:
	cell(void);
	~cell(void);

private:
	junction headings[4];
};


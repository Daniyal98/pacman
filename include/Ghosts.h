#pragma once
#include "Point.h"
#include "util.h"
class Ghosts
{

public:
	Point pos;
	bool alive;
	ColorNames color;
public:
	Ghosts()
	{
	}
	virtual void Move();
	~Ghosts();
};


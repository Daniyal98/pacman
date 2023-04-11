#pragma once
#include "Point.h"
class Ghosts
{

public:
	Point pos;
	bool alive;
public:
	Ghosts(){
		pos.setx(185);
		pos.sety(190);
	}
	~Ghosts();
};


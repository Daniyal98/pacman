#pragma once
#include "Point.h"

class Character
{
protected:
	Point pos;
public:
	Character();
	Point getPoint();
	~Character();
};
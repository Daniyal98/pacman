/*
* Point.cpp
*
*  Created on: May 11, 2017
*      Author: daniyal
*/

#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int a, int b)
{
	x = a;
	y = b;
}

int Point::getx()
{
	return x;
}

int Point::gety()
{
	return y;
}

void Point::setx(int a)
{
	x = a;
}

void Point::sety(int a)
{
	y = a;
}

bool Point::operator==(Point P)
{
	bool equalx = false;
	bool equaly = false;

	for (int i = x - 30; i < x + 30; i++)
	{
		if (i == P.getx())
			equalx = true;
	}

	for (int i = y - 30; i < y + 30; i++)
	{
		if (i == P.gety())
			equaly = true;
	}

	if (equalx && equaly)
		return true;

	return false;
}

Point::~Point() {
}


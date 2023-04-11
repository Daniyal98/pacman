/*
* Bomb.cpp
*
*  Created on: May 20, 2017
*      Author: daniyal
*/

#include "Bomb.h"

Bomb::Bomb() {
	time = 0;
	LineStatus = false;

}

void Bomb::SetPoint(Point A)
{
	P.setx(A.getx());
	P.sety(A.gety());
	time = 0;
}

Point Bomb::getPoint()
{
	return P;
}

bool Bomb::Timecheck(){
	time++;
	if (time == 3)
		return false;
	else
		return true;
}

void Bomb::Reset()
{
	P.setx(0);
	P.sety(0);
}

int Bomb::getTime()
{
	return time;
}

void Bomb::Status()
{
	if (LineStatus == true)
		LineStatus = false;

	else if (LineStatus == false)
		LineStatus = true;
}

bool Bomb::getLineStatus()
{
	return LineStatus;
}



Bomb::~Bomb() {

}


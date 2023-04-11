/*
* Character.cpp
*
*  Created on: May 11, 2017
*      Author: daniyal
*/

#include "Character.h"

Character::Character()
{
	pos.setx(0);
	pos.sety(0);
}

/*Character::Character(int a, int b)
{
pos.setx(a);
pos.sety(b);
}*/

Point Character::getPoint()
{
	return pos;
}

Character::~Character() {
	// TODO Auto-generated destructor stub
}


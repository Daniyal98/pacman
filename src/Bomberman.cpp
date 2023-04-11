/*
* Bomberman.cpp
*
*  Created on: May 11, 2017
*      Author: daniyal
*/
#include <iostream>
using namespace std;
#include "Bomberman.h"

Bomberman::Bomberman()
{
	pos.setx(80);
	pos.sety(90);
	lives = 3;
	isAlive = true;
	cout << "HelloWorld";
}

Point Bomberman::getPoint()
{
	return pos;
}

void Bomberman::MoveUp()
{
	if ((pos.gety() + 60) < 720)
		pos.sety(pos.gety() + 60);
}

void Bomberman::MoveDown()
{
	if ((pos.gety() + 60) > 150)
		pos.sety(pos.gety() - 60);
}

void Bomberman::MoveRight()
{
	if ((pos.getx() + 60) < 950)
		pos.setx(pos.getx() + 60);
}

void Bomberman::MoveLeft()
{
	if ((pos.getx() + 60) > 140)
		pos.setx(pos.getx() - 60);
}

void Bomberman::Lives()
{
	lives--;
}

void Bomberman::setPoint(int a, int b)
{
	pos.setx(a);
	pos.sety(b);
}

Bomberman::~Bomberman() {

}


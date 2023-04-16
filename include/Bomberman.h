#pragma once

#include "Character.h"
#include"Bomb.h"

class Bomberman : public Character
{
private:
	bool isAlive;
	int lives;
public:
	Bomb bomb;
	Bomberman();
	Point getPoint();
	void MoveUp();
	void MoveDown();
	void MoveRight();
	void Lives();
	void MoveLeft();
	void setPoint(int, int);
	int getLives();
	virtual ~Bomberman();
};

#pragma once
#include "Point.h"

class Bomb
{
private:
	int time;
	Point P;
	bool LineStatus;
public:
	Bomb();
	void SetPoint(Point);
	Point getPoint();
	bool Timecheck();
	int getTime();
	void Reset();
	void Status();
	bool getLineStatus();
	virtual ~Bomb();
};

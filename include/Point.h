#pragma once



class Point
{
private:
	int x;
	int y;
public:
	Point();
	Point(int, int);
	int getx();
	int gety();
	void setx(int);
	void sety(int);
	bool operator==(Point);
	virtual ~Point();
};


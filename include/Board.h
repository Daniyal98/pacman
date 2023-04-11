/*
* Board.h
*
*  Created on: May 2, 2014
*      Author: Sibt ul Hussain
*/
#ifndef _BOARD_H_
#define _BOARD_H_

//#include <GL/glut.h>
#include <iostream>
#include "util.h"
#include "Bomberman.h"
#include"Ghosts.h"
using namespace std;
class Board {
private:

	int xcellsize, ycellsize;
	int width, height;
	ColorNames pcolor, bcolor, gcolor;
	int score;
public:
	Ghosts ghost[4];
	static const int BOARD_X;
	static const int BOARD_Y;
	Board(int xsize = 8, int ysize = 8);
	Bomberman Bombman;
	int Array[13][17];
	int getScore();
	bool Check();
	void Reset();
	~Board(void);
	void InitalizeBoard(int, int);
	//draw the board
	void Draw();
	void Destroy(Point);

	static int GetBoardX() {
		return BOARD_X;
	}
	static int GetBoardY() {
		return BOARD_Y;
	}
	int GetMidX() {
		return BOARD_X * xcellsize / 2.0;
	}
	int GetMidY() {
		return BOARD_Y * ycellsize / 2.0;
	}
	int GetCellSize() {
		return xcellsize;
	}
	void GetInitBombermanPosition(int &x, int &y) {
		x = xcellsize + xcellsize / 2;
		y = ycellsize + ycellsize / 2;
	}

	void GetInitTextPosition(int &x, int &y);
	void GetInitPinkyPosition(int &x, int &y);
	//	int GetMidx
};

#ifdef WITH_TEXTURES
void RegisterTextures();
#endif

#endif

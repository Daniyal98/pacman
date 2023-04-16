//============================================================================
// Name        : bubble-shooter.cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Bubble Shooting...
//============================================================================
#ifndef BOMBER_PACMAN_CPP
#define BOMBER_PACMAN_CPP

//#include <GL/gl.h>
//#include <GL/glut.h>
#include "Board.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
bool bombStatus = false;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
*  that is what dimensions (x and y) your game will have
*  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
* */
void SetCanvasSize(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//Number of Vertices used to draw Bomberman Circle...
// x= r cos (theta), y= r sin(theta)
const int npmvertices = 1220;
GLfloat pmvertices[npmvertices][2];
void InitPMVertices(float radius) {

	float hdegree = (M_PI - M_PI / 2.0) / 360.0;
	float angle = M_PI + M_PI / 6.0;
	for (int i = 0; i < npmvertices; ++i) {
		pmvertices[i][0] = radius * cos(angle);
		pmvertices[i][1] = radius * sin(angle);
		angle += hdegree;
	}
}

void DrawBomberman(float sx/*center x*/, float sy/*center y*/,
	float radius/*Radius*/,
	const ColorNames &colorname/*Bomberman Colour*/) {

	glColor3fv(colors[colorname]); // set the circle color
	InitPMVertices(radius);
	glBegin(GL_TRIANGLE_FAN);
	glVertex4f(sx, sy, 0, 1);
	for (int i = 0; i < npmvertices; ++i)
		glVertex4f(sx + pmvertices[i][0], sy + pmvertices[i][1], 0, 1);
	glEnd();
	DrawCircle(sx - radius + radius / 2, sy + (radius - radius / 2),
		radius / 10, colors[BLACK]);
}
/*
* Main Canvas drawing function.
* */
Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors

	//

	b->Draw();
	int x, y;
	b->GetInitPinkyPosition(x, y);
	cout << x << "  y= " << y << endl << flush;
	// DrawEnemy(b->ghosts[0].pos.getx(), b->ghosts[0].pos.gety(), b->ghosts[0].color, 0.9 * b->GetCellSize(), 0.9 * b->GetCellSize());
	// DrawEnemy(b->ghosts[1].pos.getx(), b->ghosts[1].pos.gety(), b->ghosts[1].color, 0.9 * b->GetCellSize(), 0.9 * b->GetCellSize());
	// DrawEnemy(b->ghosts[2].pos.getx(), b->ghosts[2].pos.gety(), b->ghosts[2].color, 0.9 * b->GetCellSize(), 0.9 * b->GetCellSize());
	// DrawEnemy(b->ghosts[3].pos.getx(), b->ghosts[3].pos.gety(), b->ghosts[3].color, 0.9 * b->GetCellSize(), 0.9 * b->GetCellSize());

	//b->GetInitBombermanPosition(x, y);
	DrawBomberman(b->Bombman.getPoint().getx(), b->Bombman.getPoint().gety(), b->GetCellSize() / 2 - 2, YELLOW);
	cout << b->Bombman.getPoint().getx() << " " << b->Bombman.getPoint().gety() << endl;
	b->GetInitTextPosition(x, y);
	cout << endl << "Text Position = " << x << "  y= " << y << endl << flush;
	DrawString(x, y, "Score = " + Num2Str(b->getScore()), colors[5]);
	//	glPopMatrix();
	if (bombStatus == true) {
		DrawCircle(b->Bombman.bomb.getPoint().getx(), b->Bombman.bomb.getPoint().gety(), 15, colors[RED]); // To Draw a bomb. You will provide your own x and y relative to Bombermans position
		//bombStatus = false;
	}
	if (b->Bombman.bomb.getTime() == 3)
	{
		b->Destroy(b->Bombman.bomb.getPoint());
		
		if (b->Bombman.bomb.getLineStatus() == true)
		{
			DrawLine(b->Bombman.bomb.getPoint().getx(), b->Bombman.bomb.getPoint().gety(), b->Bombman.bomb.getPoint().getx() + 60, b->Bombman.bomb.getPoint().gety(), 30, colors[YELLOW]);
			DrawLine(b->Bombman.bomb.getPoint().getx(), b->Bombman.bomb.getPoint().gety(), b->Bombman.bomb.getPoint().getx() - 60, b->Bombman.bomb.getPoint().gety(), 30, colors[YELLOW]);
			DrawLine(b->Bombman.bomb.getPoint().getx(), b->Bombman.bomb.getPoint().gety(), b->Bombman.bomb.getPoint().getx(), b->Bombman.bomb.getPoint().gety() + 60, 30, colors[YELLOW]);
			DrawLine(b->Bombman.bomb.getPoint().getx(), b->Bombman.bomb.getPoint().gety(), b->Bombman.bomb.getPoint().getx(), b->Bombman.bomb.getPoint().gety() - 60, 30, colors[YELLOW]);
			b->Bombman.bomb.Status();
		}

		cout << "Bomberman cordinates are " << b->Bombman.getPoint().getx() << "and " << b->Bombman.getPoint().gety() << endl;
		cout << "Bomb coordiantes are " << b->Bombman.bomb.getPoint().getx() << "and " << b->Bombman.bomb.getPoint().gety() << endl;
	}
	glutSwapBuffers(); // do not modify this line..

}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
* is pressed from the keyboard
*
* You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
*
* This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
* program coordinates of mouse pointer when key was pressed.
*
* */

void NonPrintableKeys(int key, int x, int y) {
	if (key

		== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed..
		if (b->Array[b->Bombman.getPoint().gety() / 60][b->Bombman.getPoint().getx() / 60 - 1] == 0)
		{
			b->Bombman.MoveLeft();
			glutPostRedisplay();
		}

	}
	else if (key
		== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if (b->Array[b->Bombman.getPoint().gety() / 60][b->Bombman.getPoint().getx() / 60 + 1] == 0)
		{
			b->Bombman.MoveRight();
			glutPostRedisplay();
		}

	}
	else if (key
		== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if (b->Array[(b->Bombman.getPoint().gety() / 60) + 1][b->Bombman.getPoint().getx() / 60] == 0)
		{
			b->Bombman.MoveUp();
			glutPostRedisplay();
		}
	}

	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if (b->Array[b->Bombman.getPoint().gety() / 60 - 1][b->Bombman.getPoint().getx() / 60] == 0)
		{
			b->Bombman.MoveDown();
			glutPostRedisplay();
		}
	} 

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	* this function*/
	/*
	glutPostRedisplay();
	*/
}


/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
* is pressed from the keyboard
* This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
* program coordinates of mouse pointer when key was pressed.
* */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
	{
		b->Bombman.bomb.SetPoint(b->Bombman.getPoint());
		bombStatus = true;
		b->Bombman.bomb.Status();
	
	}
	glutPostRedisplay();
}

/*
* This function is called after every 1000.0/FPS milliseconds
* (FPS is defined on in the beginning).
* You can use this function to animate objects and control the
* speed of different moving objects by varying the constant FPS.
*
* */
void Timer(int m) {

	// implement your functionality here
	if (bombStatus == true){
		bombStatus = b->Bombman.bomb.Timecheck();
	}

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
	glutPostRedisplay();
}

/*
* our gateway main function
* */
int main(int argc, char*argv[]) {

	b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("CP's Bomber Bomberman"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
#ifdef WITH_TEXTURES
	RegisterTextures();
#endif
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* Bomberman_CPP_ */

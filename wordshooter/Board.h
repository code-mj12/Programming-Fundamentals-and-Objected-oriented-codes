/*
 * Board.h
 *
 *  Created on: May 2, 2014
 *      Author: Sibt ul Hussain
 */
#ifndef _BOARD_H_
#define _BOARD_H_

#include <GL/glut.h>
#include <iostream>
#include "util.h"
using namespace std;
class Board {
private:
	int pebbles_left;
	int xcellsize, ycellsize;
	int lwidth;
	float cwidth;
	//array for eating
	int tp_array[31][28];
	ColorNames pcolor, bcolor, gcolor;

public:
	static const int BOARD_X;
	static const int BOARD_Y;
	Board(int xsize = 8, int ysize = 8);

	~Board(void);

	//draw the board
	void Draw(void);

	//this function returns whether or not a location is open or a wall
	bool IsOpen(int, int);

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
	void GetInitPacmanPosition(int &x, int &y) {
		x = 14 * xcellsize;
		y = 9 * ycellsize + ycellsize / 2;
	}
	void GetInitPinkyPosition(int &x, int &y) {
		x = 11 * xcellsize/* - xcellsize / 2.0*/;
		y = 18 * ycellsize - ycellsize / 2.0;
	}
	void GetInitRedPosition(int &x, int &y) {
		x = 13 * xcellsize;
		y = 21 * ycellsize - ycellsize / 2.0;
	}
	void GetInitOrangePosition(int &x, int &y) {

		x = 13 * xcellsize;
		y = 18 * ycellsize - ycellsize / 2.0;
	}
	void GetInitBluePosition(int &x, int &y) {
		x = 15 * xcellsize;
		y = 18 * ycellsize - ycellsize / 2.0;
	}
	void GetInitTextPosition(int &x, int &y) {
		x = 13 * xcellsize;
		y = 14 * ycellsize;
	}
//	int GetMidx
}
;

#endif

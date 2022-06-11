/*
 * Board.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Sibt ul Hussain
 */

#include "Board.h"
#include <cstdio>

const int Board::BOARD_X = 28;
const int Board::BOARD_Y = 36;
//here's pacman's crrrazy board
enum BoardParts {
	NILL, // Prohibitive Empty space
	TLC, // Left corner top
	TRC, //Right corner top
	BLC, // Left corner bottom
	BRC, //Right corner bottom
	BT, // Border Drawing top
	BB, // Border Drawing bottom
	BL, // Border Drawing left
	BR, // Border Drawing right
	HL, // Horizontal line
	VL, // Vertical line
	GG, // Ghost Gate
	BTLC, // Border Left corner top
	BTRC, //Border Right corner top
	BBLC, //Border Left corner bottom
	BBRC, //Border Right corner bottom
	PEBB, // Pebbles
	VE, // Valid Empty
	SB, // Solid Ball
	GH, // Ghoust House
	SBR, // straight line with bottom right corner
	SBL, // straight line with bottom left corner
	// vertical straight lines for different border...
	VTR,
	VTL,
	VBR,
	VBL
};
// defining some utility functions...

static int board_array[Board::BOARD_Y][Board::BOARD_X] = { { 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0 }, { BBRC, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		SBL, SBR, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, BBLC }, { 7, 16, 16, 16,
		16, 16, 16, 16, 16, 16, 16, 16, 16, 10, 10, 16, 16, 16, 16, 16, 16, 16,
		16, 16, 16, 16, 16, BR }, { 7, 16, BRC, 9, 9, BLC, 16, BRC, 9, 9, 9,
		BLC, 16, 10, 10, 16, BRC, 9, 9, 9, BLC, 16, BRC, 9, 9, BLC, 16, BR }, {
		7, 18, 10, 0, 0, 10, 16, 10, 0, 0, 0, 10, 16, 10, 10, 16, 10, 0, 0, 0,
		10, 16, 10, 0, 0, 10, 18, BR },
		{ 7, 16, TRC, 9, 9, TLC, 16, TRC, 9, 9, 9, TLC, 16, TRC, TLC, 16, TRC,
				9, 9, 9, TLC, 16, TRC, 9, 9, TLC, 16, BR }, { 7, 16, 16, 16, 16,
				16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
				16, 16, 16, 16, 16, 16, BR }, { 7, 16, BRC, 9, 9, BLC, 16, BRC,
				BLC, 16, BRC, 9, 9, 9, 9, 9, 9, BLC, 16, BRC, BLC, 16, BRC, 9,
				9, BLC, 16, BR }, { 7, 16, 2, 9, 9, 1, 16, 10, 10, 16, TRC, 9,
				9, 3, 4, 9, 9, 1, 16, 10, 10, 16, 2, 9, 9, 1, 16, BR }, { 7, 16,
				16, 16, 16, 16, 16, 10, 10, 16, 16, 16, 16, 10, 10, 16, 16, 16,
				16, 10, 10, 16, 16, 16, 16, 16, 16, BR }, { BTRC, 6, 6, 6, 6,
				BLC, 16, 10, TRC, 9, 9, BLC, 17, 10, 10, 17, BRC, 9, 9, TLC, 10,
				16, BRC, 6, 6, 6, 6, 12 }, { 0, 0, 0, 0, 0, 7, 16, 10, BRC, 9,
				9, TLC, 17, TRC, TLC, 17, TRC, 9, 9, BLC, 10, 16, 8, 0, 0, 0, 0,
				0 }, { 0, 0, 0, 0, 0, 7, 16, 10, 10, 17, 17, 17, 17, 17, 17, 17,
				17, 17, 17, 10, 10, 16, 8, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 7,
				16, 10, 10, 17, BRC, 6, 6, 11, 11, 6, 6, BLC, 17, 10, 10, 16, 8,
				0, 0, 0, 0, 0 }, { 5, 5, 5, 5, 5, TLC, 16, TRC, TLC, 17, 8, 19,
				19, 19, 19, 19, 19, 7, 17, TRC, TLC, 16, TRC, 5, 5, 5, 5, 5 }, {
				17, 17, 17, 17, 17, 17, 16, 17, 17, 17, 8, 19, 19, 19, 19, 19,
				19, 7, 17, 17, 17, 16, 17, 17, 17, 17, 17, 17 }, { BB, BB, BB,
				BB, BB, BLC, 16, BRC, BLC, 17, 8, 19, 19, 19, 19, 19, 19, 7, 17,
				BRC, BLC, 16, BRC, BB, BB, BB, BB, BB }, { 0, 0, 0, 0, 0, 7, 16,
				10, 10, 17, TRC, BT, BT, BT, BT, BT, BT, TLC, 17, 10, 10, 16, 8,
				0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 7, 16, 10, 10, 17, 17, 17, 17,
				17, 17, 17, 17, 17, 17, 10, 10, 16, 8, 0, 0, 0, 0, 0 }, { 0, 0,
				0, 0, 0, 7, 16, 10, 10, 17, BRC, HL, HL, HL, HL, HL, HL, BLC,
				VE, 10, 10, 16, 8, 0, 0, 0, 0, 0 }, { BBRC, 5, 5, 5, 5, TLC, 16,
				TRC, TLC, 17, TRC, HL, HL, BLC, BRC, HL, HL, TLC, 17, TRC, TLC,
				16, TRC, 5, 5, 5, 5, BBLC }, { 7, 16, 16, 16, 16, 16, 16, 16,
				16, 16, 16, 16, 16, VL, VL, 16, 16, 16, 16, 16, 16, 16, 16, 16,
				16, 16, 16, BR }, { 7, 16, BRC, HL, HL, BLC, 16, BRC, HL, HL,
				HL, BLC, 16, VL, VL, 16, BRC, HL, HL, HL, BLC, 16, BRC, HL, HL,
				BLC, 16, BR }, { 7, 16, TRC, HL, BLC, VL, 16, TRC, HL, HL, HL,
				TLC, 16, TRC, TLC, 16, TRC, HL, HL, HL, TLC, 16, VL, BRC, HL,
				TLC, 16, BR },
		{ 7, SB, 16, 16, VL, VL, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
				16, 16, 16, 16, VL, VL, 16, 16, SB, BR }, { VTR, HL, BLC, 16,
				VL, VL, 16, BRC, BLC, 16, BRC, HL, HL, HL, HL, HL, HL, BLC, 16,
				BRC, BLC, 16, VL, VL, 16, BRC, HL, VTL }, { VBR, HL, TLC, 16,
				TRC, TLC, 16, VL, VL, 16, TRC, HL, HL, BLC, BRC, HL, HL, TLC,
				16, VL, VL, 16, TRC, TLC, 16, TRC, HL, VBL }, { 7, 16, 16, 16,
				16, 16, 16, VL, VL, 16, 16, 16, 16, VL, VL, 16, 16, 16, 16, VL,
				VL, 16, 16, 16, 16, 16, 16, BR }, { 7, 16, BRC, HL, HL, HL, HL,
				TLC, TRC, HL, HL, BLC, 16, VL, VL, 16, BRC, HL, HL, TLC, TRC,
				HL, HL, HL, HL, BLC, 16, BR }, { 7, 16, TRC, HL, HL, HL, HL, HL,
				HL, HL, HL, TLC, 16, TRC, TLC, 16, TRC, HL, HL, HL, HL, HL, HL,
				HL, HL, TLC, 16, BR }, { 7, 16, 16, 16, 16, 16, 16, 16, 16, 16,
				16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
				16, BR },
		{ BTRC, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB,
				BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BTLC }, { 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

// Destructor
Board::~Board(void) {
}

//Constructor
Board::Board(int xsize, int ysize) {
	xcellsize = xsize;
	ycellsize = ysize;
	lwidth = 3; // line width
	cwidth = 3; // curve widh
	/*pcolor = (ColorNames) 2;
	 bcolor = (ColorNames) 1;
	 gcolor = (ColorNames) 0;*/
	pcolor = CHOCOLATE;
	bcolor = DARK_BLUE;
	gcolor = PINK;
//set up board
}

void Board::Draw(void) {
	glColor3f(0, 0, 1);
	glPushMatrix();
//	glTranslatef(10, 10, 1);
//	glScalef(2.5, 2.5, 1);
//glRotatef(10, 1, 0, 0);

	int offset = xcellsize / 2.0, roffset = 2;

	for (int i = BOARD_Y - 1, y = 0; i >= 0; --i, y += xcellsize) {
		for (int j = 0, x = 0; j < BOARD_X; j++, x += ycellsize) {
//			cout << " " << board_array[i][j] << " " << flush;
			switch (board_array[i][j]) {
			case NILL:	//resets the pebble array
						// Prohibitive Empty space
				break;
			case TLC: // Left corner top
				Torus2d(x, y + xcellsize, 270, 90,
						(float) xcellsize / 2.0 - cwidth, cwidth, 390,
						colors[bcolor]);
				break;
			case TRC: //Right corner top
				Torus2d(x + xcellsize, y + ycellsize, 180, 90,
						(float) xcellsize / 2.0 - cwidth, cwidth, 390,
						colors[bcolor]);
				break;
			case BLC: // Left corner bottom
				Torus2d(x, y, 0, 90, (float) xcellsize / 2.0 - cwidth, cwidth,
						390, colors[bcolor]);
				break;
			case BRC: //Right corner bottom
				Torus2d(x + xcellsize, y, 90, 90,
						(float) xcellsize / 2.0 - cwidth, cwidth, 390,
						colors[bcolor]);
				break;
			case BT: // Border Drawing top
				DrawLine(x, y + xcellsize, x + xcellsize, y + ycellsize, lwidth,
						colors[bcolor]);
				DrawLine(x, y + xcellsize - offset, x + xcellsize,
						y + ycellsize - offset, lwidth, colors[bcolor]);
				break;
			case BB: // Border Drawing bottom
				DrawLine(x, y, x + xcellsize, y, lwidth, colors[bcolor]);
				DrawLine(x, y + offset, x + xcellsize, y + offset, lwidth,
						colors[bcolor]);
				break;
			case BL: // Border Drawing left
				DrawLine(x, y, x, y + ycellsize, lwidth, colors[bcolor]);
				DrawLine(x + offset, y, x + offset, y + ycellsize, lwidth,
						colors[bcolor]);
				break;
			case BR: // Border Drawing right
				DrawLine(x + xcellsize, y, x + xcellsize, y + ycellsize, lwidth,
						colors[bcolor]);
				DrawLine(x - offset + xcellsize, y, x - offset + xcellsize,
						y + ycellsize, lwidth, colors[bcolor]);
				break;
			case HL: // Horizontal line
				DrawLine(x, y + ycellsize / 2, x + xcellsize, y + ycellsize / 2,
						lwidth, colors[bcolor]);
				break;
			case VL: // Vertical line
				DrawLine(x + xcellsize / 2, y, x + xcellsize / 2, y + ycellsize,
						lwidth, colors[bcolor]);
				break;
			case GG: // Ghost Gate
				DrawLine(x, y + ycellsize / 2, x + xcellsize,
						y + ycellsize / 2);
				break;
			case BTLC: // Border Left corner top
				Torus2d(x, y + xcellsize, 270, 90, (float) xcellsize - cwidth,
						cwidth, 390, colors[bcolor]);
				Torus2d(x, y + xcellsize, 270, 90,
						(float) xcellsize / 2.0 - cwidth, cwidth, 390,
						colors[bcolor]);
				break;
			case BTRC: //Border Right corner top
				Torus2d(x + xcellsize, y + ycellsize, 180, 90,
						(float) xcellsize - cwidth, cwidth, 390,
						colors[bcolor]);
				Torus2d(x + xcellsize, y + ycellsize, 180, 90,
						(float) xcellsize / 2.0 - cwidth, cwidth, 390,
						colors[bcolor]);
				break;
			case BBLC: //Border Left corner bottom
				Torus2d(x, y, 0, 90, (float) xcellsize - cwidth, cwidth, 390,
						colors[bcolor]);
				Torus2d(x, y, 0, 90, (float) xcellsize / 2.0 - cwidth, cwidth,
						390, colors[bcolor]);
				break;
			case BBRC: //Border Right corner bottom
				Torus2d(x + xcellsize, y, 90, 90,
						(float) xcellsize / 2.0 - cwidth, cwidth, 390,
						colors[bcolor]);
				Torus2d(x + xcellsize, y, 90, 90, (float) xcellsize - cwidth,
						cwidth, 390, colors[bcolor]);
				//				Torus2d(x + xcellsize, y, 0, 90, xcellsize / 2, lwidth, 10);
				//				Torus2d(x + xcellsize, y, 0, 90, xcellsize / 2 - roffset,
				//						lwidth, 10);
				break;
			case PEBB: // Pebbles
				DrawCircle(x + xcellsize / 2, y + ycellsize / 2, xcellsize / 4,
						colors[pcolor]);
				break;
			case VE: // Valid Empty
				break;
			case SB: // Solid Ball
				DrawCircle(x + xcellsize / 2, y + ycellsize / 2, xcellsize / 2,
						colors[pcolor]);
				break;
			case SBL: // Staright line with Left corner bottom
				DrawLine(x, y + xcellsize, x + xcellsize, y + ycellsize, lwidth,
						colors[bcolor]);
				Torus2d(x, y, 0, 90, (float) xcellsize / 2.0 - cwidth, cwidth,
						390, colors[bcolor]);
				break;
			case SBR: // StrRight corner bottom
				DrawLine(x, y + xcellsize, x + xcellsize, y + ycellsize, lwidth,
						colors[bcolor]);
				Torus2d(x + xcellsize, y, 90, 90,
						(float) xcellsize / 2.0 - cwidth, cwidth, 390,
						colors[bcolor]);
				break;
				break;
			case GH: // Ghoust House
				;
				break;
			case VTL: // Left corner top
				DrawLine(x + xcellsize, y, x + xcellsize, y + ycellsize, lwidth,
						colors[bcolor]);
				Torus2d(x, y + xcellsize, 270, 90,
						(float) xcellsize / 2.0 - cwidth, cwidth, 390,
						colors[bcolor]);
				break;
			case VTR: //Right corner top
				DrawLine(x, y, x, y + ycellsize, lwidth, colors[bcolor]);

				Torus2d(x + xcellsize, y + ycellsize, 180, 90,
						(float) xcellsize / 2.0 - cwidth, cwidth, 390,
						colors[bcolor]);
				break;
			case VBL: // Left corner bottom
				DrawLine(x + xcellsize, y, x + xcellsize, y + ycellsize, lwidth,
						colors[bcolor]);
				Torus2d(x, y, 0, 90, (float) xcellsize / 2.0 - cwidth, cwidth,
						390, colors[bcolor]);
				break;
			case VBR: //Right corner bottom
				DrawLine(x, y, x, y + ycellsize, lwidth, colors[bcolor]);

				Torus2d(x + xcellsize, y, 90, 90,
						(float) xcellsize / 2.0 - cwidth, cwidth, 390,
						colors[bcolor]);
				break;
			}
		}
	}
	glPopMatrix();
}

//returns whether or not the board is open at the given coords
bool Board::IsOpen(int x, int y) {
	if (board_array[y][x] > 0) {
		return false;
	}
	return true;
}
/*
 #include <string>
 #include <cctype>
 #include <algorithm>
 #include <functional>
 #include <iostream>
 #include <vector>
 class GenerateRandom {
 public:
 GenerateRandom(int l) {
 len = l;
 }
 int Random() {
 return rand() % 100;
 }
 vector<int> operator()() {
 vector<int> vec(len);
 generate(vec.begin(), vec.end(), Random);
 return vec;
 }
 private:
 int len;

 };
 int main() {

 vector<vector<int> > vec(5, 5);
 }
 */

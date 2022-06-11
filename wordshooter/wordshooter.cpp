//============================================================================
// Name        : cookie-crush.cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Cookie  Crush...
//============================================================================
#ifndef WORD_SHOOTER_CPP
#define WORD_SHOOTER_CPP

//#include <GL/gl.h>
//#include <GL/glut.h>
#include <iostream>
#include<string>
#include<cmath>
#include <cstring> ////
#include<fstream>
#include "util.h"
using namespace std;
#define MAX(A,B) ((A) > (B) ? (A):(B))
#define MIN(A,B) ((A) < (B) ? (A):(B))
#define ABS(A) ((A) < (0) ? -(A):(A))
#define FPS 30

string * dictionary;
int dictionarysize = 370099;
#define KEY_ESC 27

int width = 1820, height = 950;
int byoffset = 30;

int nxcells = (width - 30) / (2 * 30);
int nycells = (height - byoffset /*- 30*/) / (2 * 30);
int nfrows = 2; // initially number of full rows //
float score = 0;
int **board; // 2D-arrays for holding the data...
int bwidth = 130;
int bheight = 10;
int bsx, bsy;
const int nalphabets = 26;
enum alphabets {
	AL_A, AL_B, AL_C, AL_D, AL_E, AL_F, AL_G, AL_H, AL_I, AL_J, AL_K, AL_L, AL_M, AL_N, AL_O, AL_P, AL_Q, AL_R, AL_S, AL_T, AL_U, AL_W, AL_X, AL_y, AL_Z
};
GLuint texture[nalphabets];
GLuint tid[nalphabets];
string tnames[] = { "a.bmp", "b.bmp", "c.bmp", "d.bmp", "e.bmp", "f.bmp", "g.bmp", "h.bmp", "i.bmp", "j.bmp",
"k.bmp", "l.bmp", "m.bmp", "n.bmp", "o.bmp", "p.bmp", "q.bmp", "r.bmp", "s.bmp", "t.bmp", "u.bmp", "v.bmp", "w.bmp",
"x.bmp", "y.bmp", "z.bmp" };
GLuint mtid[nalphabets];
int awidth = 60, aheight = 60; // 60x60 pixels cookies...

//the variables that I defined start here
const int rows=14;  //rows of balls
const int cells=30; //no. of balls in each row
int Alphabets[rows][cells]={0}; //2d array controlling representation of balls on screen
int AlphShooter=0; //the ball to be launched
int AlphSecond=0; //the next ball in line to be shooted
const int ball_x=width/2, ball_y=bheight; //position of ball at shooter
float slope; //gradient of stright line traced by the ball
int c_x=ball_x, c_y=ball_y; //y-intercept coordinates for line ball is moving on, changed when reflected
bool moving_ball=false; //determines if the ball is in movement
int temp_y=ball_y, temp_x=ball_x; //pixel coordinates of ball while moving
int tile_x, tile_y; //tile coordinates of ball while moving
string temp_word; //stores the combination of letters being formed
int letter_coordinates[2][9]={{-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1}};//holds the coordinates of the letters being used in the word [0][i] is y tile of any word and [1][i] is x tile and i indicates the position of letter in temp_word
bool popped=true; //for popping of words after random generation of random rows
int time_remaining=120; //time for the game
int ctr=0; //for time decrement
string your_words[50]; //holds the words formed during the game
int word_number=0;//the index in array your_words, at which the word is to be stored
bool game_start=false; //determines if the game has started yet or not
bool second_click=false;
bool swapped=false; //avoid bug in swapping on right click
//my variables end here

//my functions prototypes
string exclude_last_letter(string); //removes last character from the string
string form_word(int); //forms combinations of letters from the screen
void check_pop_word(string); //checks if the combination is present in the dictionary, if it is, the letters are popped
string reverse_word(string); //reverses the order of characters in the string
bool InDictionary(string); //checks if the word is present in dictionary or not
char Number2Alphabet(int); //converts the integer to its character alternative accoring to pre-defined enum
void Pixels2Cell(int px, int py, int &, int &); //takes pixel coordinates and returns the array cell coordinates in which the pixels are present
//my functions end here

//USED THIS CODE FOR WRITING THE IMAGES TO .bin FILE
void RegisterTextures_Write()
//Function is used to load the textures from the
// files and display
{
	// allocate a texture name
	glGenTextures(nalphabets, tid);
	vector<unsigned char> data;
	ofstream ofile("image-data.bin", ios::binary | ios::out);
	// now load each cookies data...

	for (int i = 0; i < nalphabets; ++i) {

		// Read current cookie

		ReadImage(tnames[i], data);
		if (i == 0) {
			int length = data.size();
			ofile.write((char*)&length, sizeof(int));
		}
		ofile.write((char*)&data[0], sizeof(char) * data.size());

		mtid[i] = tid[i];
		// select our current texture
		glBindTexture(GL_TEXTURE_2D, tid[i]);

		// select modulate to mix texture with color for shading
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		// when texture area is small, bilinear filter the closest MIP map
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
			GL_LINEAR_MIPMAP_NEAREST);
		// when texture area is large, bilinear filter the first MIP map
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// if wrap is true, the texture wraps over at the edges (repeat)
		//       ... false, the texture ends at the edges (clamp)
		bool wrap = true;
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
			wrap ? GL_REPEAT : GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
			wrap ? GL_REPEAT : GL_CLAMP);

		// build our texture MIP maps
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, awidth, aheight, GL_RGB,
			GL_UNSIGNED_BYTE, &data[0]);
	}
	ofile.close();

}
void RegisterTextures()
/*Function is used to load the textures from the
* files and display*/
{
	// allocate a texture name
	glGenTextures(nalphabets, tid);

	vector<unsigned char> data;
	ifstream ifile("image-data.bin", ios::binary | ios::in);

	if (!ifile) {
		cout << " Couldn't Read the Image Data file ";
		//exit(-1);
	}
	// now load each cookies data...
	int length;
	ifile.read((char*)&length, sizeof(int));
	data.resize(length, 0);
	for (int i = 0; i < nalphabets; ++i) {
		// Read current cookie
		//ReadImage(tnames[i], data);
		/*if (i == 0) {
		int length = data.size();
		ofile.write((char*) &length, sizeof(int));
		}*/
		ifile.read((char*)&data[0], sizeof(char)* length);

		mtid[i] = tid[i];
		// select our current texture
		glBindTexture(GL_TEXTURE_2D, tid[i]);

		// select modulate to mix texture with color for shading
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		// when texture area is small, bilinear filter the closest MIP map
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
			GL_LINEAR_MIPMAP_NEAREST);
		// when texture area is large, bilinear filter the first MIP map
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// if wrap is true, the texture wraps over at the edges (repeat)
		//       ... false, the texture ends at the edges (clamp)
		bool wrap = true;
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
			wrap ? GL_REPEAT : GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
			wrap ? GL_REPEAT : GL_CLAMP);

		// build our texture MIP maps
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, awidth, aheight, GL_RGB,
			GL_UNSIGNED_BYTE, &data[0]);
	}
	ifile.close();
}
void DrawAlphabet(const alphabets &cname, int sx, int sy, int cwidth = 60,
	int cheight = 60)
	/*Draws a specfic cookie at given position coordinate
	* sx = position of x-axis from left-bottom
	* sy = position of y-axis from left-bottom
	* cwidth= width of displayed cookie in pixels
	* cheight= height of displayed cookiei pixels.
	* */
{
	float fwidth = (float)cwidth / width * 2, fheight = (float)cheight
		/ height * 2;
	float fx = (float)sx / width * 2 - 1, fy = (float)sy / height * 2 - 1;

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mtid[cname]);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0, 0.0);
	glVertex2d(fx, fy);
	glTexCoord2d(1.0, 0.0);
	glVertex2d(fx + fwidth, fy);
	glTexCoord2d(1.0, 1.0);
	glVertex2d(fx + fwidth, fy + fheight);
	glTexCoord2d(0.0, 1.0);
	glVertex2d(fx, fy + fheight);
	glEnd();

	glColor4f(1, 1, 1, 1);

	//	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_TEXTURE_2D);
	//glPopMatrix();

	//glutSwapBuffers();
}
int GetAlphabet() {
	return GetRandInRange(1, 26);
}

void DrawShooter(int sx, int sy, int cwidth = 60, int cheight = 60)

{
	float fwidth = (float)cwidth / width * 2, fheight = (float)cheight
		/ height * 2;
	float fx = (float)sx / width * 2 - 1, fy = (float)sy / height * 2 - 1;

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, -1);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0, 0.0);
	glVertex2d(fx, fy);
	glTexCoord2d(1.0, 0.0);
	glVertex2d(fx + fwidth, fy);
	glTexCoord2d(1.0, 1.0);
	glVertex2d(fx + fwidth, fy + fheight);
	glTexCoord2d(0.0, 1.0);
	glVertex2d(fx, fy + fheight);
	glEnd();

	glColor4f(1, 1, 1, 1);

	//	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//glutSwapBuffers();
}
/*
* Main Canvas drawing function.
* */
void DisplayFunction() {
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim red and 1 means pure red and so on.
	//#if 0
	glClearColor(1/*Red Component*/, 1.0/*Green Component*/,
		1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	//write your drawing commands here or call your drawing functions...
	if (game_start==true) //game process begins after the start screen has been clicked on
	{
		if (time_remaining>0) //game stops when time runs out
		{
			for (int i=0; i<rows; i++)
			{//displays balls on the screen based on values in the array
				for (int j=0; j<cells; j++)
						DrawAlphabet((alphabets)Alphabets[i][j], 10+awidth*j, height-100-aheight*i, awidth, aheight);
			}
			DrawAlphabet((alphabets)AlphSecond, ball_x/2,0,awidth,aheight); //displays the second shooter ball
			if (moving_ball==false)
			{//returns all variables to their default values and displays the shooter ball
				temp_y=ball_y; 
				temp_x=ball_x;
				c_x=ball_x;
				c_y=ball_y;
				DrawAlphabet((alphabets)AlphShooter, temp_x , temp_y, awidth, aheight);
			}
			else
			{
				if (temp_y<=height) //increments y pixel coordinate except when it goes out of screen
					temp_y+=10;
				else //returns the ball to the shooter if it goes out of the screen
					moving_ball=false;
				if (slope*(temp_y-c_y)+c_x>=width-30 || slope*(temp_y-c_y)+c_x<=-30)//reflection purposes
				{
					c_x=slope*(temp_y-c_y)+c_x; //changes the intercept as they serve as reference point for the movement of ball on the straight line
					c_y=temp_y-30;
					slope=-slope;
				}
				temp_x=slope*(temp_y-c_y)+c_x; //calculates x pixel coodinate on the straight line, based on the y coordinate
				Pixels2Cell(temp_x, temp_y, tile_x, tile_y);
				if ((Alphabets[tile_y-1][tile_x]!=27 && Alphabets[tile_y][tile_x]==27) || (Alphabets[tile_y][tile_x-1]!=27 && Alphabets[tile_y][tile_x]==27) || (Alphabets[tile_y][tile_x+1]!=27 && Alphabets[tile_y][tile_x]==27))
				{
					Alphabets[tile_y][tile_x]=AlphShooter;
					for (int i=1; i<=5; i++)
					{//the two functions generate combinations, check combinations in dictionary and then pops the words
						temp_word=form_word(i);
						check_pop_word(temp_word);
					}
					moving_ball=false;
					AlphShooter=AlphSecond; //the second ball proceeds to the shooter
					AlphSecond=GetAlphabet(); //a random secondary ball is generated
				}
				else
					DrawAlphabet((alphabets)AlphShooter, temp_x , temp_y, awidth, aheight);	
			}
			ctr+=1; //timer
			if (ctr==60) //FPS is 60
			{
				ctr=0; 
				time_remaining-=1;
			}
			
			DrawString(40, height - 20, width, height , "Score " + Num2Str(score), colors[BLUE_VIOLET]);
			DrawString(width / 2 - 30, height - 25, width, height,
				"Time Left:" + Num2Str(time_remaining) + " secs", colors[RED]);
		
		// #----------------- Write your code till here ----------------------------#
		//DO NOT MODIFY THESE LINES
			DrawShooter((width / 2) - 35, 0, bwidth, bheight);
		//DO NOT MODIFY THESE LINES..
		}
		else
		{//prints the ending screen
			DrawAlphabet((alphabets)19, 490, 730, awidth*2, aheight*2);
			DrawAlphabet((alphabets)8, 610, 730, awidth*2, aheight*2);
			DrawAlphabet((alphabets)12, 730, 730, awidth*2, aheight*2);
			DrawAlphabet((alphabets)4, 850, 730, awidth*2, aheight*2);
			DrawAlphabet((alphabets)20, 1030, 730, awidth*2, aheight*2);
			DrawAlphabet((alphabets)15, 1150, 730, awidth*2, aheight*2);
			DrawString(850, 650, width, height , "SCORE : " + Num2Str(score), colors[BLUE_VIOLET]);
			DrawString(820, 550, width, height , "YOUR WORDS", colors[RED]);
			for (int i=0; i<word_number; i++)
			{
				DrawString(880, 520-30*i, width, height , your_words[i], colors[HOT_PINK]);
			}
		}
	}
	else
	{//prints the starting screen
		DrawAlphabet((alphabets)25, 90, 730, awidth*2, aheight*2);
		DrawAlphabet((alphabets)18, 210, 730, awidth, aheight);
		DrawAlphabet((alphabets)22, 330, 730, awidth*2, aheight*2);
		DrawAlphabet((alphabets)14, 450, 730, awidth*2, aheight*2);
		DrawAlphabet((alphabets)17, 570, 730, awidth*2, aheight*2);
		DrawAlphabet((alphabets)3, 690, 730, awidth*2, aheight*2);
		DrawAlphabet((alphabets)18, 810, 730, awidth*2, aheight*2);
		DrawAlphabet((alphabets)7, 930, 730, awidth*2, aheight*2);
		DrawAlphabet((alphabets)14, 1050, 730, awidth*2, aheight*2);
		DrawAlphabet((alphabets)14, 1170, 730, awidth*2, aheight*2);
		DrawAlphabet((alphabets)19, 1290, 730, awidth*2, aheight*2);
		DrawAlphabet((alphabets)4, 1410, 730, awidth*2, aheight*2);
		DrawAlphabet((alphabets)17, 1530, 730, awidth*2, aheight*2);
		DrawString(820, 560, width, height , "Left Click to Shoot", colors[RED]);
		DrawString(815, 530, width, height , "Right Click to Swap", colors[RED]);
		DrawString(750, 630, width, height , "CLICK ANYWHERE TO BEGIN", colors[HOT_PINK]);
	}
	DrawShooter((width / 2) - 35, 0, 0, 0);
	glutSwapBuffers();
}

/* Function sets canvas size (drawing area) in pixels...
*  that is what dimensions (x and y) your game will have
*  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
* */
void SetCanvasSize(int width, int height) {
/*	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.*/
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
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	}
	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	}
	else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
	}
	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	* this function*/
	/*
	glutPostRedisplay();
	*/
}
/*This function is called (automatically) whenever your mouse moves witin inside the game window
*
* You will have to add the necessary code here for finding the direction of shooting
*
* This function has two arguments: x & y that tells the coordinate of current position of move mouse
*
* */

void MouseMoved(int x, int y) {
	//If mouse pressed then check than swap the balls and if after swaping balls dont brust then reswap the balls

}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
*
* You will have to add the necessary code here for shooting, etc.
*
* This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
* x & y that tells the coordinate of current position of move mouse
*
* */

void MouseClicked(int button, int state, int x, int y) {
	if (game_start==false)
		game_start=true;
	else if (second_click==false) //avoid bug due to double click detection
	{
		second_click=true;
		//checks any combinations formed in the random letters
		while (popped)
		{
			popped=false; //continues checking until no more words are formed
			for (int i=0; i<nfrows; i++)
			{
				for (int j=0; j<cells-9; j++)
				{
					tile_y=i;
					tile_x=j;
					temp_word=form_word(4); //forms horizontally right combinations of letters
					check_pop_word(temp_word); 
				}
			}
			for (int i=0; i<nfrows; i++)
			{
				for (int j=0; j<cells; j++)
				{
					if (Alphabets[i][j]==27)
						Alphabets[i][j]=GetAlphabet(); //generates new letters for the popped indices in the array
				}
			}
		}
	}
	else
	{
		if (button == GLUT_LEFT_BUTTON) // dealing only with left button
		{
			if (state == GLUT_UP && moving_ball==false && y<=height-bheight-10)
			{
				slope=float(x-ball_x)/(height-y-ball_y);
				moving_ball=true;
			}
		}
		else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
		{//right click swaps the two shooter balls
			if (swapped==false)
			{
				int temp=AlphShooter;
				AlphShooter=AlphSecond;
				AlphSecond=temp;
				swapped=true;
			}
			else
				swapped=false;
		}
	}
	glutPostRedisplay();
}
/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
* is pressed from the keyboard
* This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
* program coordinates of mouse pointer when key was pressed.
* */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == KEY_ESC/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
}

/*
* This function is called after every 1000.0/FPS milliseconds
* (FPS is defined on in the beginning).
* You can use this function to animate objects and control the
* speed of different moving objects by varying the constant FPS.
*
* */
void Timer(int m) {

	glutPostRedisplay();
	glutTimerFunc(1000.0/FPS, Timer, 0);
}

/*
* our gateway main function
* */
int main(int argc, char*argv[]) {
	InitRandomizer(); // seed the random number generator...

	//Dictionary for matching the words. It contains the 370099 words.
	dictionary = new string[dictionarysize]; 
	ReadWords("words_alpha.txt", dictionary); // dictionary is an array of strings
	//print first 5 words from the dictionary

	//Write your code here for filling the canvas with different Alphabets. You can use the Getalphabet function for getting the random alphabets
	//initializes array Alphabets with random numbers for the rows<nfrows
	for (int i=0; i<nfrows; i++)
	{
		for (int j=0; j<cells; j++)
			Alphabets[i][j]=GetAlphabet();
	}
	for (int i=nfrows; i<rows; i++)
	{
		for (int j=0; j<cells; j++)
			Alphabets[i][j]=27;
	}
	AlphShooter=GetAlphabet();
	AlphSecond=GetAlphabet();


	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Zs Word Shooter"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	RegisterTextures();
	glutDisplayFunc(DisplayFunction); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse

	//// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0/FPS, Timer, 0);

	//// now handle the control to library and it will call our registered functions when
	//// it deems necessary...

	glutMainLoop();

	return 1;
}

void Pixels2Cell(int px, int py, int & cx, int &cy) 
{
	cx=(px-10)/60;
	cy=13-(py-100)/60;
}

string exclude_last_letter(string x)
{
	string t;
	for (int i=0; i<x.length()-1; i++)
		t+=x[i];
	return t;
}

char Number2Alphabet(int x) //takes a number as input and returns its character alternative according to the defined enum but in small case cuz all dictionary words are in small case
{
	return static_cast<char>(x+97);
}

bool InDictionary(string x)
{
	for (int i=0; i<=370098; i++)
	{
		if (dictionary[i]==x)
		{
			your_words[word_number]=dictionary[i];
			word_number++;
			popped=true;
			return true;
		}
	}
	return false;
}

string reverse_word(string x)
{
	string t;
	for (int i=x.length()-1; i>=0; i--)
		t+=x[i];
	return t;
}

void check_pop_word(string temp_word)
{
	while (temp_word.length()>2)
	{//checks combinations of length >3
		if (InDictionary(temp_word)==1 || InDictionary(reverse_word(temp_word))==1)
		{
			score+=temp_word.length();
			for (int i=0; i<temp_word.length(); i++)
				Alphabets[letter_coordinates[0][i]][letter_coordinates[1][i]]=27;
			break;
		}
		temp_word=exclude_last_letter(temp_word);
	}
	for (int i=0; i<9; i++)
	{
		letter_coordinates[0][i]=-1;
		letter_coordinates[1][i]=-1;
	}
}

string form_word(int a)
{
/* for combination of letters
a=1 vertically upwards
a=2 diagonally right
a=3 diagonally left 
a=4 horizontally right
a=5 horizontally left
*/
	int y=tile_y;
	int x=tile_x;
	int k=0;
	bool condition=true; //determines if the condition for the given case should be true or not
	string word="";
	do
	{
		word+=Number2Alphabet(Alphabets[y][x]);
		letter_coordinates[0][k]=y;
		letter_coordinates[1][k]=x;
		switch(a)
		{
			case 1:
			{
				y--;
				condition=(y>=0 && word.length()<9 && Alphabets[y][x]!=27);
				break;
			}
			case 2:
			{
				y--;
				x++;
				condition=(word.length()<9 && y>=0 && x<cells && Alphabets[y][x]!=27);
				break;
			}
			case 3:
			{
				y--;
				x--;
				condition=(word.length()<9 && y>=0 && x>=0 && Alphabets[y][x]!=27);
				break;
			}
			case 4:
			{
				x++;
				condition=(word.length()<9 && x<cells && Alphabets[y][x]!=27);
				break;
			}
			case 5:
			{
				x--;
				condition=(word.length()<9 && x>=0 && Alphabets[y][x]!=27);
				break;
			}
		}
		k++;
	}while(condition);
	return word;
}
#endif /* */

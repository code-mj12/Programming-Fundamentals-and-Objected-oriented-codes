/*
 * Rectangle.h
 *
 *  Created on: Apr 25, 2019
 *      Author: hassan
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include"Shape.h"
class Rectangle: public Shape
{
private:
	int height;
	int width;
public:
	Rectangle();
	Rectangle(string t, int h, int w);
	float area ();
	void Display();
	int getHeight() const;
	int getWidth() const;
};

#endif /* RECTANGLE_H_ */

/*
 * Circle.h
 *
 *  Created on: Apr 25, 2019
 *      Author: hassan
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_
#include"Shape.h"
class Circle:public Shape
{
private:
	int radius;

public:
Circle();
Circle(string t, int r);
float area ();
virtual void Display();
int getRadius() const ;
};

#endif /* CIRCLE_H_ */

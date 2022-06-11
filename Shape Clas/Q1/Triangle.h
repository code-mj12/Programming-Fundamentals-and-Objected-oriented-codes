/*
 * Triangle.h
 *
 *  Created on: Apr 25, 2019
 *      Author: hassan
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include"Shape.h"
class Triangle:public Shape
{
private:
float base;
float height;

public:
	Triangle();
	Triangle(string t, float b, float h);
	float area ();
	void Display();
	float getBase() const ;
	float getHeight() const;
};

#endif /* TRIANGLE_H_ */

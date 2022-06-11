/*
 * Shape.h
 *
 *  Created on: Apr 25, 2019
 *      Author: hassan
 */

#ifndef SHAPE_H_
#define SHAPE_H_
#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
class Shape
{
protected:
	string type;
public:
	Shape();
	Shape(string t);
virtual float area ()=0;
virtual void Display();
const string& getType() const;
virtual ~Shape();
void setType(const string& type);
};

#endif /* SHAPE_H_ */

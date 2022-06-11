//Asfand Ali Irfan 19I-1656 AI-J

#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle():Shape() {
	radius=0;
}
Circle::Circle(string t, int r):Shape(t) {
	radius=r;
}
float Circle::area () {
	return 3.14*(float)radius*(float)radius;
}
void Circle::Display() {
	Shape::Display();
	cout<<"Radius: "<<radius<<endl;
}
int Circle::getRadius() const  {
	return radius;
}


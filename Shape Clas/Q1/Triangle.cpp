//Asfand Ali Irfan 19I-1656 AI-J

#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle():Shape() {
	base=0;
	height=0;
}
Triangle::Triangle(string t, float b, float h):Shape(t) {
	base=b;
	height=h;
}
float Triangle::area () {
	return 0.5*base*height;
}
void Triangle::Display() {
	Shape::Display();
	cout<<"Base: "<<base<<endl;
	cout<<"Height: "<<height<<endl;
}
float Triangle::getBase() const  {
	return base;
}
float Triangle::getHeight() const {
	return height;
}

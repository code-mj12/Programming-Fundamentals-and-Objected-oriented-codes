//Asfand Ali Irfan 19I-1656 AI-J

#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle():Shape() {
	height=0;
	width=0;
}
Rectangle::Rectangle(string t, int h, int w):Shape(t) {
	height=h;
	width=w;
}
float Rectangle::area () {
	return height*width;
}
void Rectangle::Display() {
	Shape::Display();
	cout<<"Height: "<<height<<endl;
	cout<<"Width: "<<width<<endl;
}
int Rectangle::getHeight() const {
	return height;
}
int Rectangle::getWidth() const {
	return width;
}

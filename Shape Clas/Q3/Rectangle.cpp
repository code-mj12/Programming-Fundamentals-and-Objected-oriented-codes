#include<iostream>
#include"Rectangle.h"
using namespace std;

    Rectangle::Rectangle()
	{
		length=0;
		width=0;
	}
	Rectangle::Rectangle(int h, int w)
	{
		length=h; 
		width=w;
	}
	float Rectangle::getarea ()
	{
		return (length*width);
	}
    float Rectangle::getperimeter()
	{
		return (2*(length+width));
	}
	void Rectangle::Display()
	{
		cout<<"length: "<<length<<endl;
		cout<<"Width: "<<width<<endl;
	}
	int Rectangle::getLength() const
	{
		return length;
	}
	int Rectangle::getWidth() const
	{
		return width;
	}
#include<iostream>
#include"Square.h"
using namespace std;

    Square::Square()
	{
		side=0;
	}
	Square::Square(int s)
	{
		side=s;
	}
	float Square::getarea ()
	{
		return (side*side);
	}
    float Square::getparameter ()
	{
		return (side*4);
	}
	void Square::Display()
	{
		cout<<"Side length: "<<side<<endl;
	}
	int Square::getSide() const
	{
		return side;
	}
//Asfand Ali Irfan 19I-1656 AI-J

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
using namespace std;

int main() {
	int choice,choice2;
	Shape* shapes[3];
	cout<<"Enter radius of circle: ";
	cin>>choice;
	shapes[0]= new Circle("Circle",choice);
	cout<<"Enter height of rectangle: ";
	cin>>choice;
	cout<<"Enter width of rectangle: ";
	cin>>choice2;
	shapes[1]= new Rectangle("Rectangle",choice,choice2);
	cout<<"Enter height of triangle: ";
	cin>>choice;
	cout<<"Enter base of triangle: ";
	cin>>choice2;
	shapes[2]= new Triangle("Triangle",choice2,choice2);
	for(int i=0;i<3;i++) {
		cout<<"Shape "<<i+1<<":"<<endl;
		shapes[i]->Display();
		cout<<"Area of shape: "<<shapes[i]->area()<<endl;
	}
	return 0;
}



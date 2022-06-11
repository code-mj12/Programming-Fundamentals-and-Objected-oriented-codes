//Asfand Ali Irfan 19I-1656 AI-J

#include "Shape.h"
Shape::Shape() {
	type="";
}
Shape::Shape(string t) {
	type=t;
}
void Shape::Display() {
	cout<<"Type: "<<type<<endl;
}
const string& Shape::getType() const {
	return type;
}
Shape::~Shape() {}
void Shape::setType(const string& type) {
	this->type=type;
}

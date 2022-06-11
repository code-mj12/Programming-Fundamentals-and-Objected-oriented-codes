#include <iostream>
#include "Instructor.h"
using namespace std;

Instructor::Instructor(){
    lastName = '\0';
    firstName = '\0';
    officeNumber = '\0';
}

Instructor::~Instructor(){}

Instructor::Instructor(const Instructor &other){
    lastName=other.lastName;
    firstName=other.firstName;
    officeNumber=other.officeNumber;
}
void Instructor::set(string lname, string fname, string office){
    lastName=lname;
    firstName=fname;
    officeNumber=office;
}
void Instructor::print() const{
    cout<<"Last Name: "<<lastName<<endl<<"First Name: "<<firstName<<endl<<"Office Number"<<officeNumber<<endl;
}
#include <iostream>
#include "Course.h"
using namespace std;

Course::Course(string course, string instrLastName, string instrFirstName, string instrOffice, string textTitle, string author,string publisher){
        courseName=course;
        instructor.set(instrLastName, instrFirstName, instrOffice);
        textbook.set(textTitle, author, publisher);
            }
Course::Course(const Course &other){
    courseName=other.courseName;
    instructor=other.instructor;
    textbook=other.textbook;
}          

void Course::print()const{
    cout<<"Course Name"<<courseName<<endl;
    instructor.print();
    textbook.print();
}

Course::~Course(){}


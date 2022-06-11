/*
 * Course.h
 *
 *  Created on: 03 Apr 2020
 *      Author: user
 */

#ifndef COURSE_H_
#define COURSE_H_
#include <iostream>
#include <string>
#include "Instructor.h"
#include "TextBook.h"
using namespace std;

class Course {
private:
string courseName;// Course name
Instructor instructor; // Instructor
TextBook textbook;// Textbook
public:
	// Constructor
			Course(string course, string instrLastName,
			string instrFirstName, string instrOffice,
			string textTitle, string author,
			string publisher);
			// print function
			void print() const;
	virtual ~Course();
	Course(const Course &other);
};

#endif /* COURSE_H_ */

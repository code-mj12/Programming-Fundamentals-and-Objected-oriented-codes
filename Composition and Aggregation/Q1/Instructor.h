/*
 * Instructor.h
 *
 *  Created on: 03 Apr 2020
 *      Author: user
 */

#ifndef INSTRUCTOR_H_
#define INSTRUCTOR_H_
#include<string>
using namespace std;

class Instructor {
string lastName;// Last name
string firstName;// First name
string officeNumber; // Office number
public:
	Instructor();
	virtual ~Instructor();
	Instructor(const Instructor &other);
	void set(string lname, string fname, string office);
	// print function
	void print() const;
};

#endif /* INSTRUCTOR_H_ */


#ifndef PROFESSOR_H_
#define PROFESSOR_H_
#include <iostream>
using namespace std;


class Professor {
	string name;
	int employeeID;
	string Designation;
public:
	Professor();
	Professor(string, int, string);
	void setName(string n);
	string getName() const;
	void setEmployeeID(int id);
	int getEmployeeID() const;
	void setDesignation(string d);
	string getDesignation() const;
};

#endif
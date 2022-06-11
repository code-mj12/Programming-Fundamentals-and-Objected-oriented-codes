
#ifndef UNIVERSITY_H_
#define UNIVERSITY_H_
#include <iostream>
#include "Department.h"
#include "Professor.h"
using namespace std;

class University {
string name;
int numberOfDepartments;
Department* dept;
public:

	University(string n, int num);
	void setName(string n);
	string getName() const;
	void setnumberOfDepartments(int n);
	int getnumberOfDepartments() const;
	void setDept(const Department &d );
	Department getDept() const;
	bool addDepartment(Department );
	bool deleteDepartment(string);
	bool updateDepartment(int, string );
	void display();
	virtual ~University();
};

#endif
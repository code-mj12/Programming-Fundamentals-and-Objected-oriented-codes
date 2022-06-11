
#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_
#include <iostream>
#include "Professor.h"
using namespace std;

class Department {
	string name;
	Professor* profList;
	int noOfProfessors;
	int deptID;
public:
	Department();
	Department(string, int, int);
	void setDeptID(int i);
	int getDeptID() const;
	void setName(string n);
	string getName() const;
	void setnoOfProfressors(int n);
	int getnoOfProfessors() const;
	bool addProfessor(Professor p);
	bool deleteProfessor (int id);
	bool updateProfessor (int , string );
	void display();
	virtual ~Department();
};

#endif
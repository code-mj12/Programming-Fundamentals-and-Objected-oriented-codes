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


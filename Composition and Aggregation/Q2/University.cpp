#include <iostream>
#include "Department.h"
#include "Professor.h"
#include "University.h"
using namespace std;

/*
string name;
int numberOfDepartments;
Department* dept;

	string name;
	Professor* profList;
	int noOfProfessors;
	int deptID;
*/

    University::University(string n, int num){
        name = n;
        numberOfDepartments = num;
        dept = new Department[num];
    }
	void University::setName(string n){
        name = n;
    }
	string University::getName() const{
        return name;
    }
	void University::setnumberOfDepartments(int n){
        numberOfDepartments = n;
    }
	int University::getnumberOfDepartments() const{
        return numberOfDepartments;
    }
	void University::setDept(const Department &d ){
        //dept =d;
    }
	Department University::getDept() const{
        return *dept;
    }
	bool University::addDepartment(Department a){

    }
	bool University::deleteDepartment(string a){
        for (int  i = 0; i < numberOfDepartments; i++)
        {
            if(dept[i].getName() == a) {   
                dept[i].setName('\0');
                dept[i].setDeptID(0);
                dept[i].setnoOfProfressors(0);
                return true;
            }
        }
    }
	bool University::updateDepartment(int id, string n){
        for (int  i = 0; i < numberOfDepartments; i++)
        {
            if(dept[i].getDeptID() == id) {   
                dept[i].setName(n);
                return true;
            }
        }
        
    }
	void University::display(){
        cout<<"Uni Name: "<<name<<endl
        <<"No. of Dept.: "<<numberOfDepartments<<endl;
        for (int i = 0; i < numberOfDepartments; i++)
        {
            dept[i].display();
        }
        
    }
	
    University::~University(){}
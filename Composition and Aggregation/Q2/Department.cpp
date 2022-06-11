#include <iostream>
#include "Professor.h"
#include "Department.h"
using namespace std;

    Department::Department(){
        name = '\0';
        noOfProfessors = 0;
        deptID = 0;
        profList = NULL;
    }
	Department::Department(string n, int d, int pn){
        name = n;
        noOfProfessors = pn;
        deptID = d;
        profList = new Professor[noOfProfessors];
    }
	void Department::setDeptID(int i){
        deptID=i;
    }
	int Department::getDeptID() const{
        return deptID;
    }
	void Department::setName(string n){
        name = n;
    }
	string Department::getName() const{
        return name;
    }
	void Department::setnoOfProfressors(int n){
        noOfProfessors =n;
    }
	int Department::getnoOfProfessors() const{
        return noOfProfessors;
    }   

	bool Department::addProfessor(Professor p){

    }
	
    bool Department::deleteProfessor (int id){
        for (int i = 0; i < noOfProfessors; i++)
        {
            if(profList[i].getEmployeeID() == id){
                profList[i].setEmployeeID(0);
                profList[i].setDesignation('\0');
                profList[i].setName('\0');
                return true;
            }
        }    
    }

	bool Department::updateProfessor (int id, string newdesig){
       for (int i = 0; i < noOfProfessors; i++)
        {
            if(profList[i].getEmployeeID() == id){
                profList[i].setDesignation(newdesig);
                return true;
                }
            }
        }

	void Department::display(){
        cout<<"Name: "<<name<<endl
        <<"No. of prof: "<<noOfProfessors<<endl
        <<"Dept. ID: "<<deptID<<endl;

        for (int i = 0; i < noOfProfessors; i++)
        {
            cout<<"Name of prof: "<<profList[i].getName()<<endl
            <<"Emp. ID: "<<profList[i].getEmployeeID()<<endl<<
            "Designation: "<<profList[i].getDesignation()<<endl;
        }
        
    }
	Department::~Department(){}
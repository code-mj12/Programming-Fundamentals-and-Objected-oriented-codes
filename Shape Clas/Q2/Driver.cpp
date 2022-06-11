#include "Driver.h"
#include <iostream>
using namespace std;

Driver::Driver(){
    Salary = 0;
}
Driver::Driver( int Emp_no, int salary){
    	this->Emp_no= Emp_no;
		this->Salary= salary;
}
int Driver::getSalary()
	{
		return Salary;
	}
void Driver::setSalary(int s)
	{
		Salary =s;
	}

/*
 * Developer.h
 *
 *  Created on: Apr 15, 2020
 *      Author: Tayyaba
 */


#include"Employee.h"
class Developer:public Employee
{
private:
	int salary;

public:
	Developer()
	{
		salary=0;
	}
	Developer( int Emp_no, int salary)
	{
		this->Emp_no= Emp_no;
		this->salary= salary;
	}
	int getSalary()
	{
		return salary;
	}
    void setSalary(int s)
	{
		salary =s;
	}
	

};


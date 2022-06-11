/*
 * Developer.h
 *
 *  Created on: Apr 15, 2020
 *      Author: Tayyaba
 */

#ifndef DEVELOPER_H_
#define DEVELOPER_H_
#include"Employee.h"
class Developer:public Employee
{
private:
	int salary;

public:
	Developer();
	Developer( int Emp_no, int salary);
	int getSalary();
        void setSalary(int s);
	

};

#endif /* DEVELOPER_H_ */

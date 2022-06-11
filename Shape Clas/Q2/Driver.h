/*
 * Driver.h
 *
 *  Created on: Apr 15, 2020
 *      Author: Tayyaba
 */

#ifndef DRIVER_H_
#define DRIVER_H_
#include"Employee.h"
class Driver:public Employee
{
private:
	int Salary;

public:
	Driver();
	Driver( int Emp_no, int salary);
	int getSalary();
    void setSalary(int s);
	

};

#endif /* DRIVER_H_ */

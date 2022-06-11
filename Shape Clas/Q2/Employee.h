/*
 * Employee.h
 *
 *  Created on: Apr 25, 2019
 *      Author: hassan
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
class Employee{
protected:
	int Emp_no;

public:
	Employee();
	Employee(int e);
	virtual int getSalary()=0;
	int getEmpNo() const;
	void setEmpNo(int empNo);
};

#endif /* EMPLOYEE_H_ */

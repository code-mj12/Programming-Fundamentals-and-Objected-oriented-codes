#include <iostream>
using namespace std;

class Date{
public:
    int d;
    int m;
    int y;
    Date():d(0),m(0),y(0){}
    Date(int dy, int my, int yy): d(dy), m(my), y(yy) {}
    Date(Date &d1){
        d = d1.d;
        m = d1.m;
        y = d1.y;
    }

    int getD()
    {
        return this->d;
    }
    void setD(int d)
    {
        this->d = d;
    }
    int getM()
    {
        return this->m;
    }
    void setM(int m)
    {
        this->m = m;
    }
    int getY()
    {
        return this->y;
    }
    void setY(int y)
    {
        this->y = y;
    }   
};

class Person{
    string name;
    string address;
public:
    Person(){
        name = '\0';
        address = '\0';
    }
    Person(string n, string a){
        name = n;
        address = a;
    }
    Person(Person &p){
        address = p.address;
        name = p.name;
    }
};

class Employee : public Person{
    int emp_num;
    Date hire_date;
public:
    Employee(){
        emp_num=0;
        hire_date.setD(0);
        hire_date.setM(0);
        hire_date.setY(0);
        }
    Employee(int e, Date d, string n, string a): Person(n, a){
        emp_num = e;
        hire_date.setD(d.d);
        hire_date.setM(d.m);
        hire_date.setY(d.y);
    }
};

class ProductionWorker : public Employee{
protected:
    int shift;
    double pay_rate;
public:
    ProductionWorker(int s, double p, int e, Date d, string n, string a): Employee(e, d, n, a)
    {
        shift = s;
        pay_rate = p;
    }
};

class TeamLeader :public ProductionWorker{
protected:
    double bonus;
    int req_hrs;
    int hrs_attended;
public:
    TeamLeader(double b, int r, int h, int s, double p, int e, Date d, string n, string a)
    :ProductionWorker(s, p, e, d,n, a),bonus(b), req_hrs(r), hrs_attended(h) {}
    
    double calculateSalary(Date dt){
        double sal = bonus * dt.d/30;
        sal = sal + dt.d * pay_rate * 8;
        return sal;
    }

};

int main(){
    Date d1(5,10,12);
    string nam = "Majid";
    string add = "ISB";
    TeamLeader t(500,5,2,1,50,1900,d1,nam,add);
    cout<<"Salary is :"<<t.calculateSalary(d1)<<endl;
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream obj("Student.txt");
    obj<<"123 Asad Ali CS A"<<endl;
    obj<<"321 Abbas Khan EE C."<<endl;
    obj<<"342 Bilal Haider FSM A."<<endl;
    obj<<"123 Asad Ali CS A"<<endl;
    obj<<"321 Abbas Khan EE C."<<endl;
    obj<<"342 Bilal Haider FSM A."<<endl;
    obj<<"123 Asad Ali CS A"<<endl;
    obj<<"321 Abbas Khan EE C."<<endl;
    obj<<"342 Bilal Haider FSM A."<<endl;
    obj<<"123 Asad Ali CS A"<<endl;
}
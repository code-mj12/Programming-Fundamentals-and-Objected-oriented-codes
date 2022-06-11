#include <iostream>
using namespace std;

class animal{
    string name;
    int age;

public:
    animal(){
        name ='\0';
        age = 0;
    }
    animal(string n, int a){
        name = n;

    }
    string getName()
    {
        return this->name;
    }
    void setvalue(string name, int age)
    {
        this->age = age;
        this->name = name;
    }
    int getAge()
    {
        return this->age;
    }
    void display(){
        cout<<name<<endl<<age<<endl;
    }
};
class zebra : public animal{
    string PoO;
public:
    zebra(animal a, string p){
        setvalue("zebra", a.getAge());
        PoO = p;
    }
    void display(){
        cout<<"Plsce of origin is : "<<PoO<<endl;
        animal::display();
    }
};
class Dolphin : public animal{
    string PoO;
public:
    Dolphin(animal a, string p){
        setvalue("Dolphin", a.getAge());
        PoO = p;
    }
    void display(){
        cout<<"Plsce of origin is : "<<PoO<<endl;
        animal::display();
    }
};


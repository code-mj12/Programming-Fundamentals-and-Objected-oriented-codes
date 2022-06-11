#include<iostream>
#include"String.h"
using namespace std;

int main(){
    char fa[5]={"ALIM"};
    String a(5);
    String b(fa);
    String c(10);
    cout<<"ADDING STRING"<<endl;
    c = a + b;
    
    cout<<c<<endl; 

     cout<<"lenght of String b: "<<b.length()<<endl;




}
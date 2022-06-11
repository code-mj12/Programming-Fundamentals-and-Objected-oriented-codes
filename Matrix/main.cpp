#include "Matrix.h"
#include "Matrix.cpp"
#include <iostream>
using namespace std;

int main(){

Matrix M1(2, 2);
    cout<<endl;
    cout<<"Input TO THE matrix M1\'s"<<endl;

    cout<<endl;
    cin>>M1;
    cout<<endl;
    cout<<"Values for first matrix M1: "<<endl;
    cout<<M1<<endl;

	Matrix M2(2,2);
	M2 = M1;

    cout<<"Values for second matrix: M2"<<endl;
    cout<<M2<<endl;

    M2 += M1;
    cout<<"Values for second matrix: M2"<<endl;
    cout<<M2<<endl;

    M2=M1;
	M2 -= M1;
    cout<<"Values for second matrix M2: should be 0s "<<endl;
    cout<<M2<<endl;

    M2=M1;
	M2 = M2+M1;
    cout<<"Values for second matrix M2: "<<endl;
    cout<<M2<<endl;

    M2=M1;
	M2 = M2-M1;
    cout<<"Values for second matrix M2: should be 0s"<<endl;
    cout<<M2<<endl;

    if((M1==M2)==1){
        cout<<"EQUAL"<<endl;
    }else{
        cout<<"Not EQUAL"<<endl;
    }

}
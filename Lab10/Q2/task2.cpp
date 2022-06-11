#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printlines(int, string); 

int main(){
//    cout<<"test";
    printlines(5,"Student.txt");
//    cout<<"test";
}

void printlines(int n, string f){
    //cout<<"test";
    ifstream obj(f);
    ifstream obj1(f);
    string a;
//cout<<"test";
    int i=0;
    int count=0;

    while(!(obj1.eof())){
        getline(obj1,a);
        i++;
    }
    cout<<i<<endl;

    if(i<n || i==n){
        //cout<<"test2";
        while( !obj.eof()){
          //  cout<<"test4";
            getline(obj,a);
            cout<<a<<endl;
            //cout<<"test3";
        }
    }
    else{
        //cout<<"test4";
        while( !obj.eof()){
            getline(obj,a);
            count++;
            //cout<<"test5";
            if(count >= (i-n)){
                cout << a << endl;
            }
        }
    }
    
}

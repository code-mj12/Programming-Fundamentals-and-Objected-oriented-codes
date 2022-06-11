#include <iostream>
#include<iostream>
#include<fstream>
#include<string>
#include "Vowels.cpp"
using namespace std;
int main()
{
    cout<<"Enter filename: ";
    string fname;
    cin>>fname;
    Vowels v1(fname);
    int line_nos;
    line_nos = v1.getNumberOfLines();
    v1.setNumberOfLines(line_nos);
    v1.VowelGame();

}

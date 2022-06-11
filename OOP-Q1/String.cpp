#include<iostream>
#include"String.h"
using namespace std;

String:: String(){
    arr = nullptr;
    size = 0;
    cout << "Default Constructur" <<  endl;
} 

String::String(char*str){
    int temp;

    for (int i = 0; *(str+i)!='\0'; i++)
    {
        temp=i;   
    }
    
    arr=new char[temp];
    size=temp;

    for (int i = 0; *(str+i)!='\0'; i++)
    {
        arr[i]=str[i];
    }
}

String:: String(int x){
    arr = new char[x];
    size = x;
    cout << "Constructure with size as perimeter" << endl;
}

char& String::operator[](int i)// returns the character at index [x]
{
    return arr[i];
}

String String::operator+(const String &str)// append a String at the end of string
{
    int u=0;
    while(arr[u]!='\0')
        {
            u++;
        }
    int s=0;
    s=str.size;
    s = s +u;
    String tmp(s+1);
    tmp.arr=new char[s];
    for(int i=0;i<s;i++)
        {
            if(i<u){
                tmp.arr[i]=arr[i];}

        }
    tmp.arr[u+1]='\0';
    return tmp;    
}

bool String::operator!()// returns true if string is empty..
{
    if(!(arr[0]=='\0'))
        {
            return false;
        }
        else
        {
            return true;
        }
}

bool String::operator==(const String& S1)const//returns true if two strings are equal
{
     int len=0;

        while(S1.arr[len]!='\0')
        {
            len++;
        }
        int total=0;
        for (int i = 0;arr[i]!='\0'; i++)
        {
            if (arr[i]==S1.arr[i])
            {
                total++;
            }
            
        }
        if (total==len)
        {
            return true;
        }
        return false;
}

int String::operator()(char searched)// returns the index of character being searched.
{
        int i=0;
        while( arr[i]!='\0') ///nfgnhgn
        {
            if(!(arr[i]=='\0'))
            {}
            else
            {
                return i;
            }
            i++;
        }	
}

int String::length()// returns the length of string
{
       int len=0;
       int i=0;
        while( arr[i]!='\0')
        {
            ++len;
            ++i;
        }
        return len; 
}

String::~String() {
 delete[]arr;
}


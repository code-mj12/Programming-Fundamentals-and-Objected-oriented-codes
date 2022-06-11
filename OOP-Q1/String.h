#ifndef STRING_H_
#define STRING_H_
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class String
{
	// think about the private data members...
char *arr;
int size;

public:// provide definitions of following functions...
String();// default constructor
String(char*str);// initializes the string with constant cstring
String(const String &);// copy constructor to initialize the string from existing string
String(int x);// initializes a string of pre-defined size
char&operator[](int i);// returns the character at index [x]
String operator+(const String &str);// append a String at the end of string
bool operator!();// returns true if string is empty..
bool operator==(const String&)const;//returns true if two strings are equal
int operator()(char);// returns the index of character being searched.

int length();// returns the length of string
~String();// destructor...};

};


#endif /* STRING_H_ */




String::String() {
	// TODO Auto-generated constructor stub
}
String::String(char*str)// initializes the string with constant cstring
{

}
String::String(const String & S1)// copy constructor to initialize the string fromexisting string
{

}
String::String(int x)// initializes a string of pre-defined size
{

}
char& String::operator[](int i)// returns the character at index [x]
{

}

String String::operator+(const String &str)// append a String at the end of string
{

}
bool String::operator!()// returns true if string is empty..
{
}
bool String::operator==(const String& S1)const//returns true if two strings are equal
{

}

int String::operator()(char searched)// returns the index of character being searched.
{
	
}
int String::length()// returns the length of string
{
	
}

String::~String() {
}


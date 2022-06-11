#ifdef SOME_NAME
#define SOME_NAME
#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;

class Shape
{
public:
virtual float getarea ()=0;
virtual float getparameter ()=0;

};
#endif
//============================================================================
// Name        : OOPLab15.cpp
// Author      : Fatima
// Version     :

//============================================================================

#include <iostream>
#include "Container.h"
using namespace std;

// function template to manipulate Container<T>
template<typename T>
void testContainer(Container<T> &thisContainer, T valueToBeInserted, T increment, T valueToSearch, T valueToRemove){
	cout << "Inserting values in the Container" << endl;

	for(int i=0;!thisContainer.isFull();i++){
		thisContainer.insert(valueToBeInserted);
		//change increment value
		valueToBeInserted += increment;
	}
	cout<<"value searching if 0 then false or esle true"<<thisContainer.search(valueToSearch)<<endl;
	cout<<"value removing "<<endl;
	thisContainer.remove(valueToRemove);
	thisContainer.Print();
	cout<<endl;
	}


int main() {
    ///////////////////// This code snippet is part of Question#02 (Function Template)/////////////////////////////////////
	cout << "Let's make container for int type" << endl;
		Container <int> bo(5);
		testContainer(bo,5,2,3,4);

	cout <<"*******************************************************************************************************" << endl;
	cout << "Let's make container for double type" << endl; //
		Container <double> bo1(5);
		testContainer(bo1,5.5,2.5,3.0,4.0);
	cout <<"*******************************************************************************************************" << endl;
	cout << "Let's make container for float type" << endl;
		Container <float> bo2(5);
		float a=1,b=2,c=3,d=4,e=5;
		testContainer(bo2,a,b,c,d);

	cout <<"*******************************************************************************************************" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	//////// This snippet can be used for normal function calls for Question#01///////////////*/
	cout << "Let's make container for int type Q1 functions are called" << endl; 
	Container <int> bod(2);
	bod.insert(5);
	bod.insert(6);
	cout<<"value searching if 0 then false or esle true"<<bod.isFull()<<endl;
	bod.Print();


	cout << "--------------------------------------------------------------------------------------------" << endl;

	cout << "Let's make container for double type Q1 functions are called" << endl; //
	Container <double> bod1(2);
	bod1.insert(2.5);
	bod1.insert(6.5);
	cout<<"value searching if 0 then false or esle true"<<bod1.isFull()<<endl;
	bod1.Print();		
	

	return 0;
}

//============================================================================
// Name        : STLTasks.cpp
// Author      : Fatima
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <iterator> // ostream_iterator
#include <algorithm>
using namespace std;

void square(int &val) {
	val= val*val;
} 

int main(){
	vector<int> v1;
	for(int i=1;i<=10;i++)
		v1.push_back(i);
	for_each(v1.begin(),v1.end(),square);
		vector<int> v2(v1.rbegin(),v1.rend());
		ostream_iterator<int> output(cout," ");
		cout<<"V1 is ";
	copy(v1.begin(),v1.end(),output);
		cout<<endl;
		cout<<"V2is ";
	copy(v2.begin(),v2.end(),output);
		cout<<endl;
		cout<<"Index of value 49 in V1: "<<distance(v1.begin(),find(v1.begin(),v1.end(),49))<<endl;
		cout<<"Equal is  if 0 true or else is false: "<<equal(v1.begin(),v1.end(),v2.begin(),v2.end())<<endl;
	replace(v1.begin(),v1.end(),16,100);
		copy(v1.begin(),v1.end(),output);
		cout<<endl;

	return 0;
}


#ifndef Vowels_H_
#define Vowels_H_
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Vowels {
	string fileName;
	int numberOfLines;
public:
	Vowels(string);
	int getNumberOfLines();
	string getFileName();
	void setNumberOfLines(int);
	void VowelGame();
	~Vowels();
};

#endif /* Vowels_H_ */

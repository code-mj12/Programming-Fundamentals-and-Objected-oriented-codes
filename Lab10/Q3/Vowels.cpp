
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include "Vowels.h"
#include <ctype.h>
using namespace std;

Vowels::Vowels(string fileName)
{
	this->fileName = fileName;
}
int Vowels::getNumberOfLines()
{
	int count;
	string STRING;
	ifstream myfile;
	myfile.open(fileName);
	while (getline(myfile, STRING))
	{
		count++;
	}
	return count;
}
string Vowels::getFileName()
{
	return fileName;
}
void Vowels::setNumberOfLines(int numberOfLines)
{
	this->numberOfLines = numberOfLines;
}
void Vowels::VowelGame()
{
	int char_cnt[10000];
	string STRING;
	int j;
	ifstream myfile;
	int vowel_cnt = 0;
	myfile.open(fileName);
	int vowel_first;
	while (getline(myfile, STRING))
	{
		for (int i = 0; i < (STRING.size()); i++)
		{
			if ((STRING[i] == 'a') || (STRING[i] == 'e') || (STRING[i] == 'i') || (STRING[i] == 'o') || (STRING[i] == 'u') || (STRING[i] == 'A') || (STRING[i] == 'E') || (STRING[i] == 'I') || (STRING[i] == 'O') || (STRING[i] == 'U'))
			{
				vowel_cnt++;
			}
			if ((STRING[i] >= 65 && STRING[i] <= 90) || (STRING[i] >= 97 && STRING[i] <= 122))
			{
				char_cnt[j]++;
			}
		}
		j++;
	}
	for (int i = 0; i < numberOfLines; i++)
	{
		cout << "Characters in line " << i+1 << " are " << char_cnt[i]<<endl;
	}
	cout << "Number of Vowels in "<<fileName<<" are: " << vowel_cnt<< endl;
}

Vowels ::~Vowels(){}

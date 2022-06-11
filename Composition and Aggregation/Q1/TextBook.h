/*
 * TextBook.h
 *
 *  Created on: 03 Apr 2020
 *      Author: user
 */

#ifndef TEXTBOOK_H_
#define TEXTBOOK_H_
#include <iostream>
#include <string>
using namespace std;

class TextBook {
private:
string title;// Book title
string author;// Author name
string publisher; // Publisher name
public:
	TextBook();
	// Constructor
	TextBook(string textTitle, string auth, string pub);
	// set function
	void set(string textTitle, string auth, string pub);
	// print function
	void print() const;
	virtual ~TextBook();
	TextBook(const TextBook &other);
};

#endif /* TEXTBOOK_H_ */

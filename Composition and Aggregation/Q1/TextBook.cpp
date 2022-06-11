#include <iostream>
#include "TextBook.h"
using namespace std;

TextBook::TextBook(){
    title = '\0';
    author = '\0';
    publisher = '\0';
}

TextBook::~TextBook(){}

TextBook::TextBook(const TextBook &other){
    title=other.title;
    author=other.author;
    publisher=other.publisher;
}
void TextBook::set(string textTitle, string auth, string pub){
    title=textTitle;
    author=auth;
    publisher=pub;
}
void TextBook::print() const{
    cout<<"Title:" <<title<<endl<<"Author: "<<author<<endl<<"Publisher: "<<publisher<<endl;
}
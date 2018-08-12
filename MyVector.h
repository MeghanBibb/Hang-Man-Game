
// Meghan Bibb
// 08/01/2018
// This file shows the contents of the MyVector object
// This will be used to store the contents of alphabet.txt for quicker access

#ifndef HANGMAN_MYVECTOR_H
#define HANGMAN_MYVECTOR_H

#include <string>
#include <iostream>

using namespace std;

class BADINDEX{};

class MyVector{

protected:
    int size;
    int capacity;
    string *data;

public:
    MyVector();
    ~MyVector();
    MyVector(const MyVector& that);
    MyVector& operator =(const MyVector& that);
    MyVector& pushFront(string item);
    MyVector& pushBack(string &item);
    MyVector& popFront(string& value); //throws BADINDEX
    MyVector& popBack(string& value); //throws BADINDEX
    int getSize();
    bool isEmpty();
    string operator [](int); //Throws BADINDEX

};

#endif //HANGMAN_MYVECTOR_H
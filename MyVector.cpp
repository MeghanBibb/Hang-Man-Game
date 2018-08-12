
// Meghan Bibb
// 08/01/2018
// This file holds the implemented functions of MyVector.h
// This will be used to store the contents of alphabet.txt for quicker access

#include "MyVector.h"

using namespace std;

    MyVector::MyVector(){
        this->size = 0;
        this->capacity = 5;
        this->data = new string[this->capacity];
    }
    MyVector::~MyVector(){
        this->size = 0;
        this->capacity = 0;
        delete [] this->data;
        data = NULL;
    }
    MyVector::MyVector(const MyVector& that){
        this->capacity = that.capacity;
        this->size = that.size;
        this->data = new string[capacity];
        for(int i = 0; i < that.size; i++){
            this->data[i] = that.data[i];
        }
    }
    MyVector& MyVector::operator =(const MyVector& that){
        if(this->data != that.data){
            this->capacity = that.capacity;
            this->size = that.size;
            this->data = new string[capacity];
            for(int i = 0; i < that.size; i++){
                this->data[i] = that.data[i];
            }
        }
        return *this;
    }
    MyVector& MyVector::pushFront(string item){

    }
    MyVector& MyVector::pushBack(string &item){
        if(this->size == this->capacity){
           //grows
        }
        data[size] = item;
        size++;
        return *this;
    }
    MyVector& MyVector::popFront(string& value){  //throws BADINDEX
        if(size <= -1){
            throw BADINDEX{};
        } else {



        }
        return *this;
    }
    MyVector& MyVector::popBack(string& value){ //throws BADINDEX

    }
    int MyVector::getSize(){
        return this->size;
    }
    bool MyVector::isEmpty(){
        bool empty;
        if(size <= -1){
            cout << "MYVECTOR IS EMPTY" << endl;
            empty = true;
        } else {
            empty = false;
        }
        return empty;
    }
    string MyVector::operator [](int) { //Throws BADINDEX
        return this->data[size];
    }
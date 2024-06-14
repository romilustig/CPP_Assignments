/* Assignment C++: 2
   Author Romi Lustig, ID: 211542089
   */

#include "Set.h"
#include <iostream>
using namespace std;

Set::Set(const int maxSize): maxSize(maxSize){
    arr = new int[maxSize]; // new dynamic array (needs to be deleted)
    currentSize = 0; // when setting new Set there's no elements
}

Set::Set(const Set &s): maxSize(s.maxSize){
    *this = s; // makes a deep copy already in = operator
}

Set::~Set() {
    delete[] arr; // deleting dynamic array
}

int Set::getcurrentSize() const{
    return currentSize; // in order to not change current size by any chance, I used a const function that
    // returns the wanted value
}

int Set::getmaxSize() const{
    return maxSize;
}

bool Set::isInSet(const int number) const{
    int same = 0; // flag to check if number is already in set
    for(int i = 0; i < this->currentSize; i++){
        if(this->arr[i] == number){
            same = 1;
            break; // break because there's no need to check anymore
        }
    }
    if(same == 1) return true;
    else return false;
}

Set &Set::operator =(const Set &other){  // makes deep copy
    if(this == &other){
        return *this; // no need to copy
    }
    currentSize = other.currentSize; // changes all of other Set's features
    arr = new int[other.maxSize];
    for(int i = 0; i<currentSize; i++){
        arr[i]= other.arr[i];
    }
    return *this;
}

Set & Set::operator+=(int number) { // returns by reference
    if(this->isInSet(number));
    else { // if not in: do the function
        if (currentSize < maxSize) { // no need to change the whole array, just add to the end of the list
            currentSize++;
            arr[currentSize - 1] = number;
        } else {
            int *tempArr = new int[maxSize + 1];
            for (int i = 0; i < maxSize; i++)
                tempArr[i] = arr[i];
            tempArr[maxSize] = number;
            delete arr; // now we have new array ready, so we can delete this one
            arr = tempArr;
            currentSize++;
        }
    }
    return *this;
}

Set Set::operator +(const int number) const{ // returns by value
    Set newSet = *this; // cpy constructor
    newSet += number; // already made an operator that adds an integer
    return newSet; // local memory; returns by value
}

Set Set::operator +(const Set & other) const{
    Set newSet(maxSize + other.getmaxSize()); // new Set which can contain all elements
    for(int i = 0; i<currentSize; i++){ // adds this array
        newSet.arr[i] = arr[i];
        newSet.currentSize++;
    }
    for(int j = 0; j<other.getcurrentSize(); j++){
        if(isInSet(other.arr[j])); // checks if number is already in array: if not, add the number
        else{
            newSet.arr[newSet.currentSize] = other.arr[j];
            newSet.currentSize++;
        }
    }
    return newSet; // returns by value
}

bool Set::operator >(const Set & other) const{
    if(other.currentSize < currentSize) // checks which Set has more elements in it (counted in current size)
        return true;
    else return false;
}

int Set::operator [](int i) const{
    return this->arr[i];
}

// FRIEND CLASS OPERATORS

Set operator + (int number, const Set & s){
    return s.Set::operator+(number); // does the same operator, but needs to support both ways
}

Set operator += (int number, Set & s){
    return s += number; // same as + operator
}

ostream & operator<<(ostream & out, const Set &s){ // to print << a few times
    out << "{";
    for(int i =0; i<s.getcurrentSize()-1; i++) // for loop to print each element
    out << s[i] << ',';
    out << s[s.currentSize-1];
    out << "}" << endl;
    return out;
}

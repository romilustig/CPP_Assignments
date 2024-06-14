/* Assignment C++: 2
   Author Romi Lustig, ID: 211542089
   */

#ifndef ASSIGNMENT2_SET_H
#define ASSIGNMENT2_SET_H
#include <iostream>
using namespace std;


class Set {
    const int maxSize; // maximal size of elements
    int currentSize{}; // current number of elements
    int *arr{}; // array of elements
public:
    Set(int maxSize = 1000); // default constructor + other constructor
    Set(const Set & s); // copy constructor
    ~Set();
    int getcurrentSize() const; // doesn't change object
    int getmaxSize() const;
    bool isInSet(int number) const;
    Set &operator =(const Set &other);
    Set &operator +=(int number);
    Set operator +(int number) const; // no need to change objects
    Set operator +(const Set & other) const;
    bool operator >(const Set & other) const;
    int operator[] (int i) const;
    // FRIEND OPERATORS
    friend Set operator + (int number, const Set & s);
    friend ostream & operator<<(ostream & out, const Set &s);
};

#endif //ASSIGNMENT2_SET_H
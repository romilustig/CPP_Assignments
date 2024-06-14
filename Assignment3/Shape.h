//
// Created by Romi Lustig on 12/01/2023.
//

#ifndef ASSIGNMENT3_SHAPE_H
#define ASSIGNMENT3_SHAPE_H
#include <cmath>
#include <iostream>
using namespace std;

class Shape {
    char * colour;
public:
    Shape(const char * colour);
    virtual double getPerimeter() const = 0;
    virtual double getArea() const = 0;
    char * getColour() const{return colour;};
    virtual void draw() const;
    virtual void printDetails() const{};
    virtual ~Shape();
    friend ostream & operator<<(ostream & out, const Shape &s);
};

#endif //ASSIGNMENT3_SHAPE_H

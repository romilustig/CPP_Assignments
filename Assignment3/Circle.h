//
// Created by Romi Lustig on 12/01/2023.
//

#ifndef ASSIGNMENT3_CIRCLE_H
#define ASSIGNMENT3_CIRCLE_H

#include "Shape.h"

using namespace std;

class Circle: public Shape{
    const double radius;
public:
    Circle(double radius = 0, const char * colour = "white"): radius(radius), Shape(colour){
        if(radius < 0) throw(double)(0);
    };
    virtual ~Circle(){};
    virtual double getPerimeter() const;
    virtual double getArea() const;
    virtual void printDetails() const;
};

#endif //ASSIGNMENT3_CIRCLE_H

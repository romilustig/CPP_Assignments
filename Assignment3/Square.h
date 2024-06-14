//
// Created by Romi Lustig on 12/01/2023.
//

#ifndef ASSIGNMENT3_SQUARE_H
#define ASSIGNMENT3_SQUARE_H
#include "Shape.h"

class Square: public Shape{
    const double side;
public:
    Square(double side = 0, const char * colour = "white"): side(side), Shape(colour){
        if(side < 0) throw(double)(0);
    };
    virtual ~Square(){/*cout << "Square Dtor"*/};
    virtual double getPerimeter() const;
    virtual double getArea() const;
    virtual void draw() const;
    virtual void printDetails() const;
};

#endif //ASSIGNMENT3_SQUARE_H

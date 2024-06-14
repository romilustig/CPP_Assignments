//
// Created by Romi Lustig on 12/01/2023.
//

#ifndef ASSIGNMENT3_ORTHOGONALTRIANGLE_H
#define ASSIGNMENT3_ORTHOGONALTRIANGLE_H

#include "Shape.h"

class OrthogonalTriangle: public Shape {
    double triSides; // triangle sides
public:
    OrthogonalTriangle(double triSides = 0, const char * colour = "white"): triSides(triSides), Shape(colour){
        if(triSides < 0) throw(double)(0);
    };
    virtual ~OrthogonalTriangle(){};
    virtual double getPerimeter() const;
    virtual double getArea() const;
    void draw() const;
    virtual void printDetails() const;
};


#endif //ASSIGNMENT3_ORTHOGONALTRIANGLE_H

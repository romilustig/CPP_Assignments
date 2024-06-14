//
// Created by Romi Lustig on 12/01/2023.
//

#include "Circle.h"

double Circle::getPerimeter() const{
    return 2 * radius * M_PI;  // 2 * (pi in c_math) * r
}

double Circle::getArea() const {
    return radius * radius * M_PI; // (pi in C_math) * r^2
}

void Circle::printDetails() const{
    cout << "Circle details: color=" << this->getColour() << ", radius=" << radius << endl;
    cout << "area= " << this->getArea() << ", perimeter=" << this->getPerimeter() << endl;
}
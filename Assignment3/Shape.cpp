//
// Created by Romi Lustig on 12/01/2023.
//

#include "Shape.h"
#include <cstring>

Shape::Shape(const char *colour) {
    if(strcmp(colour, "red") == 0 || strcmp(colour, "green") == 0 || strcmp(colour, "blue") == 0) {
        this->colour = new char(sizeof(colour));
        strcpy(this->colour, colour);
    }
    else throw 0; // THROWS EXCEPTION
}

void Shape::draw() const{
    throw (float)(0);
}

Shape::~Shape() {
    delete colour;
    cout << "Shape Dtor" << endl;
}

ostream & operator<<(ostream & out, const Shape &s){
    s.printDetails();
    out << endl;
    return out;
}

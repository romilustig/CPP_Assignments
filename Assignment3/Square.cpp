//
// Created by Romi Lustig on 12/01/2023.
//

#include "Square.h"

double Square::getPerimeter() const {
    return 4 * side;
}

double Square::getArea() const {
    return side * side;
}

void Square::draw() const {
    for(int i = 0; i < (int)(side); i++) {
        for (int j = 0; j < (int) (side); j++)
            cout << '*';
        cout << endl;
    }
}

void Square::printDetails() const{
    cout << "Square details: color=" << this->getColour() << ", side length=" << side << endl;
    cout << "area= " << this->getArea() << ", perimeter=" << this->getPerimeter() << endl;
}
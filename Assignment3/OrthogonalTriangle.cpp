//
// Created by Romi Lustig on 12/01/2023.
//

#include "OrthogonalTriangle.h"

double OrthogonalTriangle::getPerimeter() const {
    return 2 * triSides + M_SQRT2 * triSides; // sqrt(2) in c_math
}

double OrthogonalTriangle::getArea() const {
    return (triSides * triSides) / 2;
}

void OrthogonalTriangle::draw() const {
    for(int i = 0; i<(int)triSides; i++){
        for(int j = 0; j <= i; j++)
            cout << '*';
        cout << endl;
    }
}

void OrthogonalTriangle::printDetails() const{
    cout << "OrthogonalTriangle details: color=" << this->getColour() << ", side=" << triSides << endl;
    cout << "area= " << this->getArea() << ", perimeter=" << this->getPerimeter() << endl;
}

//
// Created by Romi Lustig on 12/01/2023.
//

#ifndef ASSIGNMENT3_MENU_H
#define ASSIGNMENT3_MENU_H
#include "LinkedList.h"
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "OrthogonalTriangle.h"

class Menu {
    LinkedList<Shape *> newList;
public:
    Menu(LinkedList<Shape *> newList = nullptr): newList(newList){};
    void mainMenu();
    void AddElem();
    void removeElem();
    void printInList() const;
    ~Menu(){};
};

#endif //ASSIGNMENT3_MENU_H

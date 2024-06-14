//
// Created by Romi Lustig on 12/01/2023.
//

#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::mainMenu(){
    int chosen = 0;
    do{
        cout << "=======================================\n"
             << "<1>Add element to the list\n"
             << "<2>Remove the last shape from list\n"
             << "<3>Print the last shape\n"
             << "<4>Exit\n"
             << "=======================================" << endl;
        cin >> chosen;
        cin.ignore();
        switch (chosen) {
            case(1):
                AddElem();
                break;
            case(2):
                try {
                    removeElem();
                    break;
                }
                catch(const char *){
                    cout << "Exception: list is empty!" << endl;
                    break;
                }
            case(3):
                try {
                    printInList();
                    newList.getTop()->draw();
                    break;
                }
                catch(const char *){
                    cout << "Exception: list is empty!" << endl;
                    break;
                }
                catch(float){
                    break;
                }
            case(4):
                cout << "Goodbye!" << endl;
                //exit(1);
                return;
            default:
                cout << "Invalid selection" << endl;
                break;
        }
    }
    while(chosen != 4);
}

void Menu::AddElem(){
    int shape = 0;
    try {
        cout << "Choose 1 for Square, 2 for Circle, 3 for Triangle: ";
        cin >> shape;
        cin.ignore();
    }
    catch(const char *) {
            cout << "Invalid selection" << endl;
    }
    //cout << endl;
    char * colour = new char();
    double length = 0;
    switch(shape) {
        case(1): // case of square
            do {
                try {
                    cout << "Enter square's color: ";
                    cin >> colour;
                    cin.ignore();
                    cout << "Enter square's side length: ";
                    cin >> length;
                    cin.ignore();
                    Square* newSquare = new Square(length, colour);
                    newList.insert(newSquare);
                    delete colour;
                    return;
                }
                catch(int){
                    cout << "Exception: color must be red green or blue\nplease try again" << endl;
                }
                catch(double){
                    cout << "Exception: The side must be positive\nplease try again" << endl;
                }
                catch(const char *){
                    cout << "Invalid selection" << endl;
                }
            } while(true);
        case(2):
            do {
                try {
                    cout << "Enter circle's color: ";
                    cin >> colour;
                    cin.ignore();
                    cout << "Enter circle's radius: ";
                    cin >> length;
                    cin.ignore();
                    Circle * newCircle = new Circle(length, colour);
                    newList.insert(newCircle);
                    return;
                }
                catch(int){
                    cout << "Exception: color must be red green or blue\nplease try again" << endl;
                }
                catch(double){
                    cout << "Exception: The side must be positive\n please try again" << endl;
                }
                catch(char *){
                    cout << "Invalid selection" << endl;
                }
            } while(true);
        case(3):
            do {
                try {
                    cout << "Enter Triangle's color: ";
                    cin >> colour;
                    cin.ignore();
                    cout << "Enter Triangle's side: ";
                    cin >> length;
                    cin.ignore();
                    OrthogonalTriangle * newTriangle = new OrthogonalTriangle(length, colour);
                    newList.insert(newTriangle);
                    return;
                }
                catch(int){
                    cout << "Exception: color must be red green or blue\nplease try again" << endl;
                }
                catch(double){
                    cout << "Exception: The side must be positive\n please try again" << endl;
                }
                catch(char *){
                    cout << "Invalid selection" << endl;
                }
            } while(true);
        default:
            cout << "Invalid selection" << endl;
    }
}

void Menu::removeElem(){
    try{
        newList.deleteNode();
    }
    catch(const char *){
        cout << "Exception: list is empty!\nplease try again" << endl;
    }
}

void Menu::printInList() const{
    if(newList.getHead() == nullptr) throw "Invalid";
    else (newList.getTop())->printDetails();
}

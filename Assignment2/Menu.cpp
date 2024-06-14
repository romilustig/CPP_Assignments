/* Assignment C++: 2
   Author Romi Lustig, ID: 211542089
   */

#include "Menu.h"
using namespace std;

Menu::Menu(){};

void Menu::mainMenu() {
    int number = 0; // chosen number
    do{
        cout << "(1) Set Menu\n" << "(2) Integer Queue Menu\n" << "(3) Exit" << endl;
        cin >> number;
        switch (number) { // cases of number chosen
            case(1):
                setMenu();
                break;
            case 2:
                queueMenu();
                break;
            case 3:
                cout << "Goodbye!" << endl;
                exit(0);
            default:
                cout << "Invalid selection." << endl;
                break;
        }
    } while(number != 3);
}

void Menu::setMenu() {
    Set newSet1, newSet2; // local sets (will be deleted after going back to menu)
    int number = 0; // chosen number in menu
    int setNum; // chosen number in each set
    do {
        cout << "*** Welcome to set Menu ***\n"
             << "To select an item, enter\n"
             << "1 Show set 1\n"
             << "2 Show set 2\n"
             << "3 add element to set 1\n"
             << "4 add element to set 2\n"
             << "5 Show set1 U set 2 (union)\n"
             << "6 to exit" << endl;
        cin >> number;
        switch (number) { // list of all cases
            case (1):
                if (newSet1.getcurrentSize() != 0)
                    cout << newSet1;
                else cout << "Set 1 is empty" << endl;
                break;
            case (2):
                if (newSet2.getcurrentSize() != 0)
                    cout << newSet2;
                else cout << "Set 2 is empty" << endl;
                break;
            case (3):
                cout << "Give a number: ";
                cin >> setNum;
                newSet1 += setNum; // when choosing a number: add to set
                break;
            case (4):
                cout << "Give a number: ";
                cin >> setNum;
                newSet2 += setNum; // when choosing a number: add to set
                break;
            case (5):
                if (newSet1.getcurrentSize() == 0 && newSet2.getcurrentSize() == 0)
                    cout << "The union is empty" << endl;
                else{
                    Set newSetU = newSet1 + newSet2; // union of both sets: returns new set, newSetU copies it
                    cout << newSetU;
                }
                break;
            case (6):
                return;
            default:
                cout << "Invalid selection." << endl;
                break;
        }
    } while (number != 6);
}


void Menu::queueMenu() {
    int size, choice=0; // size of queue, choice in menu
    int queueNum; // number chosen to add to queue
    cout << "Enter the size of the queue: ";
    cin >> size;
    if(size <=0) size = 0;
    myQueue newQueue(size); // local myQueue (will be deleted going back to menu)
    do{
        cout << "*** Welcome to Queue Menu ***\n"
             << "To select an item, enter\n"
             << "1 Show Queue\n"
             << "2 Insert new element\n"
             << "3 Remove element\n"
             << "4 Check the first element\n"
             << "5 to exit" << endl;
        cin >> choice;
        switch (choice){
            case(1):
                if (newQueue.isEmpty())
                    cout << "The queue is empty" << endl;
                else cout << newQueue;
                break;
            case(2):
                cout << "insert new element: ";
                cin >> queueNum;
                if(newQueue.enQueue(queueNum))
                    cout << newQueue;
                break;
            case(3):
                if(newQueue.getSize() == 0)
                    cout << "Queue is empty" << endl;
                else {
                    newQueue.deQueue();
                    cout << newQueue;
                }
            case(4):
                if(newQueue.peek() == -1)
                    cout << "Queue is empty" << endl; //
                else cout << newQueue.peek();
                break;
            case(5):
                return;
            default:
                cout << "Invalid selection." << endl;
                break;
        }
    } while(choice!=0);
}

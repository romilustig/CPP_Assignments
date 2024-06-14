/* Assignment C++: 3
   Author: Israel Israeli, ID: 01234567
*/

#ifndef ASSIGNMENT3_LINKEDLIST_H
#define ASSIGNMENT3_LINKEDLIST_H

#endif //ASSIGNMENT3_LINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

template <typename T> class LinkedList {
    Node<T> *head;
public:
    LinkedList(Node<T> * head = nullptr): head(head){};// default constructor for list
    ~LinkedList(){
        while(head != nullptr){
            deleteNode();
            //cout << "LL Dtor" << endl;
        }
    }

    void insert(const T &t) {
        Node<T> * temp = new Node<T>(t);
        temp->setNodeNext(head);
        head = temp;
    }

    T deleteNode() {
        if (head == nullptr) throw "Invalid"; // THROWS EXCEPTION
        else {
            T tempData = head->getNodeData();
            Node<T> * temp = head; // pointer
            head = temp->getNodeNext();
            delete temp;
            return tempData; // returns value of what was deleted
        }
    }

    T deleteNode(const T &data) {
        Node<T> * foundT= searchAndRet(data); // returns pointer to node who's next has data
        if (foundT == head) return deleteNode(); // deleting normally (head)
        if (foundT != nullptr) { // searches if data is in list
            Node<T> *inList = foundT->Next; // pointer to the wanted data (to be deleted)
            T dataDeleted = inList->getNodeData(); // copy constructor
            foundT->setNodeNext(inList->getNodeNext());
            delete inList;
            return dataDeleted;
        }
        throw "Invalid"; // THROWS EXCEPTION
    }
    Node<T> * searchAndRet(const T &data) const {
        Node<T> * temp = head;
        if (temp->getNodeData() == data) return head;
        while (temp->getNodeNext() != nullptr) {
            if ((temp->getNodeNext())->getNodeData() != data) temp = temp->getNodeNext();
            else return temp; // returns the node which points to data
        }
        return nullptr;
    }

    bool search(const T &data) const {
        if(searchAndRet(data)!= nullptr) return true;
        else return false;
    }

    const T& getTop() const {
        return head->getNodeData();
    }

    Node<T> * getHead() const{
        return head;
    }

    friend ostream & operator<<(ostream & out, const LinkedList<T> &lst){ // to print << a few times
        Node<T> * temp = lst.head;
        while(temp != nullptr){
            out << temp->getNodeData();
            temp = temp->getNodeNext();
        }
        out << endl;
        return out;
    }
};
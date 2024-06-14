/* Assignment C++: 3
   Author: Israel Israeli, ID: 01234567
*/

#ifndef ASSIGNMENT3_NODE_H
#define ASSIGNMENT3_NODE_H

#endif //ASSIGNMENT3_NODE_H

#include <iostream>
using namespace std;

template <typename T> class Node{
    T data;
    Node<T>* Next;
public:
    Node(T data = NULL): data(data), Next(nullptr){};
    Node & operator=(const Node & other){
        if(this == &other);
        else{
            data = other.data; Next = other.Next;
        }
        return *this;
    }
    Node(const Node & other){
        *this = other;
    } // operator =
    ~Node()= default;

    void setNodeNext(Node<T>* newNext){
        Next = newNext;
    }

    Node<T>* getNodeNext() {
        return Next;
    }

    T& getNodeData(){
        return data;
    }
    friend ostream & operator<<(ostream & out, const Node<T> &node){
        out << node.data;
        return out;
    }
};
/* Assignment C++: 2
   Author Romi Lustig, ID: 211542089
   */

#include "myQueue.h"
#include <vector>
using namespace std;

myQueue::myQueue(const myQueue &queue): maxQ(queue.maxQ){ // copy constructor
    this->newVec = queue.newVec;
}

myQueue::~myQueue() {
    newVec.clear(); // clear all numbers from vector
    newVec.shrink_to_fit(); // removes unused capacity
}

bool myQueue::enQueue(int val){
    if(newVec.size() < maxQ) { // check if vector is big enough to fit another value
        newVec.push_back(val);
        return true;
    }
    else{
        cout << "Queue is full" << endl; // check if needed
        return false;
    }
}

bool myQueue::deQueue(){
    if(this->isEmpty()) return false; // there's no elements to pop
    else{
        newVec.erase(newVec.begin()); // builtin function in vector<int>
        return true;
    }
}

bool myQueue::isEmpty() const{
    if(newVec.empty()) return true; // builtin function in vector<int>
    else return false;
}

int myQueue::peek() const{
    if(newVec.empty()) return -1;
    else return newVec[0]; // brings back reference to first number in vector
}

int myQueue::getSize() const { // no need to change object
    return (int)newVec.size(); // builtin function
}

int myQueue::operator[] (int i) const{ // not to change object
    return newVec[i];
}

ostream & operator<<(ostream & out, const myQueue &queue){ // print a few << in one line
    for(int i = queue.getSize()-1; 0<i; i--) // print all elements
        out << queue[i] << " <- ";
    out << queue[0] << endl;

    return out;
}

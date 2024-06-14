/* Assignment C++: 2
   Author Romi Lustig, ID: 211542089
   */

#ifndef ASSIGNMENT2_MYQUEUE_H
#define ASSIGNMENT2_MYQUEUE_H
#include <vector>
#include <iostream>
using namespace std;

class myQueue {
    vector<int> newVec;
    const int maxQ;
public:
    myQueue(int maxQ = 0): maxQ(maxQ), newVec(){};
    myQueue(const myQueue &queue);
    ~myQueue();
    bool enQueue(int val);
    bool deQueue();
    bool isEmpty() const;
    int peek() const;
    int getSize() const;
    int operator[] (int i) const;
    friend ostream & operator<<(ostream & out, const myQueue &queue);
};

#endif //ASSIGNMENT2_MYQUEUE_H

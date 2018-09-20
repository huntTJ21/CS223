#ifndef STACKANDQUEUE_QUEUEUSINGSTACK_H_
#define STACKANDQUEUE_QUEUEUSINGSTACK_H_

#include <iostream>
#include <climits>
#include "Stack.h"

using namespace std;

class QueueUsingStack {

    Stack *mainStack;
    int maxQueueSize;

public:
    QueueUsingStack(int maxQueueSize) {
        this->maxQueueSize = maxQueueSize;
        mainStack = new Stack(maxQueueSize);
    }

    ~QueueUsingStack() {
        delete mainStack;
    }

    void enqueue(int val) { 
        if(mainStack->getSize() == 0){
            mainStack->push(val);
        } else {
            Stack *tempStack;
            tempStack = new Stack(maxQueueSize);
            while(mainStack->getSize() > 0){
                tempStack->push(mainStack->pop());
            }
            mainStack->push(val);
            while(tempStack->getSize() > 0){
                mainStack->push(tempStack->pop());
            }
            delete tempStack;
        }
    }

    int dequeue() {
        if (0 == getSize()) {
            cout << "Cannot dequeue! Queue is empty.";
            return INT_MIN;
        }
        else
            return mainStack->pop();
    }

    int getSize() {
        return mainStack->getSize();
    }

    void print() {
        if (getSize() == 0)
            cout << "[]";
        else {
            Stack tempStack(mainStack->getSize());
            while (mainStack->getSize() > 0)
                tempStack.push(mainStack->pop());
            tempStack.print();
            while (tempStack.getSize() > 0)
                mainStack->push(tempStack.pop());
        }
    }
};
#endif /* STACKANDQUEUE_QUEUEUSINGSTACK_H_ */
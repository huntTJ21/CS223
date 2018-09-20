#ifndef STACKANDQUEUE_STACK_H_
#define STACKANDQUEUE_STACK_H_

#include <iostream>
#include <climits>
using namespace std;

class Stack {

private:
    int maxStackSize, topOfStack;
    int *stack;

public:

    Stack(int maxStackSize) {
        if (maxStackSize <= 0)
            cout << "Stack size should be a positive integer.";
        else {
            this->maxStackSize = maxStackSize;
            topOfStack = -1;
            stack = new int[maxStackSize];
        }
    }

    ~Stack() {
        delete stack;
    }

    void push(int val) { 
        if(topOfStack == maxStackSize){
            cout << "Stack Full";
        } else {
            topOfStack++;
            stack[topOfStack] = val;
        }
    }

    int pop() { 
        if(topOfStack != -1){
            int val = stack[topOfStack];
            topOfStack--;
            return val;
        } else {
            return -999;
        }
    }

    int getSize() {
        return topOfStack + 1;
    }

    void print() {
        if (getSize() == 0) {
            cout << "[]";
        } else {
            cout << "[";
            for (int i = 0; i < getSize() - 1; i++) {
                cout << stack[i] << ", ";
            }
            cout << stack[getSize() - 1] << "]";
        }
    }
};

#endif /* STACKANDQUEUE_STACK_H_ */
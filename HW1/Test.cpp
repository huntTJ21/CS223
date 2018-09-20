#include "QueueUsingStack.h"
#include "Queue.h"

void testFunctionality() {

    QueueUsingStack qViaStack(5);
    Queue queue(5);
    cout << "**** Enqueue Test ****";
    cout << endl;
    for (int i = 1; i <= 3; i++) {
        qViaStack.enqueue(i);
        queue.enqueue(i);
        cout << endl << "Stack implementation: ";
        qViaStack.print();
        cout << endl << "Standard implementation: ";
        queue.print();
        cout << endl;
    }
    cout << endl << "**** Dequeue Test ****";
    cout << endl;
    for (int i = 1; i <= 2; i++) {
        cout << endl << "Stack implementation: (Dequeued "
                << qViaStack.dequeue() << ") ";
        qViaStack.print();
        cout << endl << "Standard implementation: (Dequeued " << queue.dequeue()
                << ") ";
        queue.print();
        cout << endl;
    }
    cout << endl << "**** Enqueue Test ****";
    cout << endl;
    for (int i = 1; i <= 2; i++) {
        qViaStack.enqueue(i);
        queue.enqueue(i);
        cout << endl << "Stack implementation: ";
        qViaStack.print();
        cout << endl << "Standard implementation: ";
        queue.print();
        cout << endl;
    }
    cout << endl << "**** Dequeue Test ****";
    cout << endl;
    for (int i = 1; i <= 3; i++) {
        cout << endl << "Stack implementation: (Dequeued "
                << qViaStack.dequeue() << ") ";
        qViaStack.print();
        cout << endl << "Standard implementation: (Dequeued " << queue.dequeue()
                << ") ";
        queue.print();
        cout << endl;
    }
}

void testTime() {

    cout << endl << "**** Time Test ****" << endl << endl;
    int maxSize = 50000;
    QueueUsingStack qViaStack(maxSize);

    long startTime, endTime;

    startTime = clock();
    for (int i = 0; i < maxSize; i++) {
        qViaStack.enqueue(i);
    }
    endTime = clock();

    cout << "Time taken to grow an empty queue to size " << maxSize
            << ", when using a stack implementation: "
            << (endTime - startTime) * 1000 / CLOCKS_PER_SEC << endl;

    maxSize = 5000000;
    Queue queue(maxSize);

    startTime = clock();
    for (int i = 0; i < maxSize; i++) {
        queue.enqueue(i);
    }
    endTime = clock();
    cout << "Time taken to grow an empty queue to size " << maxSize
            << ", when using an array implementation:  "
            << (endTime - startTime) * 1000 / CLOCKS_PER_SEC << endl;
}

int main() {
    testFunctionality();
    testTime();
    return 0;
}

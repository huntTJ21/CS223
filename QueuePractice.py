class Queue:
    MAX_SIZE = 5
    queueSize = 0
    front = 0
    rear = 0
    queueArray = [None] * MAX_SIZE

    def enqueue(self, val):
        if(self.queueSize == self.MAX_SIZE):
            print("Queue is full")
        else:
            self.queueArray[self.rear] = val
            self.rear += 1
            self.queueSize += 1
            if(self.rear == self.MAX_SIZE):
                self.rear = 0

    def dequeue(self):
        if(self.queueSize == 0):
            print("Queue is empty")
        else:
            val = self.queueArray[self.front]
            self.front += 1
            self.queueSize -= 1
            if(self.front == self.MAX_SIZE):
                self.front = 0
            return val

    def peek(self):
        if(self.queueSize == 0):
            print("Queue is empty")
        else:
            return self.queueArray[self.front]

    def size(self):
        return self.queueSize

    
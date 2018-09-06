class Stack:
    def __init__(self, MAX_STACKSIZE=5):
        self.MAX_STACKSIZE = MAX_STACKSIZE
        self.topOfStack = -1
        self.stackArray = [None] * MAX_STACKSIZE
    def push(self, val):
        if(self.topOfStack == self.MAX_STACKSIZE -1):
            print("Stack Full")
        else:
            self.topOfStack = self.topOfStack+1
            self.stackArray[self.topOfStack] = val
    def pop(self):
        if(self.topOfStack != -1):
            val = self.stackArray[self.topOfStack]
            del self.stackArray[self.topOfStack]
            self.topOfStack = self.topOfStack-1
            return val
        else:
            return "Stack Empty"
    def peek(self):
        if(self.topOfStack != -1):
            return self.stackArray[self.topOfStack]
        else:
            return "Stack Empty"
    def getSize(self):
        return self.topOfStack+1

testStack = Stack()
testStack.push(5)
testStack.push(10)
testStack.push(15)
testStack.push(20)
testStack.push(25)
testStack.push(30)
print(testStack.pop())
print(testStack.pop())
print(testStack.pop())
print(testStack.pop())
print(testStack.pop())
print(testStack.pop())

# https://leetcode.com/problems/design-circular-deque/
class Node(object):
    def __init__(self, value, next=None, previous=None):
        self.value = value
        self.next = next
        self.previous = previous

class MyCircularDeque(object):
    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        """
        self.capacity = k
        self.size = 0
        self.front = None
        self.rear = None

    def insertFront(self, value: int) -> bool:
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        """
        if self.isFull():
            return False
        node = Node(value, self.front)
        if self.front:
            self.front.previous = node
        self.front = node
        
        if not self.rear:
            self.rear = self.front
        
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        """
        if self.isFull():
            return False
        node = Node(value, None, self.rear)
        if self.rear:
            self.rear.next = node
        self.rear = node
        
        if not self.front:
            self.front = self.rear
        
        self.size += 1
        return True

    def deleteFront(self) -> bool:
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        
        if self.front.next:
            self.front.next.previous = None
        self.front = self.front.next
        if not self.front:
            self.rear = None
        
        self.size -= 1
        return True

    def deleteLast(self) -> bool:
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        
        if self.rear.previous:
            self.rear.previous.next = None
        self.rear = self.rear.previous
        if not self.rear:
            self.front = None
        
        self.size -= 1
        return True

    def getFront(self) -> int:
        """
        Get the front item from the deque.
        """
        if self.front:
            return self.front.value
        return -1

    def getRear(self) -> int:
        """
        Get the last item from the deque.
        """
        if self.rear:
            return self.rear.value
        return -1

    def isEmpty(self) -> bool:
        """
        Checks whether the circular deque is empty or not.
        """
        return self.size == 0

    def isFull(self) -> bool:
        """
        Checks whether the circular deque is full or not.
        """
        return self.size == self.capacity


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()

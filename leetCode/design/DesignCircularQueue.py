# https://leetcode.com/problems/design-circular-queue/

class Node(object):
    def __init__(self, value, next=None, previous=None):
        self.next = next
        self.previous = previous
        self.value = value

class MyCircularQueue:
    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        self.capacity = k
        self.head = None
        self.tail = None
        self.size = 0

    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        if self.size == self.capacity:
            return False
        
        node = Node(value)
        if not self.head:
            self.head = node
        
        if self.tail:
            self.tail.next = node
            node.previous = self.tail
        self.tail = node
        
        self.size += 1
        return True

    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        self.size -= 1
        self.head = self.head.next
        if self.size == 0:
            self.head = None
            self.tail = None
        
        return True

    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        if self.head:
            return self.head.value
        return -1

    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        if self.tail:
            return self.tail.value
        return -1

    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        return self.head is None

    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        return self.size == self.capacity


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()

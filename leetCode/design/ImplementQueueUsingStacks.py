# https://leetcode.com/problems/implement-queue-using-stacks/
class MyQueue:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = [[], []]
        self.can_peek = False

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        if self.can_peek:
            while self.data[1]:
                self.data[0].append(self.data[1].pop())
        self.data[0].append(x)
        self.can_peek = False        

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        resp = self.peek()
        self.data[1].pop()
        return resp

    def peek(self) -> int:
        """
        Get the front element.
        """
        while self.data[0]:
            self.data[1].append(self.data[0].pop())
        self.can_peek = True
        return self.data[1][-1]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        # print(f"{self.data[0]}, {self.data[1]}")
        return (not self.data[0]) and (not self.data[1])


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()

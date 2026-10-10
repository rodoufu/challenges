# https://leetcode.com/problems/min-stack/
class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, value: int) -> None:
        min_so_far = value
        if len(self.min_stack) > 0:
            min_so_far = min(min_so_far, self.min_stack[-1])
        self.stack.append(value)
        self.min_stack.append(min_so_far)

    def pop(self) -> None:
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

# https://leetcode.com/problems/design-an-ordered-stream/
class OrderedStream:
    def __init__(self, n: int):
        self.values = [None] * n
        self.n = n
        self.ptr = 0

    def insert(self, id: int, value: str) -> List[str]:
        self.values[id - 1] = value
        resp = []
        # print(f"v: {self.values}")
        for i in range(self.ptr, self.n):
            if self.values[i]:
                resp.append(self.values[i])
            else:
                break
            self.ptr = i + 1
        return resp

# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(id,value)

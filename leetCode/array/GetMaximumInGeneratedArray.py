# https://leetcode.com/problems/get-maximum-in-generated-array/
class Solution:
    def __init__(self):
        n = 101
        self.nums = list(range(n))
        for i in range(2, n):
            if i % 2 == 0:
                self.nums[i] = self.nums[i // 2]
            else:
                self.nums[i] = self.nums[i // 2] + self.nums[i // 2 + 1]
            
    def getMaximumGenerated(self, n: int) -> int:
        # for i in range(101):
        #     print(f"{i}: {self.nums[i]}, ", end='')
        #     if (i + 1) % 10 == 0:
        #         print()
        return max(self.nums[:(n+1)])

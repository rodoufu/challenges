# https://leetcode.com/problems/number-of-good-pairs/
class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        counter = {}
        for num in nums:
            counter[num] = counter.get(num, 0) + 1
        
        resp = 0
        for i, count in counter.items():
            # print(f"{i}-{count}-{resp}")
            if count > 1:
                resp += count * (count - 1) // 2
        return resp

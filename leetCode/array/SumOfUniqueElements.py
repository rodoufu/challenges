# https://leetcode.com/problems/sum-of-unique-elements/
class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        unique = {}
        for x in nums:
            unique[x] = unique.get(x, 0) + 1
        
        resp = 0
        for num, count in unique.items():
            if count == 1:
                resp += num
        return resp

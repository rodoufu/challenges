# https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/
class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        if num % 3 != 0:
            return []
        x = num // 3

        return [x - 1, x, x + 1]

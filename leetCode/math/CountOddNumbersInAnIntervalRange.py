# https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        difference = high - low
        return (high - low) // 2 + (1 if low % 2 == 1 or high % 2 == 1 else 0)

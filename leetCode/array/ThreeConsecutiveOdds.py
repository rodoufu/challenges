# https://leetcode.com/problems/three-consecutive-odds/

class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        odds = 0
        for x in arr:
            if x % 2 == 0:
                odds = 0
            else:
                odds += 1
                if odds == 3:
                    return True
        return False

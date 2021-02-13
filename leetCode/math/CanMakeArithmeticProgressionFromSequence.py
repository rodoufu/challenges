# https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        min_a = min(arr)
        max_a = max(arr)
        set_a = set(arr)
        r = (max_a - min_a) // (len(arr) - 1)
        
        for a in arr:
            if min_a not in set_a:
                return False
            min_a += r
        
        return True

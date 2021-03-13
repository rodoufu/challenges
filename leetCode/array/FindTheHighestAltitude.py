# https://leetcode.com/problems/find-the-highest-altitude/
class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        altitude = 0
        max_so_far = 0
        for x in gain:
            altitude += x
            max_so_far = max(max_so_far, altitude)
        
        return max_so_far

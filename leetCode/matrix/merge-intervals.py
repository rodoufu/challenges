# https://leetcode.com/problems/merge-intervals/
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda x: x[0])

        merged = [intervals[0]]

        for i in range(1, len(intervals)):
            if intervals[i][0] > merged[-1][1]:
                merged.append(intervals[i])
            merged[-1][1] = max(merged[-1][1], intervals[i][1])

        return merged 

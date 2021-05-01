# https://leetcode.com/problems/merge-intervals/
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda x: x[0], reverse=True)
        tail_list = []
        while len(intervals) > 1:
            first = intervals.pop()
            second = intervals.pop()
            if first[1] >= second[0]:
                intervals.append([first[0], max(first[1], second[1])])
            else:
                intervals.append(second)
                tail_list.append(first)
        return tail_list + intervals

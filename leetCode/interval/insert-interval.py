# https://leetcode.com/problems/insert-interval
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if not intervals:
            return [newInterval]

        intervals.append(newInterval)
        # print(f"intervals: {intervals}")
        for i in range(len(intervals) - 1, 0, -1):
            if intervals[i][0] < intervals[i - 1][0]:
                # print("replace")
                intervals[i], intervals[i - 1] = intervals[i - 1], intervals[i]
            else:
                # print("stop")
                break
        # print(f"intervals: {intervals}")

        resp = [intervals[0]]
        for i in range(1, len(intervals)):
            if intervals[i][0] <= resp[-1][1]:
                resp[-1][1] = max(resp[-1][1], intervals[i][1])
            else:
                resp.append(intervals[i])

        return resp

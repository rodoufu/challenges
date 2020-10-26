# https://leetcode.com/problems/summary-ranges/
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        resp = []
        summary = []
        for x in nums:
            if summary:
                if x == summary[1] + 1:
                    summary[1] = x
                elif summary[0] != summary[1]:
                    resp.append(f"{summary[0]}->{summary[1]}")
                    summary = [x, x]
                else:
                    resp.append(str(summary[0]))
                    summary = [x, x]
            else:
                summary = [x, x]
        if summary:
            if summary[0] != summary[1]:
                resp.append(f"{summary[0]}->{summary[1]}")
            else:
                resp.append(str(summary[0]))
        return resp

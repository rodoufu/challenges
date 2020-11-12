# https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
class Solution:
    def maxDepth(self, s: str) -> int:
        t_count = 0
        resp = 0
        for x in s:
            if x == '(':
                t_count += 1
            if x == ')':
                t_count -= 1
            resp = max(resp, t_count)
            if t_count < 0:
                return -1
        return resp

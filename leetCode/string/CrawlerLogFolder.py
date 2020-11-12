# https://leetcode.com/problems/crawler-log-folder/
class Solution:
    def minOperations(self, logs: List[str]) -> int:
        level = 0
        for op in logs:
            if op == "../":
                level = max(0, level - 1)
            elif op == './':
                continue
            else:
                level += 1
        return level

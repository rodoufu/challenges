# https://leetcode.com/problems/backspace-string-compare/
class Solution:
    def backspace(self, S: str) -> str:
        resp = []
        for x in S:
            if x == '#':
                if len(resp) > 0:
                    resp.pop()
            else:
                resp.append(x)
        return ''.join(resp)

    def backspaceCompare(self, S: str, T: str) -> bool:
        return self.backspace(S) == self.backspace(T)

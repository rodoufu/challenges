# https://leetcode.com/problems/reverse-words-in-a-string-iii/
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.split(' ')
        resp = []
        for x in s:
            lenx = len(x)
            for i in range(lenx - 1, -1, -1):
                resp.append(x[i])
            resp.append(' ')
        resp.pop()
        return ''.join(resp)

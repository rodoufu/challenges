# https://leetcode.com/problems/shuffle-string/
class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        resp = [None] * len(s)
        for i in range(len(s)):
            resp[indices[i]] = s[i]
            
        return ''.join(resp)

# https://leetcode.com/problems/largest-substring-between-two-equal-characters/
class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        resp = -1
        letter_pos = {}
        
        for i in range(len(s)):
            x = s[i]
            letter_pos[x] = letter_pos.get(x, []) + [i]
            
        for positions in letter_pos.values():
            resp = max(resp, max(positions) - min(positions) - 1)
        
        return resp

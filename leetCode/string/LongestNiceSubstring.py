# https://leetcode.com/problems/longest-nice-substring/
class Solution:
    def invert_case(self, a: str) -> str:
        if a == a.lower():
            return a.upper()
        else:
            return a.lower()
    
    def is_nice(self, s: str) -> bool:
        letters = set()
        for x in s:
            letters.add(x)
            
        for x in letters:
            if self.invert_case(x) not in letters:
                return False
        
        return True

    def longestNiceSubstring(self, s: str) -> str:
        lens = len(s)
        
        resp = ''
        resps = 0
        for i in range(lens - 1):
            for j in range(i + 1, lens + 1):
                if self.is_nice(s[i:j]) and j - i > resps:
                    resps = j - i
                    resp = s[i:j]

        return resp

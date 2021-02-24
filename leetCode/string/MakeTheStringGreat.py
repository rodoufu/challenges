# https://leetcode.com/problems/make-the-string-great/
class Solution:
    def makeGoodAux(self, s: str) -> str:
        if s == "":
            return ""
        resp = []
        len_s = len(s)
        
        i = 0
        while i < len_s:
            if i == len_s - 1:
                resp.append(s[i])
                i += 1
            elif s[i].upper() == s[i + 1].upper() and s[i] != s[i + 1]:
                i += 2
            else:
                resp.append(s[i])
                i += 1
        
        return ''.join(resp)
    
    def makeGood(self, s: str) -> str:
        resp = self.makeGoodAux(s)
        while resp != s:
            s = resp
            resp = self.makeGoodAux(s)
        
        return resp

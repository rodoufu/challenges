# https://leetcode.com/problems/merge-strings-alternately/
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        resp = []
        len1 = len(word1)
        len2 = len(word2)
        
        for i in range(min(len1, len2)):
            resp.append(word1[i])
            resp.append(word2[i])
        
        for i in range(len1, len2):
            resp.append(word2[i])
            
        for i in range(len2, len1):
            resp.append(word1[i])

        return ''.join(resp)

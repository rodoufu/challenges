# https://leetcode.com/problems/valid-anagram/
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            
        count_leters_s = {}
        count_leters_t = {}

        for l in s:
            count_leters_s[l] = count_leters_s.get(l, 0) + 1

        for l in t:
            count_leters_t[l] = count_leters_t.get(l, 0) + 1
        
        return count_leters_s == count_leters_t
      

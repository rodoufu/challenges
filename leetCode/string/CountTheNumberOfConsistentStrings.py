# https://leetcode.com/problems/count-the-number-of-consistent-strings/
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        word_c = 0
        check = set(list(allowed))
        for word in words:
            is_allowed = True
            for x in word:
                is_allowed = x in check
                if not is_allowed:
                    break
            if is_allowed:
                word_c += 1
        return word_c

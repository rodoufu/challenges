# https://leetcode.com/problems/determine-if-string-halves-are-alike/
class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        lens = len(s)
        n_vowels = 0
        vowels = set(['a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'])
        for i in range(lens):
            if s[i] in vowels:
                n_vowels += 1 if i < lens / 2 else -1
        
        # print(f"vowels: {n_vowels}")
        return n_vowels == 0

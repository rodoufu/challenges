# https://leetcode.com/problems/reverse-words-in-a-string/
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join([x for x in s.split(" ") if len(x.strip()) > 0][::-1])

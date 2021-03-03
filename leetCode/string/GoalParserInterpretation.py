# https://leetcode.com/problems/goal-parser-interpretation/
class Solution:
    def interpret(self, command: str) -> str:
        resp = []
        word = ''
        
        for letter in command:
            word += letter
            if word == "G":
                resp.append("G")
                word = ''
            elif word == "()":
                resp.append('o')
                word = ''
            elif word == "(al)":
                resp.append('al')
                word = ''
        
        return ''.join(resp)

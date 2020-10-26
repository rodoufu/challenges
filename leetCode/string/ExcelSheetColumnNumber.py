# https://leetcode.com/problems/excel-sheet-column-number/
class Solution:
    def titleToNumber(self, s: str) -> int:
        resp = 0
        multi = 1
        for x in s[::-1]:
            resp += multi * ((ord(x) - ord('A')) + 1)
            multi *= 26
            # print(f"x: {x}, resp: {resp}, multi: {multi}")
        return resp

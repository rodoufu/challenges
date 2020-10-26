# https://leetcode.com/problems/excel-sheet-column-title/
class Solution:
    def convertToTitle(self, n: int) -> str:
        resp = []
        if n < 0:
            return ""
        while n:
            n -= 1
            resp.append(chr(ord('A') + (n % 26)))
            n = n // 26
            # print(f"n: {n}, resp: {resp}")
        return "".join(resp[::-1])

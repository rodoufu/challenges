# https://leetcode.com/problems/xor-operation-in-an-array
class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        resp = start
        value = 2
        for _ in range(1, n):
            resp ^= start + value
            value += 2
        return resp

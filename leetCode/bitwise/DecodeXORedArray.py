# https://leetcode.com/problems/decode-xored-array/
class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        resp = [first]
        for x in encoded:
            resp.append(resp[-1] ^ x)
        return resp

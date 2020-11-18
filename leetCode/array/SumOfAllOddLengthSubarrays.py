# https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
class Solution:
    def pick_seq(self, arr: List[int], n: int) -> Iterable[int]:
        lena = len(arr)
        for i in range(lena - n + 1):
            for j in range(i, min(i + n, lena)):
                yield arr[j]

    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        resp = 0
        for v in range(1, len(arr) + 1, 2):
            for it in self.pick_seq(arr, v):
                resp += it
                # print(f"{it}", end=" ")
            # print("")
        return resp

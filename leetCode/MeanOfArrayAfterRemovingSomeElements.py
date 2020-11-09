# https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr = sorted(arr)
        len_a = len(arr)
        cut = len_a // 20
        return sum(arr[cut:-cut]) / (len_a * 0.9)

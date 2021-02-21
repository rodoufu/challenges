# https://leetcode.com/problems/count-good-triplets/
class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        # arr = sorted(arr)
        len_a = len(arr)
        count = 0
        for i in range(len_a):
            for j in range(i + 1, len_a):
                if abs(arr[i] - arr[j]) > a:
                    continue
                for k in range(j + 1, len_a):
                    if abs(arr[k] - arr[j]) > b:
                        continue
                    if abs(arr[i] - arr[k]) > c:
                        continue
                    count += 1
        return count

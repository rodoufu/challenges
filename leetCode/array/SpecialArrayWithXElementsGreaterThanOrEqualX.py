# https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums = sorted(nums)
        len_n = len(nums)
        for i in range(len_n):
            if nums[i] >= len_n - i and (i == 0 or nums[i - 1] < len_n - i):
                return len_n - i
        return -1

# https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
class Solution:
    def is_sorted(self, nums: List[int]) -> bool:
        # print(f"is_sorted({nums})")
        lenn = len(nums)
        for i in range(lenn - 1):
            if nums[i + 1] < nums[i]:
                return False
        return True
        
    def check(self, nums: List[int]) -> bool:
        break_point = -1
        lenn = len(nums)
        for i in range(lenn - 1):
            if nums[i + 1] < nums[i]:
                if break_point >= 0:
                    return False
                else:
                    break_point = i
        # print(f"bp: {break_point}")
        return break_point == -1 or self.is_sorted(nums[break_point + 1:] + nums[:break_point + 1])

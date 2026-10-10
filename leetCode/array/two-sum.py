# https://leetcode.com/problems/two-sum/
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_index = {}
        for i in range(len(nums)):
            num_index[nums[i]] = i
        
        for i in range(len(nums)):
            num = nums[i]
            other = target - num
            other_index = num_index.get(other)
            if other_index and other_index != i:
                return [i, other_index]
        
        return [] 

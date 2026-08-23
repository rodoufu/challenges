# https://leetcode.com/problems/product-of-array-except-self/
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [1] * (len(nums) + 2)
        sufix = [1] * (len(nums) + 2)

        for i in range(len(nums)):
            prefix[i] = prefix[i - 1] * nums[i]

        for i in range(len(nums) - 1, 0, -1):
            sufix[i] = sufix[i + 1] * nums[i]
        
        # print(f"prefix: {prefix}")
        # print(f"sufix:  {sufix}")
        
        return [prefix[i - 1] * sufix[i + 1] for i in range(len(nums))]

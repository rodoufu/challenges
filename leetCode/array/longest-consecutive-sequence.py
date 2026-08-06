# https://leetcode.com/problems/longest-consecutive-sequence/
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        numbers = set() 
        min_num = min(nums)
        max_num = max(nums)

        for x in nums:
            numbers.add(x)
        
        while len(nums) > 1 and (min_num + 1) not in numbers:
            numbers.discard(min_num)
            if len(numbers) == 0:
                return 1
            min_num = min(numbers)
            
        while len(nums) > 1 and (max_num - 1) not in numbers:
            numbers.discard(max_num)
            if len(numbers) == 0:
                return 1
            max_num = max(numbers)
        
        last = min_num
        count = 1
        max_count = 1

        # print(f"min_num: {min_num}, max_num: {max_num}")
        for x in range(min_num + 1, max_num + 1):
            # print(f"x: {x}, numbers[x]: {numbers[x]}, count: {count}, max_count: {max_count}")
            if x in numbers:
                if x == last + 1:
                    count += 1
                else:
                    count = 1

                last = x
            elif count > max_count:
                max_count = count
                count = 0

        if count > max_count:
            max_count = count
            count = 0

        return max_count

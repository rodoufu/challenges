# https://leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        num_count = {}
        for x in nums:
            num_count[x] = num_count.get(x, 0) + 1
        count_num = {}
        for x, c in num_count.items():
            count_num[c] = count_num.get(c, set([x]))
            count_num[c].add(x)
        
        index = 0
        num_count = None
        for c in sorted(count_num.keys()):
            x_vec = count_num[c]
            # print(f"{c}, {x_vec}")
            for x in sorted(x_vec, reverse=True):
                for _ in range(c):
                    nums[index] = x
                    index += 1
        
        return nums

# https://leetcode.com/problems/top-k-frequent-elements/
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if len(nums) == 0:
            return []

        element_count = {}
        item = nums[0]
        count = 1
        for x in nums:
            element_count[x] = element_count.get(x, 0) + 1
            if element_count[x] > count:
                count = element_count[x]
                item = x
        
        resp = []
        for i in range(k):
            resp.append(item)
            del element_count[item]
            count = 0
            if len(element_count) == 0:
                break
            
            for x, x_count in element_count.items():
                if x_count > count:
                    count = x_count
                    item = x

        return resp

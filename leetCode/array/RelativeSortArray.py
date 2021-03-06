# https://leetcode.com/problems/relative-sort-array/
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        num_value = {}
        len2 = len(arr2)
        
        if len2 == 0:
            return arr1
        
        for i in range(len2):
            num_value[arr2[i]] = i
            
        arr1 = sorted(arr1, key=lambda x: num_value.get(x, len2 + x))
        
        return arr1

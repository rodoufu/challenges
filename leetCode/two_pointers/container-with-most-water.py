# https://leetcode.com/problems/container-with-most-water/
class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = 0
        k = len(height) - 1
        max_found = 0 
        while i < k:
            # print(f"i: {i}, k: {k}, h[i]: {height[i]}, h[k]: {height[k]}, max_found: {max_found}")
            area = min(height[i], height[k]) * (k - i) 
            max_found = max(area, max_found)
            if height[i] < height[k]:
                i += 1
            elif height[i] > height[k]:
                k -= 1
            else:
                i += 1
        
        return max_found

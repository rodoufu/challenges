# https://leetcode.com/problems/search-a-2d-matrix/
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        
        low_l = 0
        high_l = len(matrix) - 1

        while low_l <= high_l:
            mid_l = low_l + (high_l - low_l) // 2

            if matrix[mid_l][0] == target:
                return True
            elif matrix[mid_l][0] < target:
                if mid_l + 1 >= len(matrix) or matrix[mid_l + 1][0] > target:
                    break
                low_l = mid_l + 1
            else:
                high_l = mid_l - 1
        
        low_c = 0
        high_c = len(matrix[0]) - 1

        while low_c <= high_c:
            mid_c = low_c + (high_c - low_c) // 2
            if matrix[mid_l][mid_c] == target:
                return True
            elif matrix[mid_l][mid_c] < target:
                low_c = mid_c + 1
            else:
                high_c = mid_c - 1
        
        return False

# https://leetcode.com/problems/kth-missing-positive-number/

class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        idx = 0
        next_num = 1
        lena = len(arr)
        count = 1
        while idx < lena:
            if arr[idx] == next_num:
                idx += 1
                next_num += 1
            elif count == k:
                break
            else:
                count += 1
                next_num += 1
        
        # print(f"idx: {idx}, lena: {lena}, next_num: {next_num}, count: {count}, k: {k}")
        # if idx == lena:
            # return 
        
        return next_num + k - count

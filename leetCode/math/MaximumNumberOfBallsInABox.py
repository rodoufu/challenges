# https://leetcode.com/problems/maximum-number-of-balls-in-a-box/
class Solution:
    def sum_digits(self, value: int) -> int:
        resp = 0
        while value > 0:
            resp += value % 10
            value //= 10
        return resp

    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        box = {}
        for i in range(lowLimit, highLimit + 1):
            val = self.sum_digits(i)
            # print(f"sum_d({i})={val}")
            box[val] = box.get(val, 0) + 1
            
        max_i = None
        
        for x, count in box.items():
            # print(f"{x}: {count}")
            if not max_i or count > box[max_i]:
                max_i = x
        
        return box[max_i]

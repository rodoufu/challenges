# https://leetcode.com/problems/defuse-the-bomb/
class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        len_c = len(code)
        if k == 0:
            for i in range(len_c):
                code[i] = 0
            return code
        
        sum_b = 1
        if k < 0:
            sum_b = len_c + k
        sum_e = sum_b
        sum_i = 1
        val = 0
        for _ in range(k if k > 0 else -k):
            # print(f"{code[sum_e]}, e: {sum_e}, v: {val}")
            val += code[sum_e]
            sum_e = (sum_e + sum_i) % len_c
        
        # print(f"\nb: {sum_b}, e: {sum_e}, i: {sum_i}, v: {val}\n")
        
        resp = []
        for _ in range(len_c):
            resp.append(val)
            val -= code[sum_b]
            sum_b = (sum_b + sum_i) % len_c
            val += code[sum_e]
            sum_e = (sum_e + sum_i) % len_c

            # print(f"b: {sum_b}, e: {sum_e}, v: {val}, r: {resp}")
        
        return resp

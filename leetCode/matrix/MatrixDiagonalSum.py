# https://leetcode.com/problems/matrix-diagonal-sum/

class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        if not mat:
            return 0
        lenx = len(mat)
        
        mid = lenx // 2
        resp = -mat[mid][mid] if lenx % 2 != 0 else 0
        # print(f"resp: {resp}, mid: {mid}, lenx: {lenx}")
        for i in range(lenx):
            secondary = lenx - i - 1
            # print(f"resp: {resp}, i: {i}, secondary: {secondary}, mat[i][i]: {mat[i][i]}, mat[i][secondary]: {mat[i][secondary]}")
            resp += mat[i][i]
            resp += mat[i][secondary]

        return resp

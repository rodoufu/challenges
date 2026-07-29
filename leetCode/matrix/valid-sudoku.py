# https://leetcode.com/problems/valid-sudoku/
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        if len(board) == 0 or len(board[0]) == 0:
            return False
        
        values_found = set()
        for line in board:
            values_found.clear()
            for x in line:
                if x.isdigit():
                    if x in values_found:
                        # print(f"x: {x}, line: {line}, values_found: {values_found}")
                        return False
                    values_found.add(x)
        
        n = len(board)
        m = len(board[0])
        for j in range(m):
            values_found.clear()
            for i in range(n):
                x = board[i][j]
                if x.isdigit():
                    if x in values_found:
                        # print(f"i: {i}, j: {j}, x: {x}, values_found: {values_found}")
                        return False
                    values_found.add(x)
        
        side = 3
        for i in range(side):
            for j in range(side):
                values_found.clear()
                for k in range(side):
                    for l in range(side):
                        x = board[i*side + k][j * side + l]
                        if x.isdigit():
                            if x in values_found:
                                # print(f"i: {i}, j: {j}, k:{k}, l:{l}, x: {x}, values_found: {values_found}")
                                return False
                            values_found.add(x)
        
        return True

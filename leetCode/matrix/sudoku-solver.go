// https://leetcode.com/problems/sudoku-solver/
const (
	n  = 9
	sn = 3
)

func hasValue(board [][]byte, row, col int) bool {
	for i := 0; i < n; i++ {
		if i == row {
			continue
		}
		if board[i][col] == board[row][col] {
			return true
		}
	}
	for i := 0; i < n; i++ {
		if i == col {
			continue
		}
		if board[row][col] == board[row][i] {
			return true
		}
	}
	sr := row / sn
	sc := col / sn
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			rowV := sn*sr + i
			colV := sn*sc + j

			if rowV != row || colV != col {
				if board[row][col] == board[rowV][colV] {
					return true
				}
			}
		}
	}
	return false
}

func solve(board [][]byte) bool {
	noDots := true
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == '.' || board[i][j] == 0 {
				noDots = false
				for k := 1; k <= 9; k++ {
					board[i][j] = byte(int('0') + k)
					//board[i][j] = byte(k)
					if !hasValue(board, i, j) {
						if solve(board) {
							return true
						}
					}
				}
				board[i][j] = '.'
				//board[i][j] = 0

				return false
			}
		}
	}
	return noDots
}

func solveSudoku(board [][]byte) {
	solve(board)
}

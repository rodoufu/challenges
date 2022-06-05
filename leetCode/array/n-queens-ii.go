// https://leetcode.com/problems/n-queens-ii/
func totalNQueens(n int) int {
    if n <= 1 {
        return n
    }
    col := make([]bool, n)
    diag := make([]bool, 2*n-1)
    antiDiag := make([]bool, 2*n-1)
    return countMoves(col, diag, antiDiag, 0)
}

func countMoves(col, diag, antiDiag []bool, row int) int {
    n := len(col)
    count := 0
    if row == n {
        return 1
    }
    for column := 0; column < n; column++ {
        if !col[column] && !diag[row + column] && !antiDiag[row - column + n - 1] {
            col[column], diag[row + column], antiDiag[row - column + n - 1] = true, true, true
            count += countMoves(col, diag, antiDiag, row + 1)
            col[column], diag[row + column], antiDiag[row - column + n - 1] = false, false, false
        }
    }
    return count
} 

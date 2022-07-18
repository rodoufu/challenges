// https://leetcode.com/problems/n-queens/
func solveNQueens(n int) [][]string {
    if n < 1 {
        return [][]string{}
    }
    col := make([]bool, n)
    colNum := make([]int, n)
    diag := make([]bool, 2*n-1)
    antiDiag := make([]bool, 2*n-1)
    return countMoves(col, diag, antiDiag, colNum, 0)
}


func countMoves(col, diag, antiDiag []bool, colNum []int, row int) [][]string {
    n := len(col)
    if row == n {
        solution := make([]string, 0, n)
        for _, column := range colNum {
            var sb strings.Builder
            for i := 0; i < column - 1; i++ {
                sb.WriteRune('.')
            }
            sb.WriteRune('Q')
            for i := column; i < n; i++ {
                sb.WriteRune('.')
            }
            solution = append(solution, sb.String())
        }
        
        return [][]string{
            solution,
        }
    }
    var resp [][]string
    for column := 0; column < n; column++ {
        if !col[column] && !diag[row + column] && !antiDiag[row - column + n - 1] {
            col[column], diag[row + column], antiDiag[row - column + n - 1], colNum[column] = true, true, true, row + 1
            resp = append(resp, countMoves(col, diag, antiDiag, colNum, row + 1)...)
            col[column], diag[row + column], antiDiag[row - column + n - 1], colNum[column] = false, false, false, 0
        }
    }
    return resp
}

// https://leetcode.com/problems/unique-paths
func printBoard(board [][]int) {
    fmt.Printf("board:\n")
    for _, line := range board {
        fmt.Printf("%v\n", line)
    }
}
func maxInt(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func moveRobot(board [][]int, l, c int) {
    //fmt.Printf("l: %v, c: %v ", l, c)
    //printBoard(board)
    
    if l + 1 < len(board) {
        //board[l+1][c] = maxInt(board[l][c], board[l+1][c]) + 1
        board[l+1][c] += board[l][c]
        
        //moveRobot(board, l+1, c)
    }
    if c + 1 < len(board[0]) {
        //board[l][c+1] = maxInt(board[l][c], board[l][c+1]) + 1
        board[l][c+1] += board[l][c]
        
        //moveRobot(board, l, c+1)
    }
    //fmt.Printf("l: %v, c: %v ", l, c)
    //printBoard(board)
}

func uniquePaths(m int, n int) int {
    var board [][]int
    board = make([][]int, m)
    for i := 0; i < m; i ++ {
        board[i] = make([]int, n)
    }
    board[0][0] = 1
    //printBoard(board)
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            moveRobot(board, i, j)
        }
    }
    
    //printBoard(board)
    
    return board[m - 1][n -1]
}

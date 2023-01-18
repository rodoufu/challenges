// https://leetcode.com/problems/unique-paths-ii/
func moveRobot(obstacleGrid [][]int, board [][]int, l, c int) {
    //fmt.Printf("l: %v, c: %v ", l, c)
    //printBoard(board)
    
    if l + 1 < len(board) && obstacleGrid[l+1][c] == 0 {
        //board[l+1][c] = maxInt(board[l][c], board[l+1][c]) + 1
        board[l+1][c] += board[l][c]
        
        //moveRobot(board, l+1, c)
    }
    if c + 1 < len(board[0]) && obstacleGrid[l][c+1] == 0 {
        //board[l][c+1] = maxInt(board[l][c], board[l][c+1]) + 1
        board[l][c+1] += board[l][c]
        
        //moveRobot(board, l, c+1)
    }
    //fmt.Printf("l: %v, c: %v ", l, c)
    //printBoard(board)
}

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    m := len(obstacleGrid)
    n := len(obstacleGrid[0])
    if m == 1 && n == 1 && obstacleGrid[0][0] == 1 {
        return 0
    }
        var board [][]int
    board = make([][]int, m)
    for i := 0; i < m; i ++ {
        board[i] = make([]int, n)
    }
    board[0][0] = 1
    //printBoard(board)
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if obstacleGrid[i][j] == 0 {
                moveRobot(obstacleGrid, board, i, j)
            }
        }
    }
    
    //printBoard(board)
    
    return board[m - 1][n -1]
}

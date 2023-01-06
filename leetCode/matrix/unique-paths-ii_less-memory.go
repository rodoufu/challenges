// https://leetcode.com/problems/unique-paths-ii/
func moveRobot(obstacleGrid [][]int, l, c int) {
    //fmt.Printf("l: %v, c: %v ", l, c)
    //printBoard(board)
    
    if l + 1 < len(obstacleGrid) && obstacleGrid[l+1][c] >= 0 {
        //board[l+1][c] = maxInt(board[l][c], board[l+1][c]) + 1
        obstacleGrid[l+1][c] += obstacleGrid[l][c]
        
        //moveRobot(board, l+1, c)
    }
    if c + 1 < len(obstacleGrid[0]) && obstacleGrid[l][c+1] >= 0 {
        //board[l][c+1] = maxInt(board[l][c], board[l][c+1]) + 1
        obstacleGrid[l][c+1] += obstacleGrid[l][c]
        
        //moveRobot(board, l, c+1)
    }
    //fmt.Printf("l: %v, c: %v ", l, c)
    //printBoard(board)
}

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    m := len(obstacleGrid)
    n := len(obstacleGrid[0])
    
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            obstacleGrid[i][j] *= -1
        }
    }
    if obstacleGrid[m-1][n-1] < 0 || obstacleGrid[0][0] < 0 {
        return 0
    }

    obstacleGrid[0][0] = 1
    //printBoard(board)
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if obstacleGrid[i][j] >= 0 {
                moveRobot(obstacleGrid, i, j)
            }
        }
    }
    
    //printBoard(board)
    
    return obstacleGrid[m - 1][n -1]
}

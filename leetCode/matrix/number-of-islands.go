// https://leetcode.com/problems/number-of-islands
func expandLand(grid [][]byte, x, y int) {
    if x < 0 || y < 0 || x > len(grid) - 1 || y > len(grid[0]) - 1 {
        return
    }
    if grid[x][y] == '1' {
        grid[x][y] = '2'
        expandLand(grid, x - 1, y)
        expandLand(grid, x, y - 1)
        expandLand(grid, x + 1, y)
        expandLand(grid, x, y + 1)
    }
}

func numIslands(grid [][]byte) int {
    numOfIslands := 0
    lenX := len(grid)
    lenY := len(grid[0])
    for i := 0; i < lenX; i++ {
        for j := 0; j < lenY; j++ {
            if grid[i][j] == '1' {
                //fmt.Printf("x: %v, y: %v, numOfIslands: %v\n", i, j, numOfIslands)
                numOfIslands++
                expandLand(grid, i, j)
            }
        }
    }
    return numOfIslands
}

// https://leetcode.com/problems/max-area-of-island/
func expandLand(grid [][]int, x, y, size int) int {
    if x < 0 || y < 0 || x > len(grid) - 1 || y > len(grid[0]) - 1 {
        return size
    }
    if grid[x][y] == 1 {
        grid[x][y] = 2
        size++
        size = expandLand(grid, x - 1, y, size)
        size = expandLand(grid, x, y - 1, size)
        size = expandLand(grid, x + 1, y, size)
        size = expandLand(grid, x, y + 1, size)
    }
    return size
}

func maxAreaOfIsland(grid [][]int) int {
    maxIslandSize := 0
    lenX := len(grid)
    lenY := len(grid[0])
    for i := 0; i < lenX; i++ {
        for j := 0; j < lenY; j++ {
            if grid[i][j] == 1 {
                size := expandLand(grid, i, j, 0)
                if size > maxIslandSize {
                    maxIslandSize = size
                }
                //fmt.Printf("x: %v, y: %v, size: %v, maxIslandSize: %v\n", i, j, size, maxIslandSize)
            }
        }
    }
    return maxIslandSize
}

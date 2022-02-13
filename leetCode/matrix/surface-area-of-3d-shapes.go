// https://leetcode.com/problems/surface-area-of-3d-shapes/
func abs(x int) int {
    if x >= 0 {
        return x
    }
    return -x
}
func surfaceArea(grid [][]int) int {
    lenX := len(grid)
    if lenX == 0 {
        return 0
    }
    lenY := len(grid[0])
    if lenY == 0 {
        return 0
    }
    var workspace [][]int
    workspace = make([][]int, lenX + 2)
    for i := 0; i < lenX + 2; i++ {
        workspace[i] = make([]int, lenY + 2)
    }
    max := -1
    for i := 0; i < lenX; i++ {
        for j := 0; j < lenY; j++ {
            if grid[i][j] > max {
                max = grid[i][j]
            }
            workspace[i+1][j+1] = grid[i][j]
        }
    }
    count := 0
    for {
        for i := 0; i < lenX; i++ {
            for j := 0; j < lenY; j++ {
                surfaces := 0
                gAbs := abs(workspace[i+1][j+1])
                if gAbs == max {
                    if workspace[i+1][j+1] > 0 {
                        surfaces++
                    }
                    otherAbs := abs(workspace[i+1][j])
                    if gAbs > otherAbs {
                        surfaces++
                    }
                    otherAbs = abs(workspace[i][j+1])
                    if gAbs > otherAbs {
                        surfaces++
                    }
                    otherAbs = abs(workspace[i+1][j+2])
                    if gAbs > otherAbs {
                        surfaces++
                    }
                    otherAbs = abs(workspace[i+2][j+1])
                    if gAbs > otherAbs {
                        surfaces++
                    }
                    if gAbs == 1 {
                        surfaces++
                    }
                }
                //fmt.Printf("(%v, %v):%v->%v\n", i, j, workspace[i+1][j+1], surfaces)
                count += surfaces
            }
        }
        
        if max == 1 {
            break
        }
        //fmt.Println("again")
        
        for i := 0; i < lenX; i++ {
            for j := 0; j < lenY; j++ {
                if workspace[i+1][j+1] == max {
                    workspace[i+1][j+1] = -(workspace[i+1][j+1] - 1)
                } else if workspace[i+1][j+1] == -max {
                    workspace[i+1][j+1] += 1
                }
            }
        }
        max--
    }
    return count
}

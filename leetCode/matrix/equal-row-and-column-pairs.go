// https://leetcode.com/problems/equal-row-and-column-pairs/
func equalPairs(grid [][]int) int {
    cols := map[string]int{}
    lenG := len(grid)
    
    for i := 0; i < lenG; i++ {
        var colSB strings.Builder
        for j := 0; j < lenG; j++ {
            colSB.WriteString(fmt.Sprintf("%v,", grid[j][i]))
        }
        cols[colSB.String()]++
    }
    count := 0
    //fmt.Printf("cols: %v\n", cols)
    for i := 0; i < lenG; i++ {
        var rowSB strings.Builder
        for j := 0; j < lenG; j++ {
            rowSB.WriteString(fmt.Sprintf("%v,", grid[i][j]))
        }
        row := rowSB.String()
        if val, ok := cols[row]; ok {
            //fmt.Printf("i: %v, row: %v, val: %v\n", i, row, val)
            count += val
        } else {
            //fmt.Printf("i: %v, row: %v - not\n", i, row)
        }
    }
    
    return count
}

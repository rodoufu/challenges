// https://leetcode.com/problems/delete-greatest-value-in-each-row/
type valCount struct {
    val int
    count int
}

func deleteGreatestValue(grid [][]int) int {
    var linesCount [][]valCount
    for i, line := range grid {
        linesCount = append(linesCount, []valCount{})
        numCount := map[int]int{}
        for _, x := range line {
            numCount[x]++
        }
        
        //fmt.Printf("i: %v, numCount: %v\n", i, numCount)
        for num, count := range numCount {
            linesCount[i] = append(linesCount[i], valCount{
                val: num,
                count: count,
            })
            
            for it := len(linesCount[i]) - 1; it > 0 && linesCount[i][it].val < linesCount[i][it - 1].val; it-- {
                linesCount[i][it], linesCount[i][it - 1] = linesCount[i][it - 1], linesCount[i][it]
            }
        }
        //fmt.Printf("i: %v, linesCount: %v\n", i, linesCount[i])
    }
    //fmt.Printf("linesCount: %v\n", linesCount)
    resp := 0
    for {
        if len(linesCount[0]) == 0{
            break
        }
        maxSoFar := linesCount[0][len(linesCount[0]) - 1].val
        for j, lc := range linesCount {
            if lc[len(lc) - 1].val > maxSoFar {
                maxSoFar = lc[len(lc) - 1].val
            }
            lc[len(lc) - 1].count--
            if lc[len(lc) - 1].count == 0 {
                linesCount[j] = lc[:len(lc)-1]
            }
        }
        resp += maxSoFar
        //fmt.Printf("maxSoFar: %v, linesCount: %v\n", maxSoFar, linesCount)
    }
    
    return resp
}

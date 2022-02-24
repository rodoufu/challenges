// https://leetcode.com/problems/delete-columns-to-make-sorted/
func minDeletionSize(strs []string) int {
    lenS := len(strs)
    if lenS < 2 {
        return 0
    }
    lenW := len(strs[0])
    count := 0
    for i := 0; i < lenW; i++ {
        shouldAdd := false
        for j := 1; j < lenS; j++ {
            //fmt.Printf("%v-%v-%v ", string(strs[j - 1][i]), string(strs[j][i]), shouldAdd)
            if strs[j][i] < strs[j - 1][i] {
                shouldAdd = true
                //break
            }
        }
        //fmt.Println()
        if shouldAdd {
            count++
        }
    }
    return count
}

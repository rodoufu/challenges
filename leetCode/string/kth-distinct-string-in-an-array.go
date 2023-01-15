// https://leetcode.com/problems/kth-distinct-string-in-an-array/
func kthDistinct(arr []string, k int) string {
    countStr := map[string]int{}
    for _, x := range arr {
        countStr[x]++
    }
    var distnctVal []string
    for _, x := range arr {
        if count := countStr[x]; count == 1 {
            distnctVal = append(distnctVal, x)
            if len(distnctVal) > k {
                break
            }
        }
    }
    if len(distnctVal) < k {
        return ""
    }
    return distnctVal[k - 1]
}

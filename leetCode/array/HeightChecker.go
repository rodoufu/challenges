// https://leetcode.com/problems/height-checker/
func heightChecker(heights []int) int {
    lenH := len(heights)
    toSort := make([]int, lenH)
    for i := 0; i < lenH; i++ {
        toSort[i] = heights[i]
    }
    sort.Ints(toSort)
    cont := 0
    
    for i := 0; i < lenH; i++ {
        if toSort[i] != heights[i] {
            cont++
        }
    }
    
    return cont
}

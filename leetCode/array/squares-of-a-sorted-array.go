// https://leetcode.com/problems/squares-of-a-sorted-array/
func sortedSquares(nums []int) []int {
    var positive[]int
    var negative[]int
    
    for _, x := range nums {
        if x >= 0 {
            positive = append(positive, x * x)
        } else {
            negative = append(negative, x * x)
        }
    }
    
    var resp[]int
    idxP := 0
    idxN := len(negative) - 1
    
    //fmt.Printf("positive: %v, negative: %v\n", positive, negative)
    for idxP < len(positive) && idxN >= 0 {
        if positive[idxP] < negative[idxN] {
            resp = append(resp, positive[idxP])
            idxP++
        } else {
            resp = append(resp, negative[idxN])
            idxN--
        }
    }
    for idxP < len(positive) {
        resp = append(resp, positive[idxP])
        idxP++
    }
    for idxN >= 0 {
        resp = append(resp, negative[idxN])
        idxN--
    }
    
    return resp
}

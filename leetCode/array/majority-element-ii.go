// https://leetcode.com/problems/majority-element-ii/
func majorityElement(nums []int) []int {
    elementCount := map[int]int{}
    for _, x := range nums {
        elementCount[x]++
    }
    var resp []int
    
    lenNum := len(nums)
    for x, count := range elementCount {
        if count > lenNum / 3 {
            resp = append(resp, x)
        }
    }
    
    return resp
}

// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
func minStartValue(nums []int) int {
    if len(nums) == 1 {
        if nums[0] < 0 {
            return 1 + (-nums[0])
        }
        return 1
    }
    resp := 1
    val := 1
    for _, x := range nums {
        val += x 
        if val < 1 {
            resp += 1 - val 
            val = 1
        }
    }
    
    return resp
}

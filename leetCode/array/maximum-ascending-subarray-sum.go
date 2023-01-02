// https://leetcode.com/problems/maximum-ascending-subarray-sum/
func maxAscendingSum(nums []int) int {
    resp := nums[0]
    val := nums[0]
    ln := len(nums)
    for i:=1;i<ln;i++{
        if nums[i]>nums[i-1]{
            val += nums[i]

        } else {
            val = nums[i]
        }
        if val > resp {
            resp = val 
        }
    }
    return resp
}

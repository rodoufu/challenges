//https://leetcode.com/problems/number-of-unequal-triplets-in-array/
func unequalTriplets(nums []int) int {
    resp := 0
    for i := 0; i < len(nums); i++ {
        for j := i + 1; j < len(nums); j++ {
            if nums[i] == nums[j] {
                continue 
            }
            for k := j + 1; k < len(nums); k++ {
                if nums[i] != nums[k] && nums[j] != nums[k] {
                    resp++
                }
            }
        }
    }
    return resp
}

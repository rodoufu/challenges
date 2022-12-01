// https://leetcode.com/problems/find-subarrays-with-equal-sum/
func findSubarrays(nums []int) bool {
    sums := map[int]struct{}{}
    for i := 1; i < len(nums); i++ {
        s := nums[i] + nums[i - 1]
        if _, ok := sums[s]; ok {
            return true 
        }
        sums[s] = struct{}{}
    }
    return false
}

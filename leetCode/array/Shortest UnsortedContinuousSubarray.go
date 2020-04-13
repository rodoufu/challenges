// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
func findUnsortedSubarray(nums []int) int {
    s := make([]int, len(nums))
    copy(s, nums)
    sort.Ints(s)
    b := 0
    e := len(nums) - 1
    for b < len(nums) {
        if nums[b] != s[b] {
            break
        }
        b++
    }
    for e > 0 {
        if nums[e] != s[e] {
            break
        }
        e--
    }
    if b < e {
        return e - b + 1
    }
    return 0
}

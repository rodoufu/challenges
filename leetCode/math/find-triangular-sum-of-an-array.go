// https://leetcode.com/problems/find-triangular-sum-of-an-array/
func triangularSum(nums []int) int {
    lenNums := len(nums)
    if lenNums == 1 {
        value := nums[0] % 10
        if value < 0 {
            value *= -1
        }
        return value
    }
    resp := make([]int, lenNums)
    for i := 0; i < lenNums; i++ {
        resp[i] = nums[i]
    }
    for lenNums > 1 {
        for i := 0; i < lenNums; i++ {
            nums[i] = resp[i]
        }
        for i := 0; i < lenNums - 1; i ++ {
            resp[i] = (nums[i] + nums[i + 1]) % 10
        }
        lenNums--
    }
    value := resp[0] % 10
    if value < 0 {
        value *= -1
    }
    return value
}

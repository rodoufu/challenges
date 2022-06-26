// https://leetcode.com/problems/3sum-closest/
func threeSumClosest(nums []int, target int) int {
    lenN := len(nums)
    if lenN < 3 {
        return -1
    }
    closest := nums[0] + nums[1] + nums[2]
    diff := target - closest
    if diff < 0 {
        diff *= -1
    }
    for i := 0; i < lenN && diff > 0; i++ {
        for j := i + 1; j < lenN && diff > 0; j++ {
            for k := j + 1; k < lenN && diff > 0; k++ {
                current := nums[i] + nums[j] + nums[k]
                currentDiff := target - current
                if currentDiff < 0 {
                    currentDiff *= -1
                }
                if currentDiff < diff {
                    diff = currentDiff
                    closest = current
                }
            }
        }
    }
    return closest
}

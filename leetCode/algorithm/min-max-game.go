// https://leetcode.com/problems/min-max-game/
func minInt(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func maxInt(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func minMaxGame(nums []int) int {
    n := len(nums)
    if n == 1 {
        return nums[0]
    }
    resp := make([]int, 0, n/2)
    isMin := true
    for i := 0; i < n; i += 2 {
        if isMin {
            resp = append(resp, minInt(nums[i], nums[i + 1]))
        } else {
            resp = append(resp, maxInt(nums[i], nums[i + 1]))
        }
        isMin = !isMin
    }
    return minMaxGame(resp)
}

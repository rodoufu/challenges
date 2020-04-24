// https://leetcode.com/problems/check-if-n-and-its-double-exist/
func checkIfExist(arr []int) bool {
    nums := make(map[int]struct{})
    for _, x := range arr {
        if _, ok := nums[0]; ok && x == 0 {
            return true
        }
        nums[x] = struct{}{}
    }
    for _, x := range arr {
        if _, ok := nums[2 * x]; ok && x != 0 {
            return true
        }
    }

    return false
}

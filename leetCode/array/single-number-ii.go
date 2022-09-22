// https://leetcode.com/problems/single-number-ii/
func singleNumber(nums []int) int {
    numberCount := map[int]int{}
    for _, val := range nums {
        numberCount[val]++
    }
    for num, count := range numberCount {
        if count == 1 {
            return num
        }
    }
    return -1
}

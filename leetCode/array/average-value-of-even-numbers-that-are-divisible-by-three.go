// https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/
func averageValue(nums []int) int {
    sum := 0
    count := 0
    for _, x := range nums {
        if x % 6 == 0 {
            sum += x
            count++
        }
    }
    
    if count > 0 {
        return sum / count
    }
    return 0
}

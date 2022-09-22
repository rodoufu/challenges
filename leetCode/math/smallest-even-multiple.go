// https://leetcode.com/problems/smallest-even-multiple/
func smallestEvenMultiple(n int) int {
    if n % 2 == 0 {
        return n
    }
    return n * 2
}

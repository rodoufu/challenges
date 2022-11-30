// https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/
func numberOfCuts(n int) int {
    if n <= 1 {
        return 0
    }
    if n % 2 == 0 {
        return n / 2
    }
    return n
}

// https://leetcode.com/problems/counting-bits/
func countBits(n int) []int {
    if n == 0 {
        return []int { 0 }
    }
    resp := make([]int, n+1)
    resp[0] = 0
    resp[1] = 1
    for i := 1; i <= n / 2; i++ {
        resp[2*i] = resp[i]
        if 2 * i + 1 <= n {
            resp[2*i+1] = resp[i] + 1
        }
    }
    return resp
}

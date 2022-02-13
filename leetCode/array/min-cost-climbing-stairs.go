// https://leetcode.com/problems/min-cost-climbing-stairs/
func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
func minCostClimbingStairs(cost []int) int {
    lenC := len(cost)
    switch len(cost) {
    case 0:
        return 0
    case 1:
        return cost[0]
    case 2:
        if cost[0] < cost [1] {
            return cost[0]
        }
        return cost[1]
    }
    spent := make([]int, lenC + 2)
    for i := 0; i < lenC; i++ {
        spent[i + 2] = cost[i] + min(spent[i], spent[i + 1])
    }
    if spent[lenC] < spent[lenC + 1] {
        return spent[lenC]
    }
    return spent[lenC + 1]
}

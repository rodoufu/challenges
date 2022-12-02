// https://leetcode.com/problems/find-the-pivot-integer/
func pivotInteger(n int) int {
    if n <= 1 {
        return 1
    }
    sumSoFar := []int{ 0, 1 }
    for i := 2; i <= n; i++ {
        sumSoFar = append(sumSoFar, i + sumSoFar[i-1])
    }
    //fmt.Printf("sum: %v\n", sumSoFar)
    for i := 1; i < n; i++ {
        if sumSoFar[i] == sumSoFar[n] - sumSoFar[i + 1] {
            return i + 1
        }
    }
    
    return -1
}

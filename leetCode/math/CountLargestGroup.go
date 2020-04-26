// https://leetcode.com/problems/count-largest-group/
func sumDigits(n int) int {
    resp := 0
    for n > 0 {
        resp += n % 10
        n /= 10
    }
    return resp
}
func countLargestGroup(n int) int {
    countDigits := make(map[int][]int)
    largest := 0
    for i := 1; i <= n; i++ {
        theSum := sumDigits(i)
        countDigits[theSum] = append(countDigits[theSum], i)
        lenCount := len(countDigits[theSum])
        if lenCount > largest {
            largest = lenCount
        }
    }
    
    count := 0
    for _, x := range countDigits {
        if len(x) == largest {
            count++
        }
    }
    return count
}

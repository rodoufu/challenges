// https://leetcode.com/problems/maximum-number-of-pairs-in-array/
func numberOfPairs(nums []int) []int {
    numCount := map[int]int{}
    for _, num := range nums {
        numCount[num]++
    }
    pairs := 0
    left := 0
    for _, count := range numCount {
        pairs += count / 2
        left += count % 2
    }
    
    return []int{ pairs, left }
}

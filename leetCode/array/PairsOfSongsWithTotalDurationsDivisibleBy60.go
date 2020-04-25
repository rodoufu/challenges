// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
func numPairsDivisibleBy60(time []int) int {
    lent := len(time)
    count := 0
    for i := 0; i < lent; i++ {
        for j := i + 1; j < lent; j++ {
            if (time[i] + time[j]) % 60 == 0 {
                count++
            }
        }
    }
    return count
}

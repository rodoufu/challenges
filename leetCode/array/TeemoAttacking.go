// https://leetcode.com/problems/teemo-attacking/
func findPoisonedDuration(timeSeries []int, duration int) int {
    sort.Ints(timeSeries)
    poisoned := []int{0, -1}
    poisonedTime := 0
    
    for _, t := range timeSeries {
        if t > poisoned[1] {
            poisonedTime += poisoned[1] - poisoned[0] + 1
            poisoned[0] = t
        }
        
        poisoned[1] = t + duration - 1
    }
    poisonedTime += poisoned[1] - poisoned[0] + 1
    
    return poisonedTime
}

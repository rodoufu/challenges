// https://leetcode.com/problems/maximum-number-of-balloons/
func maxNumberOfBalloons(text string) int {
    count := make(map[rune]int)
    
    for _, x := range text {
        if _, ok := count[x]; ok {
            count[x]++
        } else {
            count[x] = 1
        }
    }
    
    value := 0
    for count['b'] > 0 && count['a'] > 0 && count['l'] > 1 && count['o'] > 1 && count['n'] > 0 {
        count['b'] -= 1
        count['a'] -= 1
        count['l'] -= 2
        count['o'] -= 2
        count['n'] -= 1
        value++
    }
    
    return value
}

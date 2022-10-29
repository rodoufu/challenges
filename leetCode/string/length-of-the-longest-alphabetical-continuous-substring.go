// https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/
func longestContinuousSubstring(s string) int {
    maxFound := 1
    lenS := len(s)
    current := 1
    
    for i := 1; i < lenS; i++ {
        if s[i] == s[i - 1] + 1 {
            current++
            if current > maxFound {
                maxFound = current
            }
        } else {
            current = 1
        }
    }
    
    return maxFound
}

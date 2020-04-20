// https://leetcode.com/problems/split-a-string-in-balanced-strings/
func balancedStringSplit(s string) int {
    l := 0
    count := 0
    for _, x := range s {
        if x == 'L' {
            if l == -1 {
                count++
            }
            l++
        } else if x == 'R' {
            if l == 1 {
                count++
            }
            l--
        }
    }
    return count
}

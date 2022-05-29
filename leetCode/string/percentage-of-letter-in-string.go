// https://leetcode.com/problems/percentage-of-letter-in-string/
func percentageLetter(s string, letter byte) int {
    count := 0
    for _, it := range s {
        if byte(it) == letter {
            count++
        }
    }
    return 100 * count / len(s)
}

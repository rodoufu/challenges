// https://leetcode.com/problems/count-prefixes-of-a-given-string/
func countPrefixes(words []string, s string) int {
    count := 0
    for _, w := range words {
        if strings.HasPrefix(s, w) {
            count++
        }
    }
    return count
}

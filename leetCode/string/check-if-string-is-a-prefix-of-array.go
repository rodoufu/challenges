// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/
func isPrefixString(s string, words []string) bool {
    var sb strings.Builder
    lenS := len(s)
    for _, w := range words {
        if sb.Len() >= lenS {
            break
        }
        sb.WriteString(w)
    }
    return s == sb.String()
}

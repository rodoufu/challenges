// https://leetcode.com/problems/removing-stars-from-a-string/
type letterPosition struct {
    letter rune
    position int
}

func removeStars(s string) string {
    var letterStack []string
    for _, letter := range s {
        if letter == '*' {
            if len(letterStack) == 0 {
                return ""
            }
            letterStack = letterStack[:len(letterStack)-1]
        } else {
            letterStack = append(letterStack, string(letter))
        }
    }
    return strings.Join(letterStack, "")
}

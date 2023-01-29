// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
func isPalindrome(word string) bool {
    lw := len(word)
    for i := 0; i < lw; i++ {
        if word[i] != word[lw - i - 1] {
            return false
        }
    }
    return true
}
func firstPalindrome(words []string) string {
    for _, word := range words {
        if isPalindrome(word) {
            return word
        }
    }
    return ""
}

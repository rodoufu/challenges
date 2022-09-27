// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
func makeEqual(words []string) bool {
    charCount := map[rune]int{}
    for _, word := range words {
        for _, letter := range word {
            charCount[letter]++
        }
    }
    lenW := len(words)
    for _, count := range charCount {
        if count % lenW != 0 {
            return false
        }
    }
    return true
}

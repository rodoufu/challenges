// https://leetcode.com/problems/first-letter-to-appear-twice/
func repeatedCharacter(s string) byte {
    letterCount := map[rune]struct{}{}
    for _, letter := range s {
        if _, ok := letterCount[letter]; ok {
            return byte(letter)
        }
        letterCount[letter] = struct{}{}
    }
    return 0
}

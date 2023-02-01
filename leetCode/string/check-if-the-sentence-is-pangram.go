// https://leetcode.com/problems/check-if-the-sentence-is-pangram
func checkIfPangram(sentence string) bool {
    if len(sentence) < 26 {
        return false
    }
    letterPresent := map[rune]struct{}{}

    for _, x := range sentence {
        letterPresent[x] = struct{}{}
    }

    return len(letterPresent) >= 26
}

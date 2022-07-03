// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
func isPrefixOfWord(sentence string, searchWord string) int {
    words := strings.Split(sentence, " ")
    index := -1
    for i, w := range words {
        if strings.HasPrefix(w, searchWord) {
            index = i + 1
            break
        }
    }
    return index
}

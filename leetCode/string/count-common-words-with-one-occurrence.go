// https://leetcode.com/problems/count-common-words-with-one-occurrence
func countWords(words1 []string, words2 []string) int {
    count1 := map[string]int{}
    count2 := map[string]int{}
    for _, word := range words1 {
        count1[word]++
    }
    for _, word := range words2 {
        count2[word]++
    }
    resp := 0
    for word, c1 := range count1 {
        if c2, ok := count2[word]; ok && c1 == 1 && c2 == 1 {
            resp++
        }
    }

    return resp
}

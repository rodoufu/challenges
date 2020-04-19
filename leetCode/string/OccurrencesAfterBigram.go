// https://leetcode.com/problems/occurrences-after-bigram/
func findOcurrences(text string, first string, second string) []string {
    words := strings.Split(text, " ")
    var resp []string
    lenw := len(words)
    for i, x := range words {
        if i + 2 >= lenw {
            break
        }
        if x == first && words[i + 1] == second {
            resp = append(resp, words[i + 2])
        }
    }
    return resp
}

// https://leetcode.com/problems/rearrange-characters-to-make-target-string
func countLetters(w string) map[rune]int {
    resp := make(map[rune]int)
    for _, l := range w {
        resp[l]++
    }
    return resp
}

func rearrangeCharacters(s string, target string) int {
    countLettersS := countLetters(s)
    countLettersTarget := countLetters(target)
    minTimes := len(s)
    for letter, countT := range countLettersTarget {
        count, ok := countLettersS[letter]
        if !ok {
            return 0
        }
        v := count / countT
        if v == 0 {
            return 0
        }
        if v < minTimes {
            minTimes = v
        }
    }
    return minTimes
}

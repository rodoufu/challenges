// https://leetcode.com/problems/sort-characters-by-frequency/
type letterFrequency struct {
    letter rune
    count int
}

func frequencySort(s string) string {
    letterCount := map[rune]int{}
    for _, letter := range s {
        letterCount[letter]++
    }
    
    var lettersFrequency []letterFrequency
    for letter, count := range letterCount {
        lettersFrequency = append(lettersFrequency, letterFrequency{
            letter: letter,
            count: count,
        })
        for it := len(lettersFrequency) - 1; it > 0 && lettersFrequency[it].count > lettersFrequency[it - 1].count; it-- {
            lettersFrequency[it], lettersFrequency[it - 1] = lettersFrequency[it - 1], lettersFrequency[it]
        }
    }
    var resp strings.Builder
    for _, lc := range lettersFrequency {
        for i := 0; i < lc.count; i++ {
            resp.WriteRune(lc.letter)
        }
    }
    return resp.String()
}

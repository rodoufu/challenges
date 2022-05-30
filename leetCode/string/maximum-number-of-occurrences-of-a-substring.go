// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring
func countLetters(w string) int {
    var resp = map[rune]struct{}{}
    for _, l := range w {
        resp[l] = struct{}{}
    }
    return len(resp)
}

func maxFreq(s string, maxLetters int, minSize int, maxSize int) int {
    countSubStrings := make(map[string]int)
    lenS := len(s)
    for size := minSize; size <= maxSize; size++ {
        for i := 0; i <= lenS - size; i++ {
            countSubStrings[s[i:i+size]]++
        }
    }
    
    //fmt.Printf("countSubStrings: %v\n", countSubStrings)
    maxCount := 0
    for word, count := range countSubStrings {
        if count > maxCount && countLetters(word) <= maxLetters {
            maxCount = count
        }
    }
    
    return maxCount
}

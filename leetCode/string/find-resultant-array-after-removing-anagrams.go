// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams
type anagram struct {
    count map[rune]int
    word string
}

func (a* anagram) isAnagram(b* anagram) bool {
    if (a == nil) != (b == nil) {
        return false
    }
    if len(a.count) != len(b.count) {
        return false
    }
    for letterA, countA := range a.count {
        if countB, ok := b.count[letterA]; !ok || countA != countB {
            return false
        }
    }
    return true
}

func newAnagram(word string) anagram {
    resp := make(map[rune]int)
    for _, letter := range word {
        resp[letter]++
    }
    return anagram {
        count: resp,
        word: word,
    }
}

func removeAnagrams(words []string) []string {
    if len(words) <= 1 {
        return words
    }
    anagrams := make([]anagram, 0, len(words))
    for _, word := range words {
        anagrams = append(anagrams, newAnagram(word))
    }
    index := len(words) - 1
    for index > 0 {
        //fmt.Printf("anagrams: %v\n", anagrams)
        if anagrams[index - 1].isAnagram(&anagrams[index]) {
            anagrams = append(anagrams[:index], anagrams[index+1:]...)
        }
        index--
    }
    resp := make([]string, 0, len(anagrams))
    for _, anagram := range anagrams {
        resp = append(resp, anagram.word)
    }
    return resp
}

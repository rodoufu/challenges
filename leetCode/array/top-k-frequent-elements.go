// https://leetcode.com/problems/top-k-frequent-elements/
type letterFrequency struct {
    letter int
    count int
}

func topKFrequent(nums []int, k int) []int {
    letterCount := map[int]int{}
    for _, letter := range nums {
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
    var resp []int
    for _, lc := range lettersFrequency {
        resp = append(resp, lc.letter)
        if len(resp) >= k {
            break
        }
    }
    return resp
}

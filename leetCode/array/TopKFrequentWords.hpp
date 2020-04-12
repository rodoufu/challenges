// https://leetcode.com/problems/top-k-frequent-words/
type wordCount struct {
    word string
    count int
}

type wordCountSorter []wordCount
func (a wordCountSorter) Len() int { return len(a) }
func (a wordCountSorter) Swap(i, j int) { a[i], a[j] = a[j], a[i] }
func (a wordCountSorter) Less(i, j int) bool { 
    if a[i].count == a[j].count {
        return strings.Compare(a[i].word, a[j].word) < 0
    }
    return a[i].count > a[j].count 
}

func topKFrequent(words []string, k int) []string {
    countWord := make(map[string]int)
    for _, w := range words {
        countWord[w]++
    }
    var counting wordCountSorter
    for n, c := range countWord {
        counting = append(counting, wordCount { n, c })
    }
    
    sort.Sort(counting)
    /*for _, x := range counting {
        fmt.Printf("%s: %d ", x.word, x.count)
    }
    fmt.Printf("\n")*/
    resp := make([]string, k)
    if k > 0 && len(counting) > 0 {
        for i := 0; i < k; i++ {
            resp[i] = counting[i].word
        }
    }
    
    return resp
}

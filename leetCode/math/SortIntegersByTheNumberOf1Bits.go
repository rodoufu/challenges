// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
func countBit(x int) int {
    count := 0
    //fmt.Printf("%d", x)
    for x > 0 {
        if x % 2 == 1 {
            count++
        }
        x /= 2
    }
    //fmt.Printf(": %d\n", count)
    return count
}

type sortInt []int
func (s sortInt) Less(i, j int) bool {
    ci := countBit(s[i])
    cj := countBit(s[j])
    if ci == cj {
        return s[i] < s[j]
    }
    return ci < cj
}
func (s sortInt) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}
func (s sortInt) Len() int {
    return len(s)
}

func sortByBits(arr []int) []int {   
    arrSort := sortInt(arr)
    sort.Sort(arrSort)
    
    return arrSort
}

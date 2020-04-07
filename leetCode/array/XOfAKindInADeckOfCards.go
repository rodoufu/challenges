// https://leetcode.com/problems/sum-of-square-numbers/submissions/
func mdc(a, b int) int {
    for b != 0 {
        a, b = b, a % b
    }
   return a
}

func hasGroupsSizeX(deck []int) bool {
    deckc := make(map[int]int)
    for _, x := range deck {
        deckc[x]++
    }
    minmdc, _ := deckc[deck[0]]
    /*for k, v := range deckc {
        fmt.Printf("%d: %d ", k, v)
    }
    fmt.Printf("\n")
    fmt.Printf("minmdc: %d\n", minmdc)*/
    for _, v := range deckc {
        minmdc = mdc(minmdc, v)
        //fmt.Printf("minmdc: %d - %d\n", minmdc, v)
        if minmdc < 2 {
            return false
        }
    }
    return minmdc >= 2
}

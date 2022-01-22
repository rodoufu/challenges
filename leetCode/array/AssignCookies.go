// https://leetcode.com/problems/assign-cookies/
func findContentChildren(g []int, s []int) int {
    sort.Ints(g)
    sort.Ints(s)
    
    atG := 0
    atS := 0
    happy := 0
    lenG := len(g)
    lenS := len(s)
    
    for atG < lenG && atS < lenS {
        if g[atG] <= s[atS] {
            happy++
            atG++
            atS++
        } else {
            atS++
        }
    }
    
    return happy
}

// https://leetcode.com/problems/longest-uncommon-subsequence-i/
func findLUSlength(a string, b string) int {
    if a == b {

        return -1
    }
    la := len(a)
    lb := len(b)
    if la > lb {
        return la 
    }
    return lb
}

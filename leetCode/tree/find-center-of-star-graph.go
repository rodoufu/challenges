// https://leetcode.com/problems/find-center-of-star-graph/
func findCenter(edges [][]int) int {
    nodes := map[int]struct{}{}
    for _, it := range edges {
        for i:=0; i<2; i++ {
            if _, ok := nodes[it[i]]; ok {
                return it[i]
            }
            nodes[it[i]] = struct {}{}
        }
    }
    return -1
}

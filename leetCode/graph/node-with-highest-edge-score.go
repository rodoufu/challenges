// https://leetcode.com/problems/node-with-highest-edge-score/
func edgeScore(edges []int) int {
    nodeScore := make(map[int]int)
    for from, to := range edges {
        nodeScore[to] += from
    }
    node := -1
    maxVal := -1
    for nodeIt, score := range nodeScore {
        if score > maxVal || (score == maxVal && nodeIt < node) {
            node = nodeIt
            maxVal = score
        }
    }
    return node
}

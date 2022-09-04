// https://leetcode.com/problems/best-poker-hand/
func bestHand(ranks []int, suits []byte) string {
    isFlush := true
    for i := 0; i < 4; i++ {
        if suits[i] != suits[i + 1] {
            isFlush = false
            break
        }
    }
    if isFlush {
        return "Flush"
    }
    rankCount := map[int]int{}
    for _, rank := range ranks {
        rankCount[rank]++
    }
    resp := 1 
    for _, count := range rankCount {
        if count > resp {
            resp = count
        }
    }
    fmt.Printf("rankCount: %v, resp: %v\n", rankCount, resp)
    switch resp {
        case 5:
            return "Three of a Kind"
        case 4:
            return "Three of a Kind"
        case 3:
            return "Three of a Kind"
        case 2:
            return "Pair"
    }
    return "High Card"
}

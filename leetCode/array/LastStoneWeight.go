// https://leetcode.com/problems/last-stone-weight/
func printStones(stones []int) {
    for _, x := range stones {
        //fmt.Printf("%d: %d ", i, x)
        fmt.Printf("%d ", x)
    }
    fmt.Printf("\n")
}
func lastStoneWeight(stones []int) int {
    sort.Ints(stones)
    lenS := len(stones)
    for lenS > 1 {
        //printStones(stones)
        stones[lenS - 2] = stones[lenS - 1] - stones[lenS - 2]
        //printStones(stones)
        if stones[lenS - 2] > 0 {
            stones = stones[:lenS - 1]
        } else {
            stones = stones[:lenS - 2]
        }
        lenS = len(stones)
        for i := lenS - 1; i > 0; i-- {
            if stones[i] < stones[i - 1] {
                stones[i], stones[i - 1] = stones[i - 1], stones[i]
            } else {
                break;
            }
        }
    }
    if lenS > 0 {
        return stones[0]
    }
    return 0
}

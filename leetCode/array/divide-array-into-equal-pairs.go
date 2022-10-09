// https://leetcode.com/problems/divide-array-into-equal-pairs/
func divideArray(nums []int) bool {
    elemens := map[int]struct{}{}
    for _, num := range nums {
        _, ok := elemens[num]
        if ok {
            delete(elemens, num)
        } else {
            elemens[num] = struct{}{}
        }
    }
    return len(elemens) == 0
}

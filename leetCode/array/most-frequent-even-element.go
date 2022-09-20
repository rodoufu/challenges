// https://leetcode.com/problems/most-frequent-even-element/
func mostFrequentEven(nums []int) int {
    elementCount := map[int]int{}
    for _, x := range nums {
        if x % 2 == 0 {
            elementCount[x]++
        }
    }
    maxNum := -1
    //fmt.Printf("elementCount: %v\n", elementCount)
    for x, count := range elementCount {
        //fmt.Printf("x: %v, count: %v, maxNum: %v ->", x, count, maxNum)
        if maxNum == -1 || count > elementCount[maxNum] || (count == elementCount[maxNum] && x < maxNum) {
            maxNum = x
        }
        //fmt.Printf(" maxNum: %v\n", maxNum)
    }
    return maxNum
}

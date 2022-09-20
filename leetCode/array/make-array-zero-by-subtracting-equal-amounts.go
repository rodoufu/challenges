// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
func minimumOperations(nums []int) int {
    uniqueNums := map[int]struct{}{}
    smaller := -1
    for _, num := range nums {
        if num > 0 {
            uniqueNums[num] = struct{}{}
            if num < smaller || smaller == -1 {
                smaller = num
            }
        }
    }
    
    
    countOps := 0
    for ; len(uniqueNums) > 0; countOps++ {
        //fmt.Printf("uniqueNums: %v, smaller: %v\n", uniqueNums, smaller)
        if _, ok := uniqueNums[0]; ok &&len(uniqueNums) == 1 {
            return countOps
        }
        tempUniqueNums := map[int]struct{}{}
        newSmaller := -1
        
        for num, _ := range uniqueNums {
            val := num - smaller
            if num > 0 && val > 0 {
                tempUniqueNums[val] = struct{}{}
            }
            if val > 0 && (val < newSmaller || newSmaller == -1) {
                newSmaller = val
            }
        }
        smaller = newSmaller
        uniqueNums = tempUniqueNums
    }
    
    return countOps
}

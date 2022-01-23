// https://leetcode.com/problems/longest-harmonious-subsequence/
func findLHS(nums []int) int {
    if len(nums) < 2 {
        return 0
    }
    countNum := make(map[int]int)
    for _, num := range nums {
        countNum[num]++
    }
    maxSeq := 0
    for num, count := range countNum {
        if countPlusOne, ok := countNum[num+1]; ok {
            if count + countPlusOne > maxSeq {
                maxSeq = count + countPlusOne
            }
        }
        
        if countLessOne, ok := countNum[num-1]; ok {
            if count + countLessOne > maxSeq {
                maxSeq = count + countLessOne
            }
        }
    }
    
    return maxSeq
}

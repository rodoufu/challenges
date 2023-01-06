//https://leetcode.com/problems/maximum-average-subarray-i/
func findMaxAverage(nums []int, k int) float64 {
    lenN := len(nums)
    mAvg := make([]int, lenN)
    mAvg[0] = nums[0]
    for i := 1; i < lenN; i++ {
        mAvg[i] = mAvg[i-1] + nums[i]
    }
    //fmt.Printf("mAvg:%v\n", mAvg)
    lm := mAvg[k-1]
    for i := lenN-1; i>=k; i-- {
        mAvg[i] -= mAvg[i-k]
        if lm < mAvg[i]{
            lm = mAvg[i]
        }
    }
    //fmt.Printf("mAvg:%v, lm:%v\n", mAvg, lm)
    return float64(lm)/float64(k)
}

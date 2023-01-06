// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
func canThreePartsEqualSum(arr []int) bool {
    sums :=[]int { 0 }
    for i,x := range arr {
        sums = append(sums, sums[i]+x)
    }
    la := len(arr)
    if sums[la] % 3 != 0 {
        return false 
    }
    tf := sums[la] / 3
    count := 0
    fmt.Printf("sums:%v\n", sums)
    for i,x := range sums {
        if i > 0 && x == tf {
            count++
            tf += sums[la]/3
        }
        if tf == sums[la] {
            //return true 
        }
    }
    
    return count >= 3

}

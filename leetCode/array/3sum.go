// https://leetcode.com/problems/3sum/
func threeSum(nums []int) [][]int {
    numCount := make(map[int]int)
    for _, x := range nums {
        numCount[x]++
    }
    lenNum := len(nums)
    found := map[int]map[int]map[int]struct{}{}
    //fmt.Printf("numCount: %v\n", numCount)
    for i := 0; i < lenNum; i++ {
        numCount[nums[i]]--
        for j := 0; j < lenNum; j++ {
            numCount[nums[j]]--
            if i == j {
                numCount[nums[j]]++
                continue
            }
            twoNum := nums[i] + nums[j]
            //fmt.Printf("numCount: %v, nI: %v, nJ: %v, tn: %v\n", numCount, nums[i], nums[j], twoNum)
            if countK, ok := numCount[-twoNum]; ok && countK > 0 {
                values := []int{nums[i], nums[j], -twoNum}
                sort.Ints(values)
                //fmt.Printf("values: %v\n", values)
                
                found0, ok := found[values[0]]
                if !ok {
                    found[values[0]] = make(map[int]map[int]struct{})
                    found0 = found[values[0]]
                }
                found1, ok := found0[values[1]]
                if !ok {
                    found0[values[1]] = make(map[int]struct{})
                    found1 = found0[values[1]]
                }
                
                found1[values[2]] = struct{}{}
            }
            numCount[nums[j]]++
        }
        numCount[nums[i]]++
    }
    //fmt.Printf("found: %v\n", found)
    var resp[][]int
    for num0, found0 := range found {
        for num1, found1 := range found0 {
            for num2, _ := range found1 {
                resp = append(resp, []int{num0, num1, num2})
            }
        }
    }
    return resp
}

// https://leetcode.com/problems/4sum/
func fourSum(nums []int, target int) [][]int {
    sort.Ints(nums)
    lenNums := len(nums)
    
    found := map[int]map[int]map[int]map[int]struct{}{}
    for i := 0; i < lenNums; i++ {
        for j := i + 1; j < lenNums; j++ {
            for k, l := j + 1, lenNums - 1; k < lenNums; {
                if l == k {
                    k++
                    l = lenNums - 1
                    continue
                }
                current := nums[i] + nums[j] + nums[k] + nums[l]
                if current == target {
                    //fmt.Printf("values(%v, %v, %v, %v): {%v, %v, %v, %v}\n", i, j, k, l, nums[i], nums[j], nums[k], nums[l])
                    //resp = append(resp, []int{nums[i], nums[j], nums[k], nums[l]})
                    foundI, ok := found[nums[i]]
                    if !ok {
                        found[nums[i]] = make(map[int]map[int]map[int]struct{})
                        foundI = found[nums[i]]
                    }
                    foundJ, ok := foundI[nums[j]]
                    if !ok {
                        foundI[nums[j]] = make(map[int]map[int]struct{})
                        foundJ = foundI[nums[j]]
                    }
                    foundK, ok := foundJ[nums[k]]
                    if !ok {
                        foundJ[nums[k]] = make(map[int]struct{})
                        foundK = foundJ[nums[k]]
                    }
                    foundK[nums[l]] = struct{}{}
                    l--
                } else if current > target {
                    l--
                } else {
                    k++
                }
            }
        }
    }
    
    var resp [][]int
    for numI, foundI := range found {
        for numJ, foundJ := range foundI {
            for numK, foundK := range foundJ {
                for numL, _ := range foundK {
                    resp = append(resp, []int{numI, numJ, numK, numL})
                }
            }
        }
    }
    return resp
}
